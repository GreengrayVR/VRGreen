#pragma once

#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <filesystem>
#include "ConsoleColor.h"

namespace VRCQuickMenu
{
	void VRDebugUpdate();
}


class FileUtils {
public:
	static bool fileExists(const char* fileName);

	static bool dirExists(const char* dirName_in);
};

class ConsoleUtils {
public:
	struct Line 
	{
		std::string text;
		std::string shadowText;
		std::string time;
		int counter = 0;

		void Update(int lineNumber);
		void UpdateShadow(int lineNumber);
	};

	inline static std::vector<Line> LogList = {};

	inline static int LogListIndex = -1;

	inline static int MaxDebugLines = 26;

	static bool HasConsole();

	static void CreateConsole();

	static void DestroyConsole();

	template<typename... TArgs>
	static void Log(TArgs&&... Args);

	static void VRLog(std::string text);

	static std::string GetVRTime() noexcept;

	static std::string GetTime() noexcept;

private:

	static void localTimeSafe(std::tm *pTMInfo, const std::time_t *pTime) noexcept;
};

template<typename... TArgs>
void ConsoleUtils::Log(TArgs&&... Args)
{
	if (!HasConsole())
		return;


	std::cout << "[" << GetTime() << "] ";


	using Expand__ = int[];
	(void)Expand__
	{
		0, (std::cout << Args, 0)...
	};

	std::cout << '\n' << white;
}

//inline std::vector<ConsoleUtils::Line> ConsoleUtils::LogList;