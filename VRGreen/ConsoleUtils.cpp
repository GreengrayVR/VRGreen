#include "ConsoleUtils.hpp"

#include "UnityEngine/Transform.hpp"
#include "QuickMenu.hpp"
#include "Text.hpp"
#include <algorithm>
#include <regex>

static std::regex nigger("(<color=#?\\w+)>");

bool ConsoleUtils::HasConsole()
{
	return GetConsoleWindow() != NULL;
}

void ConsoleUtils::CreateConsole()
{
	if (HasConsole())
		return;

	// Alloc console
	if (!AllocConsole())
	{
		MessageBox(NULL, L"Failed to create debug console.", NULL, MB_OK | MB_ICONEXCLAMATION);
		return;
	}

	SetConsoleOutputCP(65001);

	// Setup outputs
	freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
	freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	SetConsoleTitle(L"VRGreen");

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 25;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	std::cout << white << "Credits to: ";
	std::cout << green << "Green";
	std::cout << gray << "gray";
	std::cout << white << ", ";
	std::cout << green << "kerrytazi";
	std::cout << white << ", ";
	std::cout << green << "abbez ";
	std::cout << white << "and ";
	std::cout << green << "Sypherr";
	std::cout << white << ".\n";

	std::cout << white << " ______________________________________________\n";
	std::cout << white << "/";
	std::cout << "                                          ";
	std::cout << white << "    \\\n";
	std::cout << "|                                         ";
	std::cout << white << "     |\n";
	std::cout << white << "|";
	std::cout << magenta << "  __     ______   ";
	std::cout << green << " ____                     ";
	std::cout << white << "  |\n";
	std::cout << white << "|";
	std::cout << magenta << "  \\ \\   / /  _ \\";
	std::cout << green << "  / ___|_ __ ___  ___ _ ___";
	std::cout << white << "   |\n";
	std::cout << white << "|";
	std::cout << magenta << "   \\ \\ / /| |_) |";
	std::cout << green << "| |  _| '__/ _ \\/ _ \\ '_  \\";
	std::cout << white << "  |\n";
	std::cout << white << "|";
	std::cout << magenta << "    \\ V / |  _ <";
	std::cout << green << " | |_| | | |  __/  __/ | | |";
	std::cout << white << "  |\n";
	std::cout << white << "|";
	std::cout << magenta << "     \\_/  |_| \\_\\";
	std::cout << green << " \\____|_|  \\___|\\___|_| |_|";
	std::cout << white << "  |\n";
	std::cout << white << "|";
	std::cout << "                                          ";
	std::cout << white << "    |\n";
	std::cout << white << "|";
	std::cout << cyan << "            Unity";
	std::cout << cyan << " 2018.4.20f1             ";
	std::cout << white << "    |\n";
	std::cout << white << "\\______________________________________________/\n";
}

void ConsoleUtils::DestroyConsole()
{
	if (!HasConsole())
		return;

	// Remove outputs
	fclose(reinterpret_cast<FILE*>(stdout));
	fclose(reinterpret_cast<FILE*>(stdin));

	// Free console
	FreeConsole();
}

void ConsoleUtils::VRLog(std::string text)
{
	// NOTE: Assume LogList.size() == MaxDebugLines
	if (LogList[LogListIndex].text == text)
	{
		LogList[LogListIndex].counter++;
	}
	else
	{
		Line line;
		line.text = text;
		line.shadowText = regex_replace(text, nigger, "<color=black>");;
		line.counter = 1;
		line.time = GetVRTime();

		LogListIndex = (LogListIndex + 1) % MaxDebugLines;

		LogList[LogListIndex] = line;
	}


	VRCQuickMenu::VRDebugUpdate();
}

std::string ConsoleUtils::GetVRTime() noexcept
{
	using namespace std::chrono;

	std::int64_t TotalMs = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

	std::time_t CurrentTime = std::time_t(TotalMs / 1000);
	std::int32_t MSCount = static_cast<std::int32_t>(TotalMs % 1000);

	std::tm TMInfo;

	localTimeSafe(&TMInfo, &CurrentTime);

	char pBuffer[16];

	std::size_t StringSize = ::strftime(pBuffer, 32, "%H:%M:%S", &TMInfo);

	return std::string(pBuffer, StringSize);
}

std::string ConsoleUtils::GetTime() noexcept
{
	using namespace std::chrono;

	std::int64_t TotalMs = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

	std::time_t CurrentTime = std::time_t(TotalMs / 1000);
	std::int32_t MSCount = static_cast<std::int32_t>(TotalMs % 1000);

	std::tm TMInfo;

	localTimeSafe(&TMInfo, &CurrentTime);

	char pBuffer[32];

	std::size_t StringSize = ::strftime(pBuffer, 32, "%Y-%m-%d %H:%M:%S", &TMInfo);

	StringSize += std::snprintf(pBuffer + StringSize, 32 - StringSize, ".%03d", MSCount);

	return std::string(pBuffer, StringSize);
}

void ConsoleUtils::localTimeSafe(std::tm* pTMInfo, const std::time_t* pTime) noexcept
{
#ifdef _MSC_VER
	::localtime_s(pTMInfo, pTime);
#else // clang
	::localtime_r(pTime, pTMInfo);
#endif // _MSC_VER
}

bool FileUtils::fileExists(const char* fileName)
{
	std::ifstream file;
	file.open(fileName, std::ios::in | std::ios::binary);

	bool exists = file.good();

	if (exists && file.is_open())
		file.close();
	return exists;
}

bool FileUtils::dirExists(const char* dirName_in)
{
	DWORD ftyp = GetFileAttributesA(dirName_in);

	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;
	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;
	return false;
}

void ConsoleUtils::Line::Update(int lineNumber)
{
	std::string newText;

	if (counter > 0)
	{
		newText += "<color=#ffffff><size=40>[";
		newText += time;
		newText += "]</size> ";
		if (counter > 1)
		{
			newText += "<color=red>(";
			newText += std::to_string(counter);
			newText += ")</color> ";
		}
		newText += text;
		newText += "</color>";
	}


	UnityEngine::Transform* text = QuickMenu::QuickMenuInstance()->get_transform()->Find(IL2CPP::StringNew("ShortcutMenu/debugString" + std::to_string(lineNumber)));
	auto component = (UnityEngine::UI::Text*)text->GetComponent("UnityEngine.UI.Text");
	component->SetText(newText);
}

void ConsoleUtils::Line::UpdateShadow(int lineNumber)
{
	std::string newText;

	if (counter > 0)
	{
		newText += "<color=black><size=40>[";
		newText += time;
		newText += "]</size> ";
		if (counter > 1)
		{
			newText += "(";
			newText += std::to_string(counter);
			newText += ") ";
		}
		newText += shadowText;
		newText += "</color>";
	}


	UnityEngine::Transform* text = QuickMenu::QuickMenuInstance()->get_transform()->Find(IL2CPP::StringNew("ShortcutMenu/debugStringShadow" + std::to_string(lineNumber)));
	auto component = (UnityEngine::UI::Text*)text->GetComponent("UnityEngine.UI.Text");
	component->SetText(newText);
}
