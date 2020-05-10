#include "ConsoleUtils.h"



void ConsoleUtils::WriteLine(const char* text)
{
	HANDLE hStdout;

	TCHAR msgBuf[255];
	size_t cchStringSize;
	DWORD dwChars;

	// Make sure there is a console to receive output results. 

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdout == INVALID_HANDLE_VALUE)
		return;

	// Cast the parameter to the correct data type.
	// The pointer is known to be valid because 
	// it was checked for NULL before the thread was created.


	// Print the parameter values using thread-safe functions.

	StringCchPrintf(msgBuf, 255, TEXT("TEXT: %s\n"), text);
	StringCchLength(msgBuf, 255, &cchStringSize);
	WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);
}

ConsoleUtils::ConsoleUtils()
{
} 


ConsoleUtils::~ConsoleUtils()
{
}

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
	while (LogList.size() >= 26)
	{
		LogList.pop_back();
	}

	std::string newText = "<color=#ffffff><size=40>";
	newText += "[";
	newText += GetVRTime();
	newText += "]</size> ";
	newText += text;
	newText += "</color>";

	LogList.insert(LogList.begin(), newText);

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
