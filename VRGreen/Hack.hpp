#ifndef HACK_H
#define HACK_H



#include "Utils/http.h"

#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <vector>
#include <thread>
#include <string>
#include <cstdint>
#include <mutex>
#include <memory>
#include <thread>


#include "detours/detours.h"

#include "IL2CPP/IL2CPP.hpp"


struct UserInteractMenu;
struct VRCPlayer;
namespace VRC { struct Player; }
namespace VRC::Core { struct APIUser; struct ApiAvatar; }
namespace UnityEngine { struct GameObject; }
namespace VRC::SDKBase { struct VRC_EventHandler; }

class Hack
{
public:
	float emojiSpamDelay;
	float updateDelay;
	bool lobbyLag;

	inline static Hack& getInstance();
	void init();
	void mainLoop();
	void destroy();


private:

	struct mode;


	// variables
	std::vector<mode> settings;
	std::mutex DetourMutex;
	std::string GoToRoomID;
	HANDLE threadId;
	
	
	bool seeBlocked;
	bool gravityHack;
	bool emojiSpam;
	bool toggleRPC;
	bool disableTriggers;
	bool noGlobal;
	bool isTyping;
	bool menuInitialized;
	//


	void setupVariables();
	void generateHWID();
	void disableDetours();
	void setupSettings();

	static void SwitchAvatar(void* _this, VRC::Core::ApiAvatar* apiavatar, IL2CPP::String* fuzzy, float betterthen, void* tsumiki);
	static void OfflineMode(IL2CPP::String* target, void* responseContainer, void* requestParams, void* credentials);
	static void ReceiveVoteToKickInitiation(void* _this, IL2CPP::String* player2, VRC::Player* player);
	static void Wtf(void* _this, VRC::Player* player);
	static void CloneAvatar(UserInteractMenu* __instance);
	static bool IsBlockedEitherWay(void* _this, IL2CPP::String* str);
	static IL2CPP::String* GetFriendlyDetailedNameForSocialRank(VRC::Core::APIUser* apiuser);
	static void CustomPlates(VRCPlayer* __instance, void* aaa);
	static void EventDispatcherExecuteRPCPrefix(void* _this, void* VrcBroadcastType, int aaaa, void* VrcTargetType, UnityEngine::GameObject* gameObject, IL2CPP::String* str, void* byteArray);
	static bool IsKicked2(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3);
	static bool JoinWorld(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3);
	static bool IsKickedFromWorld(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3);
	static void NoKickTrue(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3);
	static void ForceLogoutRPC(void* _this, IL2CPP::String* player2, VRC::Player* player);
	static void FriendStateChangeRPC(void* _this, IL2CPP::String* player2, VRC::Player* player);
	static void ResetShowUserAvatarToDefaultRPC(void* _this, IL2CPP::String* player2, VRC::Player* player);
	static void ModMicGainChangeRPC(void* _this, IL2CPP::String* player2, int date, VRC::Player* player);
	static void BanPublicOnlyRPC(void* _this, IL2CPP::String* player2, int date, VRC::Player* player);
	static void BanRPC(void* _this, IL2CPP::String* player2, int date, VRC::Player* player);
	static void MuteChangeRPC(void* _this, IL2CPP::String* player2, bool state, VRC::Player* player);
	static void ModForceOffMicRPC(void* _this, IL2CPP::String* str, VRC::Player* player);
	static void ShowUserAvatarChangedRPC(void* _this, IL2CPP::String* player2, bool state, VRC::Player* player);
	static void SpawnEmojiRPC(void* _this, int emoji, VRC::Player* player);
	static void ShowSocialRankRPC(void* _this, bool state, VRC::Player* player);
	static void GotoRoomTargetUserRPC(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, VRC::Player* player);
	static void PlayEmoteRPC(void* _this, int emote, VRC::Player* player);
	static void GotoRoomRPC(void* _this, IL2CPP::String* worldId, IL2CPP::String* instaceId, VRC::Player* player);
	static void TakePhotoRPC(void* _this, VRC::Player* player);
	static void BlockStateChangeRPC(void* _this, IL2CPP::String* player2, bool blockState, VRC::Player* player);
	static void PlayerLeft(void* _this, VRC::Player* player);
	static void PlayerJoined(void* _this, VRC::Player* player);
	static void* ReceiveAudio(void* _this, long long arr, int length);
	static void OnTriggerEnter(void* _this, void* collider);
	static void KickUserRPC(void* _this, IL2CPP::String* player2, IL2CPP::String* str2, IL2CPP::String* str3, IL2CPP::String* str4, VRC::Player* player);
	static void WarnUserRPC(void* _this, IL2CPP::String* player2, IL2CPP::String* str2, VRC::Player* player);
	static void Update(void* _this);
	static void ConfigurePortal(void* _this, IL2CPP::String* world_id, IL2CPP::String* instance_id, int32_t playersInWorld, VRC::Player* player);
	static void InternalTriggerEvent(VRC::SDKBase::VRC_EventHandler* _this, void* vrc_event, int broadcastType, int instagatorId, float fastForward);
	static int get_RoundTripTimeDetour();
	static IL2CPP::String* get_DeviceId();
	void initDetours();
	mode& getSetting(std::string settingName);
	void toggleSetting(std::string settingName);
	static void promptRoomID();
	static void testReturnStrings(std::vector<ptrdiff_t>& vector);
	static std::string getEmoji(int i);
};

#endif