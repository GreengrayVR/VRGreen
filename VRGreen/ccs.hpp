#pragma once

#include <string>
#include <array>

class CCexprString
{
private:

	char* m_pStr;
	std::size_t m_Size;

public:

	template <typename T>
	CCexprString(const T& arr)
	{
		m_Size = arr.size();
		m_pStr = new char[m_Size];

		for (std::size_t i = 0; i != m_Size; ++i)
			m_pStr[i] = arr[i];
	}

	inline ~CCexprString()
	{
		delete[] m_pStr;
	}

	inline std::string get() const
	{
		std::string NewStr(m_Size, 0);

		for (std::size_t i = 0; i != m_Size; ++i)
			NewStr[i] = m_pStr[i] ^ 0x5a;

		return NewStr;
	}
};

#define ccs(_Str) \
    CCexprString([]() { \
        constexpr std::size_t Size = sizeof(_Str); \
        std::array<char, Size> NewStr; \
        for (std::size_t i = 0; i != Size; ++i) \
            NewStr[i] = (_Str)[i] ^ 0x5a; \
        return NewStr; \
    }())
