#pragma once

#include <cstdint>
#include <functional>
#include <cstddef>
#include <Windows.h>
#include <utility>

class CDetour // TODO: rename
{

private:

	CDetour(const CDetour&) = delete;
	CDetour& operator = (const CDetour&) = delete;
	CDetour(CDetour&&) = delete;
	CDetour& operator = (CDetour&&) = delete;

	std::uint8_t* m_pTour = nullptr;

	std::function<void()> m_Func;

	constexpr static std::size_t TOUR_OFFSET = 128;

	static void CreateTrampolineWithCurrentRIP(void* pMemory, const void* pFunc) noexcept
	{
		const std::uint64_t fp = reinterpret_cast<std::uint64_t>(pFunc);
		const uint8_t* f = reinterpret_cast<uint8_t const*>(&fp);

		const std::uint8_t t[]{

			// call <next>
			0xE8, 0x00, 0x00, 0x00, 0x00,
			// pop rax
			0x58,
			// mov rcx, rax
			0x48, 0x8B, 0xC8,

			// mov rax, pFunc
			0x48, 0xB8, f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7],
			// jmp rax
			0xFF, 0xE0,

			// int 3 ; Just for debuggin purposes
			0xCC,
		};

		std::copy(t, t + sizeof(t), static_cast<std::uint8_t*>(pMemory));
	}

	static void Proxy(uint64_t rip)
	{
		uint64_t base = rip & ~uint64_t(0xFFF);
		const CDetour* pThis = *reinterpret_cast<CDetour const* const*>(base);
		return pThis->m_Func();
	}

	void Init() noexcept
	{
		auto pMemory = ::VirtualAlloc(nullptr, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		m_pTour = reinterpret_cast<std::uint8_t*>(pMemory);
		*reinterpret_cast<CDetour**>(m_pTour) = this;
		auto pFunc = m_pTour + TOUR_OFFSET;

		CreateTrampolineWithCurrentRIP(pFunc, &Proxy);
	}

public:

	template <typename TLambda>
	CDetour(TLambda&& Func) :
		m_Func(std::move(Func))
	{
		Init();
	}

	~CDetour()
	{
		if (m_pTour)
		{
			::VirtualFree(m_pTour, 0, MEM_RELEASE);
			m_pTour = nullptr;
		}
	}

	//static void* operator new(std::size_t sz);

	using FuncType = void(*)();

	FuncType GetFuncPointer() const
	{
		return reinterpret_cast<FuncType>(m_pTour + TOUR_OFFSET);
	}
};

class CDetourManager
{

	std::vector<std::unique_ptr<CDetour>> m_Detours;

public:
	template <typename T>
	CDetour* Create(T&& Fn)
	{
		return m_Detours.emplace_back(std::make_unique<CDetour>(std::move(Fn))).get();
	}

	static CDetourManager& GetSingleton()
	{
		static CDetourManager Instance;
		return Instance;
	}
};

template <typename T>
inline CDetour* CreateDetour(T&& Fn)
{
	return CDetourManager::GetSingleton().Create(std::move(Fn));
}

//inline void* CDetour::operator new(std::size_t sz)
//{
//	CDetour* pDetour = static_cast<CDetour*>(::operator new(sz));
//	CDetourManager::GetSingleton().Add(pDetour);
//	return pDetour;
//}