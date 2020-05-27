#pragma once
#include "Discord.hpp"

#include <list>

namespace UnityEngine { struct GameObject; }


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
	inline static bool blockRPCs;
	inline static bool instanceLock;
	inline static bool antiWorldTriggers;
	inline static bool antiPortal;
	inline static bool printApiRequests;
	inline static bool serialize;
	inline static bool stickOnHead;
	inline static bool portalLag;
	inline static bool spamEmoji;
	inline static bool testing;
	inline static bool fly;
	inline static bool esp;
	inline static float flySpeed;
	inline static std::list<std::string> whiteList;
	inline static UnityEngine::GameObject* modManager = nullptr;
	inline static Discord* g_Discord;
};