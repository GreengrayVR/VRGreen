#pragma once

#include <mutex>
#include "List.hpp"
#include "RoomManagerBase.hpp"
#include "ButtonAPI.hpp"
#include "UnityAction.hpp"
#include "ApiWorld.hpp"
#include "ApiWorldInstance.hpp"
#include "ArrayList.hpp"


namespace VRC { struct Player; }
namespace VRC::Core { struct APIUser; }

struct Misc
{
    static UnityEngine::Color GetRainbow();

    static void DropPortal(const std::string& world, const std::string& id, const std::string& text);

    static void DropPortal(const std::string& world, const std::string& id);

    static void DropPortal(VRC::Player* player);

    static void DropPortalBlock(VRC::Player* player);

    static void SpawnEmoji(int index);

    static void PlayEmote(int index);

    static std::vector<std::string> split(std::string text, const std::string& delimiter);

    template <typename T>
    static bool contains(std::list<T>& listOfElements, const T& element)
    {
        return std::find(listOfElements.begin(), listOfElements.end(), element) == listOfElements.end();
    }

	static const wchar_t* wchar_t_ptr(const char* str);

    static const wchar_t* wchar_t_ptr(std::string str);

    static void SerializeAll();

    static void ToLower(std::string& text);

    static void ToUpper(std::string& text);

    static bool Contains(std::string text, std::string contains);

    static void FindEverything(std::string objectsToDelete);

    static void DestroyEverything();

    static void DestroyPortals();

    static std::string GetWorldTag(std::string worldId);

    static std::string RandomString(int len);

    static bool isMe(VRC::Player* player);

    static void WorldInfoPrint();

	static std::string GetSocialRankForPlayerList(VRC::Player* player);

	static std::string GetSocialRankForPlayerListShadow(VRC::Player* player);

    static std::string GetUserRank(VRC::Core::APIUser* apiuser);

    static std::string GetUserVipPlateRank(VRC::Core::APIUser* apiuser);

    static std::string GetUserRankName(VRC::Core::APIUser* apiuser);

    static void CloseGame();
};

