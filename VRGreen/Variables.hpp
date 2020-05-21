#pragma once
#include "Discord.hpp"

#include <list>

struct Variables // TODO: move to Hack.hpp
{
#pragma region QMButtons
	inline static bool uiElementsPage1;
#pragma endregion

	inline static void* player;
	inline static bool speedHack;
	inline static bool offlineMode;
	inline static bool forceMute;
	inline static bool autoDestroy;
	inline static bool worldTriggers;
	inline static bool antiPortal;
	inline static bool printApiRequests;
	inline static bool stickOnHead;
	inline static bool portalLag;
	inline static bool spamEmoji;
	inline static bool testing;
	inline static bool fly;
	inline static bool esp;
	inline static float flySpeed;
	inline static std::list<std::string> whiteList;
	inline static Discord* g_Discord;
};