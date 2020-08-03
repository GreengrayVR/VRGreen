#pragma once
#include "Discord.hpp"


#include <list>
#include <vector>
#include <set>

namespace UnityEngine { struct GameObject; }


struct Variables // TODO: move to Hack.hpp
{
#pragma region QMButtons
	inline static bool uiElementsPage1;
	inline static bool uiElementsPage2;
	inline static bool userInteractMenu1;
#pragma endregion

	inline static void* player;
	inline static void* takeMyHeart;
	inline static bool speedHack;
	inline static bool offlineMode;
	inline static bool forceMute;
	inline static bool autoDestroy;
	inline static bool worldTriggers;
	inline static bool friendRequestSent;
	inline static bool fakePing;
	inline static bool customPlates;
	inline static bool blockRPCs;
	inline static bool rpcBlockNonFriends;
	inline static bool instanceLock;
	inline static bool antiWorldTriggers;
	inline static bool portalKOS;
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
	inline static std::set<std::string> logoutKOSList;
	inline static std::set<std::string> portalKOSList;
	inline static std::set<std::string> photonBots;
	inline static std::set<std::string> rpcBlocked;
	inline static UnityEngine::GameObject* modManager = nullptr;
	inline static Discord* g_Discord;
};