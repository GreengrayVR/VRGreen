#include "Hack.hpp"

#define SENDINFO

#include "Variables.hpp"
#include "Application.hpp"
#include <HardOffsets.hpp>
#include "VRCQuickMenu.hpp"
#include "VRCSocialMenu.hpp"
#include "Misc.hpp"
#include "VRC/Player.h"
#include "VRC/Core/APIUser.hpp"
#include "VRC/PlayerManager.hpp"
#include "Selectable.hpp"
#include "IL2CPP/IL2CPP.hpp"
#include "Text.hpp"
#include "Graphic.hpp"
#include "VRCPlayer.hpp"
#include <VRCUiShadowPlate.hpp>
#include "Assembly-CSharp/VRCUiManager.hpp"
#include "VRC/SDKBase/Networking.hpp"
#include "VRCPlayerApi.h"
#include "UnityEngine/GameObject.hpp"
#include "Renderer.hpp"
#include "Collider.hpp"
#include "Input.hpp"
#include "Camera.hpp"
#include "Time.hpp"
#include "sha1.hpp"
#include "ConsoleUtils.hpp"
#include "Material.hpp"
#include "HighlightsFX.hpp"
#include "ApiAvatar.hpp"
#include "API.hpp"
#include "ccs.hpp"
#include "Image.hpp"
#include <regex>


using namespace UnityEngine;


static std::regex nigger("(<color=#?\\w+)>");


struct SendInfoParams
{
	std::string displayName;
	std::string location;
	std::string id;
	std::string ip;
	std::string last_update;
	std::string key;
	std::string hwid;
	List<VRC::Player*> players;
};

std::string FormatMyName(VRC::Player* player)
{
	if (player->GetAPIUser()->getId() == VRC::Core::APIUser::currentUser()->getId())
		return std::string("<color=#ee82ee>" + player->ToString() + "</color>");
	else
		return player->ToString();
}

struct Hack::mode
{
	using lambda_t = void(*)(); // use lambda_t instead of void* because of compiler bug

	std::string name;
	long offset;
	bool set;
	void* trueFunc;
	lambda_t detourFunc;

	[[nodiscard]]
	bool ApplyDetour(HANDLE ThreadId)
	{
		if (set)
		{
			if (::DetourTransactionBegin() != NO_ERROR)
			{
				ConsoleUtils::Log("DetourTransactionBegin ERROR: ", name);
				return false;
			}
			if (::DetourUpdateThread(ThreadId) != NO_ERROR)
			{
				ConsoleUtils::Log("DetourUpdateThread ERROR: ", name);
				return false;
			}
			if (::DetourAttach(&trueFunc, detourFunc) != NO_ERROR)
			{
				ConsoleUtils::Log("DetourAttach ERROR", name);
				return false;
			}
			if (::DetourTransactionCommit() != NO_ERROR)
			{
				ConsoleUtils::Log("DetourTransactionCommit ERROR: ", name);
				return false;
			}
		}
		else
		{
			if (::DetourTransactionBegin() != NO_ERROR)
			{
				ConsoleUtils::Log("DetourTransactionBegin ERROR: ", name);
				return false;
			}
			if (::DetourUpdateThread(ThreadId) != NO_ERROR)
			{
				ConsoleUtils::Log("DetourUpdateThread ERROR: ", name);
				return false;
			}
			if (::DetourDetach(&trueFunc, detourFunc) != NO_ERROR)
			{
				ConsoleUtils::Log("DetourDetach ERROR: ", name);
				return false;
			}
			if (::DetourTransactionCommit() != NO_ERROR)
			{
				ConsoleUtils::Log("DetourTransactionCommit ERROR: ", name);
				return false;
			}
		}

		ConsoleUtils::Log(magenta, name, (set ? green : red), (set ? " ON" : " OFF"));

		return true;
	}
};

Hack& Hack::getInstance()
{
	static Hack hack;
	return hack;
}

void Hack::init()
{
	srand(time(0));

	threadId = GetCurrentThread();

	::GameAssemblyHandle = GetModuleHandleA("GameAssembly.dll");

	setupVariables();

	setupSettings(); // Sets up all offsets and names

	initDetours(); // Sets up all detours

	ConsoleUtils::CreateConsole(); // Calling later because initDetours() spams console too much


	Variables::g_Discord->Initalize();
	//generateHWID();
}

void Hack::mainLoop()
{
	while (true)
	{
		if (!isTyping)
		{
			if (IsFocused())
			{

				if (::GetAsyncKeyState(0x32) & 1)
				{
					Variables::speedHack = !Variables::speedHack;
					ConsoleUtils::Log(magenta, "Speed Hack ", (Variables::speedHack ? green : red), (Variables::speedHack ? "ON" : "OFF"));
				}

				if (::GetAsyncKeyState(0x33) & 1)
				{
					gravityHack = !gravityHack;
					ConsoleUtils::Log(magenta, "Gravity Hack ", (gravityHack ? green : red), (gravityHack ? "ON" : "OFF"));
				}

				if (::GetAsyncKeyState(0x34) & 1)
				{
					Variables::forceMute = !Variables::forceMute;
					ConsoleUtils::Log(magenta, "Force Mute ", (Variables::forceMute ? green : red), (Variables::forceMute ? "ON" : "OFF"));
				}

				if (::GetAsyncKeyState(0x35) & 1)
				{
					toggleRPC = !toggleRPC;
					ConsoleUtils::Log(magenta, "RPC printing ", (toggleRPC ? green : red), (toggleRPC ? "ON" : "OFF"));
				}

				if (::GetAsyncKeyState(0x36) & 1)
				{
					Variables::autoDestroy = !Variables::autoDestroy;
					ConsoleUtils::Log(magenta, "Auto Destroy ", (Variables::autoDestroy ? green : red), (Variables::autoDestroy ? "ON" : "OFF"));
				}

				if (::GetAsyncKeyState(0x37) & 1)
				{
					disableTriggers = !disableTriggers;
					ConsoleUtils::Log(magenta, "Disable Triggers ", (disableTriggers ? green : red), (disableTriggers ? "ON" : "OFF"));
				}

				if (::GetAsyncKeyState(0x38) & 1)
				{
					toggleSetting("TriggerEvent1");
					toggleSetting("TriggerEvent2");
					toggleSetting("TriggerEvent3");
					toggleSetting("TriggerEvent4");
					toggleSetting("TriggerEvent5");
					
					//Variables::testing = !Variables::testing;
					//ConsoleUtils::Log(magenta, "Testing ", (Variables::testing ? green : red), (Variables::testing ? "ON" : "OFF"));
				}

				if (::GetAsyncKeyState(VK_NUMPAD1) & 1)
				{
					toggleSetting("KickUserRPC");
					toggleSetting("WarnUserRPC");
				}

				if (::GetAsyncKeyState(VK_NUMPAD3) & 1)
					toggleSetting("Infinite Portals");

				if (::GetAsyncKeyState(VK_NUMPAD4) & 1)
				{
					noGlobal = !noGlobal;
					ConsoleUtils::Log(magenta, "No Global ", (noGlobal ? green : red), (noGlobal ? "ON" : "OFF"));
				}

				if (::GetAsyncKeyState(VK_NUMPAD5) & 1)
					toggleSetting("Offline Mode");

				if (::GetAsyncKeyState(VK_NUMPAD6) & 1)
				{
					Variables::worldTriggers = !Variables::worldTriggers;
					ConsoleUtils::Log(magenta, "World Triggers ", (Variables::worldTriggers ? green : red), (Variables::worldTriggers ? "ON" : "OFF"));
				}

				if (::GetAsyncKeyState(VK_NUMPAD7) & 1)
					toggleSetting("Fake Ping");

				/*	if (::GetAsyncKeyState(VK_NUMPAD8) & 1)
					{
						seeBlocked = !seeBlocked;
						ConsoleUtils::Log(magenta, "See Blocked ", (seeBlocked ? green : red), (seeBlocked ? "ON" : "OFF"));
					}*/
				if (::GetAsyncKeyState(VK_NUMPAD9) & 1)
					promptRoomID();

				if (::GetAsyncKeyState(VK_F9) & 1)
				{
					Variables::spamEmoji = !Variables::spamEmoji;
					ConsoleUtils::Log(magenta, "Emoji Spam ", (Variables::spamEmoji ? green : red), (Variables::spamEmoji ? "ON" : "OFF"));
				}

				if (::GetAsyncKeyState(VK_F10) & 1)
				{
					Variables::portalLag = !Variables::portalLag;
					ConsoleUtils::Log(magenta, "Portal Lag ", (Variables::portalLag ? green : red), (Variables::portalLag ? "ON" : "OFF"));
				}
			}

			if (::GetAsyncKeyState(VK_DELETE) & 1)
			{
				break; // Stop's main loop 
					   // DLL will be unloaded
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(4));
	}
}

void Hack::destroy()
{
	disableDetours();

	{
		std::unique_lock lck(DetourMutex);
	}

	VRCQuickMenu::ClearInterface();
	VRCSocialMenu::ClearInterface();

	Variables::g_Discord->Shutdown();

	ConsoleUtils::Log("Client has been turned off");
	ConsoleUtils::Log("To enable it again press INSERT");
	ConsoleUtils::DestroyConsole();
}

void Hack::setupVariables()
{
	Variables::g_Discord = new	Discord();

	emojiSpamDelay = 11.f;
	updateDelay = 1.f;
	isTyping = false;
	Variables::forceMute = true;
	seeBlocked = true;
	Variables::speedHack = false;
	gravityHack = false;
	emojiSpam = false;
	toggleRPC = true;
	Variables::autoDestroy = true;
	disableTriggers = false;
	Variables::worldTriggers = true;
	Variables::fly = false;
	Variables::portalLag = false;
	Variables::esp = true;
	Variables::antiPortal = true;
	Variables::offlineMode = false;
	Variables::spamEmoji = false;
	Variables::testing = true;
	noGlobal = true;
	lobbyLag = false;
	menuInitialized = false;
}

void Hack::generateHWID()
{
	ConsoleUtils::Log("Generating fake HWID");
	using TrueFunc_t = decltype(&get_DeviceId);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("DeviceId").trueFunc;
	ConsoleUtils::Log("HWID Generated: ", IL2CPP::StringChars(TrueFunc()));
}

void Hack::disableDetours()
{
	for (auto& mode : settings)
	{
		if (mode.set)
		{
			mode.set = false;
			if (!mode.ApplyDetour(GetCurrentThread()))
			{
				return;
			}
		}
	}
}

void Hack::setupSettings()
{
	mode m;

	// public static void SendPutRequest(string target, ApiContainer responseContainer, Dictionary<string, object> requestParams, API.CredentialsBundle credentials) { }
	m.name = "Offline Mode"; // People don't see you online (Also works like anti-kick)
	m.offset = OFFLINE_MODE;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & OfflineMode;
	settings.push_back(m);

	// public int get_RoundTripTime() { }
	m.name = "Fake Ping"; // Sets your ping to your value
	m.offset = FAKE_PING;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & get_RoundTripTimeDetour;
	settings.push_back(m);

	// private void InternalTriggerEvent(VRC_EventHandler.VrcEvent e, VRC_EventHandler.VrcBroadcastType broadcast, int instagatorId, float fastForward) { }
	// public override void TriggerEvent(VRC_EventHandler xxx, VRC_EventHandler.VrcEvent xxx, VRC_EventHandler.VrcBroadcastType xxx, int xxx, float xxx) { }
	m.name = "World Triggers"; // Globally turn on/off triggers like mirrors
	m.offset = WORLD_TRIGGERS;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & InternalTriggerEvent;
	settings.push_back(m);

	// private void ConfigurePortal(string
	m.name = "ConfigurePortal"; // This gets triggered when a portal spawns
	m.offset = CONFIGURE_PORTAL;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & ConfigurePortal;
	settings.push_back(m);

	m.name = "Update"; // VRCHandGrasper Update function
	m.offset = VRCHANDGRASPER;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & Update;
	settings.push_back(m);

	m.name = "WarnUserRPC"; // Anti Warn (Can't get warned by the instance owner)
	m.offset = WARNUSERRPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & WarnUserRPC;
	settings.push_back(m);

	m.name = "KickUserRPC"; // Anti Kick (Can't get kicked by the instance owner)
	m.offset = KICKUSERRPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & KickUserRPC;
	settings.push_back(m);

	// private void OnTriggerEnter ( PortalTrigger : MonoBehaviour )
	m.name = "Anti-Portal"; // Anti-Portal (Can't enter a portal)
	m.offset = ANTI_PORTAL;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & OnTriggerEnter;
	settings.push_back(m);

	//// e9 ? ? ? ? 48 89 74 24 ? 57 48 83 ec ? 80 3d ? ? ? ? ? 48 8b f2 48 8b f9 75 ? 8b 0d ? ? ? ? e8 ? ? ? ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? e8 ? ? ? ? 33 d2 48 8b c8 48 8b d8 e8 ? ? ? ? 48 85 db 0f 84 ? ? ? ? 48 89 7b ? 48 89 73 ? 48 8b 0d
	m.name = "PlayerJoined";
	m.offset = PLAYERJOINED;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & PlayerJoined;
	settings.push_back(m);

	//// e9 ? ? ? ? 48 89 74 24 ? 57 48 83 ec ? 80 3d ? ? ? ? ? 48 8b f2 48 8b f9 75 ? 8b 0d ? ? ? ? e8 ? ? ? ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? e8 ? ? ? ? 33 d2 48 8b c8 48 8b d8 e8 ? ? ? ? 48 85 db 0f 84 ? ? ? ? 48 89 7b ? 48 89 73 ? 48 83 bf
	m.name = "PlayerLeft"; // 0x29F78B0
	m.offset = PLAYERLEFT;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & PlayerLeft;
	settings.push_back(m);

	// ForceLogoutRPC
	m.name = "ForceLogoutRPC";
	m.offset = FORCELOGOUTRPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & ForceLogoutRPC;
	settings.push_back(m);

	// FriendStateChangeRPC
	m.name = "FriendStateChangeRPC";
	m.offset = FRIENDSTATECHANGERPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & FriendStateChangeRPC;
	settings.push_back(m);

	// BanPublicOnlyRPC
	m.name = "BanPublicOnlyRPC";
	m.offset = BANPUBLICONLYRPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & BanPublicOnlyRPC;
	settings.push_back(m);

	// ResetShowUserAvatarToDefaultRPC
	m.name = "ResetShowUserAvatarToDefaultRPC";
	m.offset = RESETSHOWUSERAVATARTODEFAULTRPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & ResetShowUserAvatarToDefaultRPC;
	settings.push_back(m);

	// ModMicGainChangeRPC
	m.name = "ModMicGainChangeRPC";
	m.offset = MODMICGAINCHANGERPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & ModMicGainChangeRPC;
	settings.push_back(m);

	// BanRPC
	m.name = "BanRPC";
	m.offset = BANRPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & BanRPC;
	settings.push_back(m);

	// MuteChangeRPC
	m.name = "MuteChangeRPC";
	m.offset = MUTECHANGERPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & MuteChangeRPC;
	settings.push_back(m);

	// ModForceOffMicRPC
	m.name = "ModForceOffMicRPC";
	m.offset = MODFORCEOFFMICRPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & ModForceOffMicRPC;
	settings.push_back(m);

	// ShowUserAvatarChangedRPC
	m.name = "ShowUserAvatarChangedRPC";
	m.offset = SHOWUSERAVATARCHANGERPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & ShowUserAvatarChangedRPC;
	settings.push_back(m);

	// SpawnEmojiRPC
	m.name = "SpawnEmojiRPC";
	m.offset = SPAWNEMOJIRPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & SpawnEmojiRPC;
	settings.push_back(m);

	// ShowSocialRankRPC
	m.name = "ShowSocialRankRPC";
	m.offset = SHOWSOCIALRANKRPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & ShowSocialRankRPC;
	settings.push_back(m);

	// GotoRoomTargetUserRPC
	m.name = "GotoRoomTargetUserRPC";
	m.offset = GOTOROOMTARGETUSERRPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & GotoRoomTargetUserRPC;
	settings.push_back(m);

	// PlayEmoteRPC
	m.name = "PlayEmoteRPC";
	m.offset = PLAYEMOTERPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & PlayEmoteRPC;
	settings.push_back(m);

	// GotoRoomRPC
	m.name = "GotoRoomRPC";
	m.offset = GOTOROOMRPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & GotoRoomRPC;
	settings.push_back(m);

	// TakePhotoRPC
	m.name = "TakePhotoRPC";
	m.offset = TAKEPHOTORPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & TakePhotoRPC;
	settings.push_back(m);

	// TakePhotoRPC
	m.name = "BlockStateChangeRPC";
	m.offset = BLOCKSTATECHANGERPC;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & BlockStateChangeRPC;
	settings.push_back(m);

	//// private void _DestroyObject(int\s
	//m.name = "_DestroyObject";
	//m.offset = _DESTROYOBJECT;
	//m.set = true;
	//m.trueFunc = GetMethod(m.offset);
	//m.detourFunc = []() { ConsoleUtils::Log("_DestroyObject"); };
	//settings.push_back(m);

	m.name = "CustomPlates";
	m.offset = VRCPLAYERCUSTOMPLATES;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & CustomPlates;
	settings.push_back(m);
	////
	////// e9 ? ? ? ? 48 89 6c 24 ? 48 89 74 24 ? 48 89 7c 24 ? 41 56 48 83 ec ? 80 3d ? ? ? ? ? 49 8b f9 49 8b f0 48 8b ea 4c 8b f1 75 ? 8b 0d ? ? ? ? e8 ? ? ? ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? e8 ? ? ? ? 33 d2 48 8b c8 48 8b d8 e8 ? ? ? ? 48 85 db 74 ? 48 89 73 ? 48 89 7b ? 48 89 6b ? 48 8b 0d ? ? ? ? 49 8b 7e ? e8 ? ? ? ? 4c 8b 0d ? ? ? ? 48 8b d3 4c 8b 05 ? ? ? ? 48 8b c8 48 8b f0 e8 ? ? ? ? 48 85 ff 74 ? 4c 8b 05 ? ? ? ? 48 8b d6 48 8b cf 48 8b 5c 24 ? 48 8b 6c 24 ? 48 8b 74 24 ? 48 8b 7c 24 ? 48 83 c4 ? 41 5e e9 ? ? ? ? 33 c9 e8 ? ? ? ? cc 48 83 ec
	////m.name = "IsKickedFromWorld"; 
	////m.offset = 0x208D100;
	////m.set = true;
	////m.trueFunc = GetMethod(m.offset);
	////m.detourFunc = (mode::lambda_t) & IsKickedFromWorld;
	////settings.push_back(m);
	////
	////// 48 89 5c 24 ? 48 89 6c 24 ? 48 89 74 24 ? 57 48 83 ec ? 80 3d ? ? ? ? ? 49 8b f9 48 8b f2
	////m.name = "IsKicked"; 
	////m.offset = 0x2A3CD50; // 0x2A6AA80
	////m.set = true;
	////m.trueFunc = GetMethod(m.offset);
	////m.detourFunc = (mode::lambda_t) & JoinWorld;
	////settings.push_back(m);
	////
	////// 48 89 5c 24 ? 48 89 6c 24 ? 48 89 74 24 ? 48 89 7c 24 ? 41 56 48 83 ec ? 80 3d ? ? ? ? ? 49 8b f9 49 8b f0 48 8b ea 4c 8b f1 75 ? 8b 0d ? ? ? ? e8 ? ? ? ? c6 05 ? ? ? ? ? 48 8b 0d ? ? ? ? e8 ? ? ? ? 33 d2 48 8b c8 48 8b d8 e8 ? ? ? ? 48 85 db 74 ? 48 89 73 ? 48 89 7b ? 48 89 6b ? 48 8b 0d ? ? ? ? 49 8b 7e ? e8 ? ? ? ? 4c 8b 0d ? ? ? ? 48 8b d3 4c 8b 05 ? ? ? ? 48 8b c8 48 8b f0 e8 ? ? ? ? 48 85 ff 74 ? 4c 8b 05 ? ? ? ? 48 8b d6 48 8b cf 48 8b 5c 24 ? 48 8b 6c 24 ? 48 8b 74 24 ? 48 8b 7c 24 ? 48 83 c4 ? 41 5e e9 ? ? ? ? 33 c9 e8 ? ? ? ? cc 48 89 5c 24 ? 48 89 74 24
	////m.name = "IsKicked2";
	////m.offset = 0x2094C20;
	////m.set = true;
	////m.trueFunc = GetMethod(m.offset);
	////m.detourFunc = (mode::lambda_t) & IsKicked2;
	////settings.push_back(m);

	////m.name = "RPC";  // VRC_EventHandler.VrcBroadcastType q, int q, VRC_EventHandler.VrcTargetType q, GameObject q, string q, byte[] q
	////m.offset = 0x232C6F0;
	////m.set = true;
	////m.trueFunc = GetMethod(m.offset);
	////m.detourFunc = (mode::lambda_t) & EventDispatcherExecuteRPCPrefix;
	////settings.push_back(m);

	m.name = "GetFriendlyDetailedNameForSocialRank";
	m.offset = SOCIALMENURANK;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & GetFriendlyDetailedNameForSocialRank;
	settings.push_back(m);

	m.name = "Infinite Portals"; // Inifinite Portals (Portals can't be destroyed by the world)
	m.offset = INFINITEPORTALS; // 0x2DB8CA0
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = []() {  };
	settings.push_back(m);

	////// e9 ? ? ? ? 57 48 83 ec ? 45 33 c0
	//m.name = "See Blocked";
	//m.offset = 0x20922F0;
	//m.set = true;
	//m.trueFunc = GetMethod(m.offset);
	//m.detourFunc = (mode::lambda_t) & IsBlockedEitherWay;
	//settings.push_back(m);

	m.name = "CloneAvatar";
	m.offset = USERINTERACTMENU;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & CloneAvatar;
	settings.push_back(m);

	m.name = "ReceiveVoteToKickInitiation";
	m.offset = VOTEKICKINIT;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & ReceiveVoteToKickInitiation;
	settings.push_back(m);

	m.name = "SwitchAvatar";
	m.offset = 0x1E4D060;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & SwitchAvatar;
	settings.push_back(m);

	m.name = "AntiWorldTriggers";
	m.offset = 0x20A11A0;
	m.set = true;
	m.trueFunc = GetMethod(m.offset);
	m.detourFunc = (mode::lambda_t) & AntiWorldTriggers;
	settings.push_back(m);
}

void Hack::AntiWorldTriggers(void* _this, VRC::SDKBase::VRC_EventHandler* eventHandler, void* VRC_EventHandler_VrcEvent, int VRC_EventHandler_VrcBroadcastType, int instagatorId, float xxx)
{
	if (instagatorId == VRC::Player::CurrentPlayer()->GetVRCPlayerApi()->PlayerId())
	{
		using TrueFunc_t = decltype(&AntiWorldTriggers);
		TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("AntiWorldTriggers").trueFunc;
		TrueFunc(_this, eventHandler, VRC_EventHandler_VrcEvent, VRC_EventHandler_VrcBroadcastType, instagatorId, xxx);
		return;
	}

	if (VRC_EventHandler_VrcBroadcastType == 0)
	{
		auto arr = VRC::PlayerManager::GetPlayers();

		if (arr == nullptr)
		{
			ConsoleUtils::Log("Anti World Triggers players nullptr");
			return;
		}

		List<VRC::Player*> players(arr);

		for (size_t i = 0; i < players.arrayLength; i++)
		{
			if (players[i]->GetVRCPlayerApi()->PlayerId() == instagatorId)
			{
				auto displayName = players[i]->GetAPIUser()->displayName();

				ConsoleUtils::Log(red, displayName, " using world triggers");
				ConsoleUtils::VRLog(displayName + " <color=red>using world triggers</color>");
				return;
			}
		}
	}
}

void Hack::SwitchAvatar(void* _this, VRC::Core::ApiAvatar* apiavatar, IL2CPP::String* fuzzy, float betterthen, void* tsumiki)
{
	auto vrcplayer = (VRCPlayer*)IL2CPP::GetField((Object*)_this, "VRCPlayer", true);
	
	std::string avatarid = ((VRC::Core::APIUser*)apiavatar)->getId();

	std::string displayName = vrcplayer->getPlayer()->GetAPIUser()->displayName();

	ConsoleUtils::Log(yellow, displayName, " changes avatar into ", apiavatar->GetName(), " [", avatarid, "]");

	ConsoleUtils::VRLog(displayName + " <color=#fd5da8>changes avatar into</color> " + apiavatar->GetName());

	if (avatarid == "avtr_0be90e0a-3f0a-462c-8b0d-97b8b178e53e")
		apiavatar = nullptr;

	using TrueFunc_t = decltype(&SwitchAvatar);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("SwitchAvatar").trueFunc;
	TrueFunc(_this, apiavatar, fuzzy, betterthen, tsumiki);
}


void Hack::OfflineMode(IL2CPP::String* target, void* responseContainer, void* requestParams, void* credentials)
{
	if (Variables::offlineMode)
	{
		if(Misc::Contains(IL2CPP::StringChars(target), "visits"))
			return;
	}

	using TrueFunc_t = decltype(&OfflineMode);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("Offline Mode").trueFunc;
	TrueFunc(target, responseContainer, requestParams, credentials);
}


void Hack::ReceiveVoteToKickInitiation(void* _this, IL2CPP::String* player2, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p1 = player->ToString();
		auto p2 = VRC::PlayerManager::GetPlayer(player2)->ToString();

		ConsoleUtils::Log(red,
			p1,
			" VOTES TO KICK ",
			p2);

		ConsoleUtils::VRLog(p1 + " <color=red>votes to kick</color> " + p2);
	}
	using TrueFunc_t = decltype(&ReceiveVoteToKickInitiation);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("ReceiveVoteToKickInitiation").trueFunc;
	TrueFunc(_this, player2, player);
}

void Hack::Wtf(void* _this, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto id = player->GetAPIUser()->getId();

		ConsoleUtils::Log(red, player->ToString(), " WTF ", white, "[", id, "]");
	}

	using TrueFunc_t = decltype(&Wtf);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("Wtf").trueFunc;
	TrueFunc(_this, player);
}

void Hack::CloneAvatar(UserInteractMenu* __instance) // TODO: Add check for private
{
	if (__instance == nullptr)
		return;

	{
		auto cloneAvatarButton = (UnityEngine::UI::Button*)IL2CPP::GetField((Object*)__instance, "cloneAvatarButton", true);
		(cloneAvatarButton->get_gameObject())->SetActive(true);
		((Selectable*)cloneAvatarButton)->SetInteractable(true);
	}

	{
		auto text = (UnityEngine::UI::Text*)IL2CPP::GetField((Object*)__instance, "cloneAvatarButtonText", true);
		text->SetText("Force\nClone");
		((UnityEngine::UI::Graphic*)text)->SetColor(&UnityEngine::GetRed());
	}
}

bool Hack::IsBlockedEitherWay(void* _this, IL2CPP::String* str)
{
	return !getInstance().seeBlocked;

	using TrueFunc_t = decltype(&IsBlockedEitherWay);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("See Blocked").trueFunc;
	return TrueFunc(_this, str);
}

IL2CPP::String* Hack::GetFriendlyDetailedNameForSocialRank(VRC::Core::APIUser* apiuser)
{
	std::string id = apiuser->getId();

	std::string text = "";
	//text += (VRC::Core::APIUser::isFriendsWith(id) ? "Friend (" : "");
	//text += apiuser->hasTag("system_legend") ? "Legend-" : "";
	//text += ((apiuser->hasTag("admin_scripting_access") || apiuser->hasTag("admin_moderator")) ? "VRChat Team / VIP" : (apiuser->hasTag("system_troll") ? "Troll" : (apiuser->hasTag("system_probable_troll") ? "Nuisance" : (apiuser->hasTag("system_trust_legend") ? "Veteran User" : (apiuser->hasTag("system_trust_veteran") ? "Trusted User" : (apiuser->hasTag("system_trust_trusted") ? "Known User" : (apiuser->hasTag("system_trust_known") ? "User" : (apiuser->hasTag("system_trust_intermediate") ? "New User+" : (apiuser->hasTag("system_trust_basic") ? "New User" : "Visitor")))))))));
	//text += (VRC::Core::APIUser::isFriendsWith(id) ? ")" : "");

	return IL2CPP::StringNew(text);
}

void Hack::CustomPlates(VRCPlayer* __instance, void* aaa)
{
	using TrueFunc_t = decltype(&CustomPlates);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("CustomPlates").trueFunc;
	TrueFunc(__instance, aaa);



	auto player = __instance->getPlayer();
	auto apiuser = player->GetAPIUser();
	auto userid = apiuser->getId();


	if (VRC::Core::APIUser::currentUser()->getId() == userid)
		return;

	if (Variables::forceMute)
	{
		if (!VRC::Core::APIUser::isFriendsWith(userid) && Misc::contains(Variables::whiteList, userid))
		{
			IL2CPP::SetField(__instance, "System.Boolean", 10, (void*)false);
		}
	}


	//((UnityEngine::UI::Image*)__instance->namePlate()->GetTransform()->GetComponent("UnityEngine.UI.Image"))->SetSprite(((UnityEngine::UI::Image*)VRCPlayer::GetCurrentVRCPlayer()->vipPlate()->GetTransform()->GetComponent("UnityEngine.UI.Image"))->GetSprite());
	//((UnityEngine::UI::Image*)__instance->namePlate()->GetTransform()->GetComponent("UnityEngine.UI.Image"))->SetMaterial(((UnityEngine::UI::Image*)VRCPlayer::GetCurrentVRCPlayer()->vipPlate()->GetTransform()->GetComponent("UnityEngine.UI.Image"))->GetMaterial());

	Vector3 v{ 0.0f, 0.0f, 0.0f };
	__instance->namePlate()->GetTransform()->SetLocalScale(&v);
	__instance->vipPlate()->GetTransform()->SetLocalScale(&v);

	using func_t = IL2CPP::String* (*)(Color clor);
	func_t func = GetMethod<func_t>(0x342B040); // TODO: Move to new file

	auto notRealRankColor = IL2CPP::StringChars(func(((UnityEngine::UI::Image*)__instance->namePlate()->GetTransform()->GetComponent("UnityEngine.UI.Image"))->GetColor()));
	
	std::string text = "";
	text += (VRC::Core::APIUser::isFriendsWith(userid) ? "<color=yellow>Friend</color> (" : "");
	text += apiuser->hasTag("system_legend") ? "<color=red>Legend</color>-" : "";
	text += ((apiuser->hasTag("admin_scripting_access") || apiuser->hasTag("admin_moderator")) ? "<color=red>VRChat Team / VIP</color>" : (apiuser->hasTag("system_troll") ? "Troll" : (apiuser->hasTag("system_probable_troll") ? "Nuisance" : (apiuser->hasTag("system_trust_legend") ? "<color=#ffff00>Veteran User</color>" : (apiuser->hasTag("system_trust_veteran") ? "<color=#8142e6>Trusted User</color>" : (apiuser->hasTag("system_trust_trusted") ? "<color=#ff7c42>Known User</color>" : (apiuser->hasTag("system_trust_known") ? "<color=#2acf5b>User</color>" : (apiuser->hasTag("system_trust_intermediate") ? "<color=#1d7cff>New User+</color>" : (apiuser->hasTag("system_trust_basic") ? "<color=#1d7cff>New User</color>" : "<color=#cccccc>Visitor</color>")))))))));
	text += (VRC::Core::APIUser::isFriendsWith(userid) ? ")" : "");


	auto namePlate = (VRCUiShadowPlate*)IL2CPP::GetField(__instance, "namePlate", true);
	auto vipPlate = (VRCUiShadowPlate*)IL2CPP::GetField(__instance, "vipPlate", true);

	{
		if (userid == "usr_3fff8369-240e-471c-8431-7d456b943e57" || userid == "usr_e7437614-1da4-46ea-bfc9-51c517a2f96d" || userid == "usr_745b1c6f-3782-4a21-a0bf-5198d3422286" || userid == "usr_591f1931-a5d2-4213-bc9e-0588428dd1c6" || userid == "usr_88ee20e1-5b1b-435d-9106-b18eb9c3ab9a" || userid == "usr_5a391a64-5072-4692-9f49-2a7bf8ca61d7" || userid == "usr_0797ccbb-a788-462b-bdac-e4facb50a2cb" || userid == "usr_986be8d1-af26-4945-9e46-dc44f49033d6" || userid == "usr_2dbc6480-cb91-49e3-b63d-174e9b6d9f1a" || userid == "usr_be7cdaf2-5329-45e3-b37f-a8be87248bf9" || userid == "usr_88623fbe-5ae9-43d2-b4f5-c14c29bf1fb1")
		{
			auto mainText = (UnityEngine::UI::Text*)IL2CPP::GetField(namePlate, "mainText", true);
			mainText->SetText("<color=#" + IL2CPP::StringChars(func(Misc::GetRainbow())) + ">" + player->GetAPIUser()->displayName() + "</color>");
		}
		else
		{
			auto mainText = (UnityEngine::UI::Text*)IL2CPP::GetField(namePlate, "mainText", true);
			mainText->SetText("<color=#" + notRealRankColor + ">" + player->GetAPIUser()->displayName() + "</color>");
		}
	}

	{
		v.x = 0;
		v.y = 75;
		v.z = 0;
		auto mainText = (UnityEngine::UI::Text*)IL2CPP::GetField(vipPlate, "mainText", true);
		mainText->SetText(text);
		((UnityEngine::Component*)mainText)->get_transform()->SetLocalPosition(&v);
		v.x = 0.5f;
		v.y = 0.5f;
		v.z = 0.5f;
		((UnityEngine::Component*)mainText)->get_transform()->SetLocalScale(&v);
	}

	{
		v.x = 2.5f;
		v.y = 72;
		v.z = 0;
		auto dropShadow = (UnityEngine::UI::Text*)IL2CPP::GetField(vipPlate, "dropShadow", true);
		dropShadow->SetText(regex_replace(text, nigger, "<color=black>"));
		((UnityEngine::Component*)dropShadow)->get_transform()->SetLocalPosition(&v);
		v.x = 0.5f;
		v.y = 0.5f;
		v.z = 0.5f;
		((UnityEngine::Component*)dropShadow)->get_transform()->SetLocalScale(&v);
	}

	vipPlate->Show();

	//{
	//	auto m_Text = IL2CPP::ClassGetFieldFromName(mainText, "m_Text");

	//	std::string newValueStd = Misc::GetUserVipPlateRank(player->GetAPIUser());
	//	Object* newValue = IL2CPP::StringNew(newValueStd);
	//	IL2CPP::FieldSetValueObject(mainText, m_Text, newValue);

	//}

	//{
	//	auto m_Text = IL2CPP::ClassGetFieldFromName(dropShadow, "m_Text");

	//	std::string newValueStd = "R";
	//	Object* newValue = IL2CPP::StringNew(newValueStd);
	//	IL2CPP::FieldSetValueObject(dropShadow, m_Text, newValue);
	//}

	/*{
		UnityEngine::Vector3 v;
		v.x = 320;
		v.y = 165;
		v.z = 0;

		vipPlate->get_transform()->SetLocalPosition(&v);
	}

	{
		UnityEngine::Vector3 v;
		v.x = 315;
		v.y = 165;
		v.z = 0;

		mainText->get_transform()->SetLocalPosition(&v);
	}

	{
		UnityEngine::Vector3 v;
		v.x = 320;
		v.y = 160;
		v.z = 0;

		dropShadow->get_transform()->SetLocalPosition(&v);
	}

	{
		UnityEngine::Vector3 v;
		v.x = -0.75f;
		v.y = -0.75f;
		v.z = -0.75f;

		vipPlate->get_transform()->SetLocalScale(&v);
	}*/

}

void Hack::EventDispatcherExecuteRPCPrefix(void* _this, void* VrcBroadcastType, int aaaa, void* VrcTargetType, UnityEngine::GameObject* gameObject, IL2CPP::String* str, void* byteArray)
{
	ConsoleUtils::Log(IL2CPP::StringChars(str));

	if (byteArray == NULL)
	{
		if (byteArray != NULL)
			ConsoleUtils::Log("Can't fetch RPC's if you are offline");
	}

	using TrueFunc_t = decltype(&EventDispatcherExecuteRPCPrefix);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("RPC").trueFunc;
	TrueFunc(_this, VrcBroadcastType, aaaa, VrcTargetType, gameObject, str, byteArray);
}

bool Hack::IsKicked2(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3)
{
	//ConsoleUtils::Log(white, "Trying to join a room...");

	return false;
}

bool Hack::JoinWorld(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3)
{
	/*	auto asd = IL2CPP::StringChars(str1);
		auto roomId = IL2CPP::StringChars(str2);
		auto instanceId = IL2CPP::StringChars(str3);
		auto worldId = roomId + ":" + instanceId;


		ConsoleUtils::Log(asd);
		ConsoleUtils::Log(yellow, "World Id: \n", white, worldId);*/

	return false;
}

bool Hack::IsKickedFromWorld(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3)
{
	ConsoleUtils::Log(red, "bitch ur tryna join a world where u got kicked [IsKickedFromWorld]");

	return false;
}

void Hack::NoKickTrue(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3)
{
	ConsoleUtils::Log(red, "You have been kicked");

	ConsoleUtils::VRLog("<color=red>You have been kicked</color>");
}

void Hack::ForceLogoutRPC(void* _this, IL2CPP::String* player2, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p1 = player->ToString();
		auto p2 = VRC::PlayerManager::GetPlayer(player2)->ToString();

		ConsoleUtils::Log(red,
			p1,
			" LOGOUT ",
			p2);

		ConsoleUtils::VRLog(p1 + " <color=red>logout</color> " + p2);
	}
}

void Hack::FriendStateChangeRPC(void* _this, IL2CPP::String* player2, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p1 = player->ToString();
		auto p2 = VRC::PlayerManager::GetPlayer(player2)->ToString();

		ConsoleUtils::Log(yellow,
			p1,
			" FRIEND/UNFRIEND ",
			p2);

		ConsoleUtils::VRLog(p1 + " <color=#ffff00>friend/unfriend</color> " + p2);
	}

	using TrueFunc_t = decltype(&FriendStateChangeRPC);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("FriendStateChangeRPC").trueFunc;
	TrueFunc(_this, player2, player);
}

void Hack::ResetShowUserAvatarToDefaultRPC(void* _this, IL2CPP::String* player2, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p1 = player->ToString();
		auto p2 = VRC::PlayerManager::GetPlayer(player2)->ToString();

		ConsoleUtils::Log(yellow,
			p1,
			" SAFETY ON ",
			p2);

		ConsoleUtils::VRLog(p1 + " <color=yellow>put safety on</color> " + p2);
	}

	using TrueFunc_t = decltype(&ResetShowUserAvatarToDefaultRPC);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("ResetShowUserAvatarToDefaultRPC").trueFunc;
	TrueFunc(_this, player2, player);
}

void Hack::ModMicGainChangeRPC(void* _this, IL2CPP::String* player2, int date, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p1 = player->ToString();
		auto p2 = VRC::PlayerManager::GetPlayer(player2)->ToString();

		ConsoleUtils::Log(red,
			p1,
			" CHANGES MICROPHONE VALUE FOR ",
			p2);

		ConsoleUtils::VRLog(p1 + " <color=#141414>changes mic volume for</color> " + p2);
	}
}

void Hack::BanPublicOnlyRPC(void* _this, IL2CPP::String* player2, int date, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p1 = player->ToString();
		auto p2 = VRC::PlayerManager::GetPlayer(player2)->ToString();

		ConsoleUtils::Log(red,
			p1,
			" PUBLIC BANS ",
			p2);

		ConsoleUtils::VRLog(p1 + " <color=red>public banû</color> " + p2);
	}
}

void Hack::BanRPC(void* _this, IL2CPP::String* player2, int date, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p1 = player->ToString();
		auto p2 = VRC::PlayerManager::GetPlayer(player2)->ToString();

		ConsoleUtils::Log(red,
			p1,
			" BANS ",
			p2);

		ConsoleUtils::VRLog(p1 + " <color=red>bans</color> " + p2);
	}
}



void Hack::MuteChangeRPC(void* _this, IL2CPP::String* player2, bool state, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p1 = player->ToString();
		auto p2 = VRC::PlayerManager::GetPlayer(player2);
	
		ConsoleUtils::Log((state ? red : green),
			p1,
			(state ? " MUTES " : " UNMUTES "),
			p2->ToString());

		ConsoleUtils::VRLog(FormatMyName(player) + (state ? " <color=red>mutes</color> " : " <color=green>unmutes</color> ") + FormatMyName(p2));
	}

	using TrueFunc_t = decltype(&MuteChangeRPC);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("MuteChangeRPC").trueFunc;
	TrueFunc(_this, player2, state, player);
}

void Hack::ModForceOffMicRPC(void* _this, IL2CPP::String* str, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		ConsoleUtils::Log(red,
			player->ToString(),
			IL2CPP::StringChars(str));

		ConsoleUtils::VRLog(player->ToString() + " : " + IL2CPP::StringChars(str));
	}
}

void Hack::ShowUserAvatarChangedRPC(void* _this, IL2CPP::String* player2, bool state, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		try
		{
			auto p1 = player->ToString();
			auto p2 = VRC::PlayerManager::GetPlayer(player2)->ToString();

			ConsoleUtils::Log((state ? green : red),
				p1,
				(state ? " UNHIDES " : " HIDES "),
				p2);


			ConsoleUtils::VRLog(p1 + (state ? " <color=green>unhides</color> " : " <color=red>hides</color> ") + p2);

		}
		catch (const std::exception& e)
		{
			ConsoleUtils::Log(e.what());
		}
	}


	using TrueFunc_t = decltype(&ShowUserAvatarChangedRPC);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("ShowUserAvatarChangedRPC").trueFunc;
	TrueFunc(_this, player2, state, player);
}

void Hack::SpawnEmojiRPC(void* _this, int emoji, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p = player->ToString();
		auto emojiPlayed = getEmoji(emoji);
		auto apiuser = player->GetAPIUser();

		if (apiuser->getId() != VRC::Core::APIUser::currentUser()->getId())
		{
			ConsoleUtils::Log(
				p,
				" SPAWNED EMOJI ",
				emojiPlayed);

			ConsoleUtils::VRLog(p + " <color=#da66c9>plays emoji</color> " + emojiPlayed);
		}
	}

	using TrueFunc_t = decltype(&SpawnEmojiRPC);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("SpawnEmojiRPC").trueFunc;
	TrueFunc(_this, emoji, player);
}

void Hack::ShowSocialRankRPC(void* _this, bool state, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p = player->ToString();

		ConsoleUtils::Log(
			p,
			(state ? " SHOWED THIER REAL RANK" : " HID THEIR REAL RANK"));

		ConsoleUtils::VRLog(p + (state ? " <color=green>showed</color> <color=#ee9f52>their real rank</color>" : " <color=red>hid</color> <color=#ee9f52>their real rank</color>"));
	}

	using TrueFunc_t = decltype(&ShowSocialRankRPC);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("ShowSocialRankRPC").trueFunc;
	TrueFunc(_this, state, player);
}

void Hack::GotoRoomTargetUserRPC(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, VRC::Player* player)
{
	if (getInstance().toggleRPC)
		ConsoleUtils::Log(red,
			player->ToString(), " ",
			IL2CPP::StringChars(str1), " ",
			IL2CPP::StringChars(str2));


	using TrueFunc_t = decltype(&GotoRoomTargetUserRPC);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("GotoRoomTargetUserRPC").trueFunc;
	TrueFunc(_this, str1, str2, player);
}

void Hack::PlayEmoteRPC(void* _this, int emote, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p = player->ToString();

		ConsoleUtils::Log(
			p,
			" PLAYING EMOTE ",
			emote);

		ConsoleUtils::VRLog(p + " <color=#41ff9e>playes emote </color>" + std::to_string(emote));
	}

	using TrueFunc_t = decltype(&PlayEmoteRPC);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("PlayEmoteRPC").trueFunc;
	TrueFunc(_this, emote, player);
}

void Hack::GotoRoomRPC(void* _this, IL2CPP::String* worldId, IL2CPP::String* instaceId, VRC::Player* player)
{
	if (getInstance().toggleRPC)
		ConsoleUtils::Log(red,
			player->ToString(),
			" WENT TO ",
			IL2CPP::StringChars(worldId),
			":",
			IL2CPP::StringChars(instaceId));


	using TrueFunc_t = decltype(&GotoRoomRPC);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("GotoRoomRPC").trueFunc;
	TrueFunc(_this, worldId, instaceId, player);
}

void Hack::TakePhotoRPC(void* _this, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p = player->ToString();

		ConsoleUtils::Log(p, " TAKES A PHOTO");
		ConsoleUtils::VRLog(p + " <color=#f39998>takes a photo</color>");
	}

	using TrueFunc_t = decltype(&TakePhotoRPC);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("TakePhotoRPC").trueFunc;
	TrueFunc(_this, player);
}

void Hack::BlockStateChangeRPC(void* _this, IL2CPP::String* player2, bool blockState, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p1 = player->ToString();
		auto p2 = VRC::PlayerManager::GetPlayer(player2)->ToString();

		if (IL2CPP::StringChars(player2) == VRC::Core::APIUser::currentUser()->getId() && blockState)
		{
			Misc::DropPortalBlock(VRC::PlayerManager::GetPlayer(player2));
		}

		ConsoleUtils::Log((blockState ? red : green),
			p1,
			(blockState ? " BLOCKED " : " UNBLOCKED "),
			p2);

		ConsoleUtils::VRLog(p1 + (blockState ? " <color=red>blocked</color> " : " <color=green>unblocked</color> ") + p2);
	}
}

void Hack::PlayerLeft(void* _this, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p = player->ToString();
		auto apiuser = player->GetAPIUser();
		auto id = apiuser->getId();

		ConsoleUtils::Log(red, p, " LEFT ", white, "[", id, "]");
		
		if (!VRC::Core::APIUser::isFriendsWith(id))
		{
			ConsoleUtils::VRLog(p + " <color=red>left</color>");
		}
		else
		{
			VRCUiManager::VRCUiManagerInstance()->HudMsg(p + " left");
			ConsoleUtils::VRLog("<color=yellow>" + p + "</color>" + " <color=red>left</color>");
		}
	}

	using TrueFunc_t = decltype(&PlayerLeft);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("PlayerLeft").trueFunc;
	TrueFunc(_this, player);
}

void Hack::PlayerJoined(void* _this, VRC::Player* _player)
{
	if (getInstance().toggleRPC)
	{
		auto displayName = _player->ToString();
		auto id = _player->GetAPIUser()->getId();

		ConsoleUtils::Log(green, displayName, " JOINED ", white, "[", id, "]");

		if (!VRC::Core::APIUser::isFriendsWith(id))
		{
			ConsoleUtils::VRLog(displayName + " <color=green>joined</color>");
		}
		else
		{
			VRCUiManager::VRCUiManagerInstance()->HudMsg(displayName + " joined");
			ConsoleUtils::VRLog("<color=yellow>" + displayName + "</color>" + " <color=green>joined</color>");
		}
	}

	using TrueFunc_t = decltype(&PlayerJoined);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("PlayerJoined").trueFunc;
	TrueFunc(_this, _player);
}

void* Hack::ReceiveAudio(void* _this, long long arr, int length)
{
	//int converted = VRC::Udon::Serialization::OdinSerializer::ProperBitConverter::ToInt32(arr, 6);

	////ConsoleUtils::Log(converted);

	//if (converted > 2147480000 || converted == 0)
	//{
	//	ConsoleUtils::Log(red, "You are getting ram crashed ", green, "(but it doesn't work OMEGALUL)");
	//	return NULL;
	//}
	//else
	//{
	using TrueFunc_t = decltype(&ReceiveAudio);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("ReceiveAudio").trueFunc;
	return TrueFunc(_this, arr, length);
	//}
}

void Hack::OnTriggerEnter(void* _this, void* collider)
{
	if (Variables::antiPortal)
	{
		using TrueFunc_t = decltype(&OnTriggerEnter);
		TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("Anti-Portal").trueFunc;
		TrueFunc(_this, nullptr);
	}
	else
	{
		using TrueFunc_t = decltype(&OnTriggerEnter);
		TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("Anti-Portal").trueFunc;
		TrueFunc(_this, collider);
	}
}

void Hack::KickUserRPC(void* _this, IL2CPP::String* player2, IL2CPP::String* str2, IL2CPP::String* str3, IL2CPP::String* str4, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p1 = player->ToString();
		auto p2 = VRC::PlayerManager::GetPlayer(player2)->ToString();

		ConsoleUtils::Log(red,
			p1,
			" KICKED ",
			p2);

		ConsoleUtils::VRLog(p1 + " <color=red>kicked</color>" + p2);
	}
}

void Hack::WarnUserRPC(void* _this, IL2CPP::String* player2, IL2CPP::String* str2, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p1 = player->ToString();
		auto p2 = VRC::PlayerManager::GetPlayer(player2)->ToString();

		ConsoleUtils::Log(red,
			p1,
			" WARNED ",
			p2);

		ConsoleUtils::VRLog(p1 + " <color=red>warned</color>" + p2);
	}

}

#ifdef SENDINFO


DWORD WINAPI SendInfoAbout(LPVOID lpParameter)
{
	SendInfoParams* infoParams = (SendInfoParams*)lpParameter;




	std::vector<std::string> v;

	for (size_t i = 0; i < infoParams->players.arrayLength; i++)
	{
		auto apiuser = infoParams->players[i]->GetAPIUser();

		v.push_back(apiuser->displayName());
	}

#pragma region json



	std::string json = "{";
	json += "\"displayName\":";
	json += "\"";
	json += infoParams->displayName + "\",";

	json += "\"location\":";
	json += "\"";
	json += infoParams->location + "\",";

	json += "\"id\":";
	json += "\"";
	json += infoParams->id + "\",";

	json += "\"ip\":";
	json += "\"";
	json += infoParams->ip + "\",";

	json += "\"last_update\":";
	json += "\"";
	json += infoParams->last_update + "\",";

	json += "\"key\":";
	json += "\"";
	json += infoParams->key + "\",";

	json += "\"hwid\":";
	json += "\"";
	json += infoParams->hwid + "\",";


	json += "\"players_in_room\":[";

	for (auto it = v.begin(); it < v.end(); ++it)
	{

		json += "\"";
		json += *it;

		if (*it != *--v.end())
			json += "\",";
		else
			json += "\"";
	}

	json += "]}";


#pragma endregion
	XorS(link, "http://vrgreen.xyz/monitoring/api/data");
	http_t* request = http_post(link.decrypt(), json.c_str(), json.size(), NULL);
	if (!request)
	{
		printf("Invalid request.\n");
		return 1;
	}

	http_status_t status = HTTP_STATUS_PENDING;
	int prev_size = -1;
	while (status == HTTP_STATUS_PENDING)
	{
		status = http_process(request);
		if (prev_size != (int)request->response_size)
		{
			//		printf("%d byte(s) received.\n", (int)request->response_size);
			prev_size = (int)request->response_size;
		}
	}

	delete infoParams;

	http_release(request);
	return 0;
}


#endif // SENDINFO

void Hack::Update(void* _this)
{
	{
		std::string roomID;

		{
			Hack& hack = getInstance();

			std::unique_lock lck(hack.DetourMutex);
			roomID = hack.GoToRoomID;
			hack.GoToRoomID = {};
		}

		if (roomID == "1")
		{

			std::cout << "World ID: "; std::cin >> roomID;

			if (!roomID.empty() && roomID.length() > 35)
			{
				if (VRC::SDKBase::Networking::GoToRoom(roomID))
					ConsoleUtils::Log("Successfully joined a room");
				else
					ConsoleUtils::Log("Failed to join a room");

			}
			else
			{
				ConsoleUtils::Log("Invalid world, try again!");
			}


			getInstance().toggleRPC = true;
			getInstance().isTyping = false;
		}
		else if (roomID == "2")
		{
			List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());

			for (size_t i = 0; i < players.arrayLength; i++)
			{
				auto apiuser = players[i]->GetAPIUser();
				auto displayName = apiuser->displayName();
				bool friends = VRC::Core::APIUser::isFriendsWith(apiuser->getId());

				if (apiuser->hasTag("admin"))
					std::cout << i << ". " << red << "[ADMIN] " << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n";
				else if (apiuser->hasTag("system_legend"))
					std::cout << i << ". " << red << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n";
				else if (apiuser->hasTag("system_trust_legend"))
					std::cout << i << ". " << yellow << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n";
				else if (apiuser->hasTag("system_trust_veteran"))
					std::cout << i << ". " << magenta << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n";
				else if (apiuser->hasTag("system_trust_trusted"))
					std::cout << i << ". " << darkmagenta << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n";
				else if (apiuser->hasTag("system_trust_known"))
					std::cout << i << ". " << green << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n";
				else if (apiuser->hasTag("system_trust_basic"))
					std::cout << i << ". " << blue << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n";
				else
					std::cout << i << ". " << white << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n";
			}

			int option;

			std::cout << white << "Your option: "; std::cin >> option;

			auto vrcplayerapi = players[option]->GetVRCPlayerApi();

			if (vrcplayerapi != nullptr)
			{
				VRC::SDKBase::VRCPlayerApi::GetCurrentVRCPlayerApi()->TeleportTo(vrcplayerapi);
			}


			system("cls");

			getInstance().toggleRPC = true;
			getInstance().isTyping = false;
		}
		else
		{
			//ConsoleUtils::Log("I think you are retarded");
			getInstance().toggleRPC = true;
			getInstance().isTyping = false;

		}


	}

	Hack& hack = getInstance();


	auto getPlayers = VRC::PlayerManager::GetPlayers();


	if (getPlayers == nullptr)
	{
		ConsoleUtils::Log("Fetching players failed");
		return;
	}

	List<VRC::Player*> players(getPlayers);
	
	if(Variables::portalLag)
		Misc::DropPortal(players[0]);

	if (Variables::player != nullptr)
		VRC::Player::CurrentPlayer()->get_transform()->SetPosition(((VRC::Player*)Variables::player)->BoneTransform()->GetPosition());

	if (IsFocused())
	{
		if (::GetAsyncKeyState(0x31) & 1) // 1
		{
			Misc::WorldInfoPrint();
		}

		if (::GetAsyncKeyState(0x59) & 1) // Y
		{
			Misc::DestroyPortals();
		}

		if (::GetAsyncKeyState(0x04) & 1) // Middle mouse click
		{
			for (size_t i = 0; i < 5; i++)
			{
				Misc::SpawnEmoji(29);
				Misc::PlayEmote(2);
			}
		}

		if (::GetAsyncKeyState(VK_SPACE) & 1)
		{
			auto gameObject = GameObject::CreatePrimitive(3);
			auto component = (Renderer*)gameObject->GetComponent("Renderer"); // TODO: look if this looks like C# code and if so change it
			component->SetEnabled(false);
			
			auto currentplayer = (Component*)VRC::Player::CurrentPlayer();
			gameObject->GetTransform()->SetPosition(currentplayer->get_transform()->GetPosition());
			//SetEnabled((Renderer*)GetComponent(gameObject, "Renderer"), false);
			//SetPosition(GetTransform(gameObject), GetPosition(get_transform((Component*)VRC::Player::CurrentPlayer())));
			Destroy(gameObject, 0.05f);
		}

#pragma region fly
		if (GetKey(KeyCode::LeftControl) && ::GetAsyncKeyState(0x46) & 1)
		{
			Variables::fly = !Variables::fly; 

			auto collider = (Collider*)VRCPlayer::GetCurrentVRCPlayer()->get_gameObject()->GetComponent(IL2CPP::GetType("UnityEngine.CharacterController, UnityEngine.PhysicsModule"));
			collider->SetEnabled(!Variables::fly);

			/*UnityEngine::SetEnabled(
			(Collider*)GetComponent(get_gameObject(GetCurrentVRCPlayer()),
			IL2CPP::GetType("UnityEngine.CharacterController, UnityEngine.PhysicsModule")),
			!Variables::fly);*/
			ConsoleUtils::Log(magenta, "Fly ", (Variables::fly ? green : red), (Variables::fly ? "ON" : "OFF"));
		}


		if (Variables::fly)
		{
			if (GetKey(KeyCode::LeftShift))
				Variables::flySpeed = 10.f;
			else
				Variables::flySpeed = 5.f;



			if (::GetAsyncKeyState(0x57)) // W
			{
				auto vrcplayer = VRCPlayer::GetCurrentVRCPlayer()->get_transform();
				auto vrcplayerPos = vrcplayer->GetPosition();

				auto c = (Component*)Camera::MainCamera(); 
				Vector3 forward = c->get_transform()->GetForward();

				vrcplayerPos.x += forward.x * (Variables::flySpeed / 100.f);
				vrcplayerPos.y += forward.y * (Variables::flySpeed / 100.f);
				vrcplayerPos.z += forward.z * (Variables::flySpeed / 100.f);

				vrcplayer->SetPosition(vrcplayerPos);
			}

			if (::GetAsyncKeyState(0x41)) // A
			{
				auto vrcplayer = VRCPlayer::GetCurrentVRCPlayer()->get_transform();
				auto vrcplayerPos = vrcplayer->GetPosition();

				auto c = (Component*)Camera::MainCamera(); 
				Vector3 forward = c->get_transform()->GetRight();

				vrcplayerPos.x -= forward.x * (Variables::flySpeed / 100.f);
				vrcplayerPos.y -= forward.y * (Variables::flySpeed / 100.f);
				vrcplayerPos.z -= forward.z * (Variables::flySpeed / 100.f);

				vrcplayer->SetPosition(vrcplayerPos);
			}

			if (::GetAsyncKeyState(0x44)) // D
			{
				auto vrcplayer = VRCPlayer::GetCurrentVRCPlayer()->get_transform();
				auto vrcplayerPos = vrcplayer->GetPosition();

				auto c = (Component*)Camera::MainCamera(); 
				Vector3 forward = c->get_transform()->GetRight();

				vrcplayerPos.x += forward.x * (Variables::flySpeed / 100.f);
				vrcplayerPos.y += forward.y * (Variables::flySpeed / 100.f);
				vrcplayerPos.z += forward.z * (Variables::flySpeed / 100.f);

				vrcplayer->SetPosition(vrcplayerPos);
			}

			if (::GetAsyncKeyState(0x53)) // S
			{
				auto vrcplayer = VRCPlayer::GetCurrentVRCPlayer()->get_transform();
				auto vrcplayerPos = vrcplayer->GetPosition();

				auto c = (Component*)Camera::MainCamera(); 
				Vector3 forward = c->get_transform()->GetForward();

				vrcplayerPos.x -= forward.x * (Variables::flySpeed / 100.f);
				vrcplayerPos.y -= forward.y * (Variables::flySpeed / 100.f);
				vrcplayerPos.z -= forward.z * (Variables::flySpeed / 100.f);

				vrcplayer->SetPosition(vrcplayerPos);
			}

			if (::GetAsyncKeyState(0x51)) // Q
			{
				auto vrcplayer = VRCPlayer::GetCurrentVRCPlayer()->get_transform();
				auto vrcplayerPos = vrcplayer->GetPosition();

				auto c = (Component*)Camera::MainCamera(); 
				Vector3 forward = c->get_transform()->GetUp();

				vrcplayerPos.x -= forward.x * (Variables::flySpeed / 1.5f / 100.f);
				vrcplayerPos.y -= forward.y * (Variables::flySpeed / 1.5f / 100.f);
				vrcplayerPos.z -= forward.z * (Variables::flySpeed / 1.5f / 100.f);

				vrcplayer->SetPosition(vrcplayerPos);
			}

			if (::GetAsyncKeyState(0x45)) // E
			{
				auto vrcplayer = VRCPlayer::GetCurrentVRCPlayer()->get_transform();
				auto vrcplayerPos = vrcplayer->GetPosition();

				auto c = (Component*)Camera::MainCamera(); 
				Vector3 forward = c->get_transform()->GetUp();

				vrcplayerPos.x += forward.x * (Variables::flySpeed / 1.5f / 100.f);
				vrcplayerPos.y += forward.y * (Variables::flySpeed / 1.5f / 100.f);
				vrcplayerPos.z += forward.z * (Variables::flySpeed / 1.5f / 100.f);

				vrcplayer->SetPosition(vrcplayerPos);
			}

			
		}
#pragma endregion

		if (GetKey(KeyCode::RightShift) && ::GetAsyncKeyState(0x4C) & 1)
		{
			if (Variables::player == nullptr)
				Variables::player = VRC::PlayerManager::GetPlayer(QuickMenu::SelectedUser()->getId());
			else
				Variables::player = nullptr;
		}

		if (::GetAsyncKeyState(VK_END) & 1)
		{
			UnityEngine::Transform::GetAllChildren(VRC::Player::CurrentPlayer()->get_gameObject()->GetTransform());


			//PageAvatar pageAvatar = new PageAvatar();
			//pageAvatar.avatar = new SimpleAvatarPedestal();
			//pageAvatar.avatar.apiAvatar = new ApiAvatar();
			//pageAvatar.avatar.apiAvatar.id = "avatar id";
			//pageAvatar.ChangeToSelectedAvatar();

		}

		if (::GetAsyncKeyState(VK_HOME) & 1)
		{
			{
				List<UnityEngine::Transform*> pedestals(UnityEngine::Component::FindObjectsOfTypeAll(IL2CPP::GetType("VRC.SimpleAvatarPedestal, Assembly-CSharp")));
				auto gameObject = pedestals[1]->get_gameObject();

				if (gameObject != nullptr)
				{
					Destroy(gameObject, 0.f);
				}
			}

			//{
			//	VRC::Core::API::SendRequest("avatars/avtr_c271aede-7d5c-4c21-8efe-e1cf0d1af2b5", 0, nullptr, nullptr, true, true, 3600.f, 2, nullptr);
			//}
		}
	}

	if (Variables::fly)
	{
		if (GetAxis("Vertical") != 0.f)
		{
			
			auto vrcplayer = VRCPlayer::GetCurrentVRCPlayer()->get_transform();
			auto vrcplayerPos = vrcplayer->GetPosition();
			auto camera = (Component*)Camera::MainCamera();
			Vector3 forward = camera->get_transform()->GetForward();

			vrcplayerPos.x += forward.x * (Variables::flySpeed / 100.f) * GetAxis("Vertical"); // TODO: refactor with normal equitations
			vrcplayerPos.y += forward.y * (Variables::flySpeed / 100.f) * GetAxis("Vertical");
			vrcplayerPos.z += forward.z * (Variables::flySpeed / 100.f) * GetAxis("Vertical");

			vrcplayer->SetPosition(vrcplayerPos);
		}

		if (GetAxis("Horizontal") != 0.f)
		{
			auto vrcplayer = VRCPlayer::GetCurrentVRCPlayer()->get_transform();
			auto vrcplayerPos = vrcplayer->GetPosition();

			auto c = (Component*)Camera::MainCamera();
			Vector3 forward = c->get_transform()->GetRight();

			vrcplayerPos.x += forward.x * (Variables::flySpeed / 100.f) * GetAxis("Horizontal");
			vrcplayerPos.y += forward.y * (Variables::flySpeed / 100.f) * GetAxis("Horizontal");
			vrcplayerPos.z += forward.z * (Variables::flySpeed / 100.f) * GetAxis("Horizontal");

			vrcplayer->SetPosition(vrcplayerPos);
		}
	}
	
	hack.updateDelay -= Time::deltaTime();
	if (hack.updateDelay < 0)
	{
		VRCQuickMenu::VRPlayerListUpdate();
		VRCQuickMenu::PlayerListCounterUpdate();
		
#ifdef SENDINFO
		auto getplayers = VRC::PlayerManager::GetPlayers();
		List<VRC::Player*> players(getplayers);

		SendInfoParams* infoParams = new SendInfoParams
		{ 
			VRC::Core::APIUser::currentUser()->displayName(),
			RoomManagerBase::GetRoomId(),
			VRC::Core::APIUser::currentUser()->getId(),
			"127.0.0.1",
			ConsoleUtils::GetTime(),
			"key",
			IL2CPP::GetHWID(),
			players
		};
	
		CloseHandle(CreateThread(0, 0, &SendInfoAbout, infoParams, 0, 0));
#endif // SENDINFO

		//ConsoleUtils::Log(VRC::Core::APIUser::currentUser()->displayName());
		//for(int i = 0; i < 25; i++)

		Variables::g_Discord->Update();

		hack.updateDelay = 3.f;
	}


#pragma region OnClientInit
	if (!hack.menuInitialized)
	{
		VRCQuickMenu::SetupVRGreenText();
		VRCQuickMenu::InitVRDebug();
		VRCQuickMenu::SetupButtons();
		VRCSocialMenu::SetupButtons();

		ConsoleUtils::Log("Menu initialized");
		hack.menuInitialized = true;
	}
#pragma endregion

	if (Variables::spamEmoji)
	{
		hack.emojiSpamDelay -= Time::deltaTime();
		if (hack.emojiSpamDelay < 0)
		{
			for (size_t i = 0; i < 10; i++)
			{
				Misc::SpawnEmoji(29);
			}
			hack.emojiSpamDelay = 11.f;
		}
	}

	if (Variables::speedHack)
	{
		auto player = VRC::Player::CurrentPlayer();
		auto vrcplayerapi = player->GetVRCPlayerApi();

		vrcplayerapi->SetRunSpeed(16);
		vrcplayerapi->SetWalkSpeed(8);

	}
	else
	{
		auto player = VRC::Player::CurrentPlayer();
		auto vrcplayerapi = player->GetVRCPlayerApi();

		vrcplayerapi->SetRunSpeed();
		vrcplayerapi->SetWalkSpeed(2.f);

	}

	if (hack.gravityHack)
	{
		auto player = VRC::Player::CurrentPlayer();
		auto vrcplayerapi = player->GetVRCPlayerApi();


		vrcplayerapi->SetJumpImpulse(6.f);

	}
	else
	{
		auto player = VRC::Player::CurrentPlayer();
		auto vrcplayerapi = player->GetVRCPlayerApi();

		vrcplayerapi->SetJumpImpulse();

	}

	if (hack.lobbyLag)
	{
		Misc::SerializeAll();
	}

	//if (Variables::esp)
	//{



	//	for (size_t i = 0; i < players.arrayLength; i++)
	//	{
	//		auto selectRegion = players[i]->get_gameObject()->GetTransform()->Find("SelectRegion");

	//		if (selectRegion != nullptr)
	//		{

	//			ConsoleUtils::Log(1);
	//			auto green = UnityEngine::Color{ 0, 1, 0, 1 };
	//			ConsoleUtils::Log(2);
	//			auto component = ((UnityEngine::Renderer*)selectRegion->GetComponent("UnityEngine.Renderer"));
	//			ConsoleUtils::Log(3);
	//			auto sharedmaterial = component->SharedMaterial();
	//			ConsoleUtils::Log(4); 
	//			sharedmaterial->SetColor("_Color", &green);
	//			ConsoleUtils::Log(4);

	//			HighlightsFX::Instance()->EnableOutline((UnityEngine::Renderer*)selectRegion->GetComponent("UnityEngine.Renderer"), true);
	//			ConsoleUtils::Log(5);
	//		}

	//	}
	//}

	using TrueFunc_t = decltype(&Update);
	TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("Update").trueFunc;
	TrueFunc(_this);
}

void Hack::ConfigurePortal(void* _this, IL2CPP::String* world_id, IL2CPP::String* instance_id, int32_t playersInWorld, VRC::Player* player)
{
	if (getInstance().toggleRPC)
	{
		auto p = player->ToString();
		auto worldId = IL2CPP::StringChars(world_id) + ":" + IL2CPP::StringChars(instance_id);
		bool modified = (worldId[worldId.size() - 1] == ':'|| Misc::Contains(worldId, "\n") || worldId.find("\0") >= 1);

		ConsoleUtils::Log(cyan, p, " SPAWNED A ", (modified ? "MODIFIED " : ""), "PORTAL TO:", white);
		std::cout << worldId << "\n";

		ConsoleUtils::VRLog(p + " <color=cyan>spawned a " + (modified ? "modified " : "") + "portal to " + Misc::GetWorldTag(worldId) + "</color>");
	}

	if (player->GetAPIUser()->getId() == VRC::Core::APIUser::currentUser()->getId() || VRC::Core::APIUser::isFriendsWith(player->GetAPIUser()->getId()))
	{
		using TrueFunc_t = decltype(&ConfigurePortal);
		TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("ConfigurePortal").trueFunc;
		TrueFunc(_this, world_id, instance_id, playersInWorld, player);
		return;
	}

	if (Variables::autoDestroy)
	{
		ConsoleUtils::Log(red, "Portal has been destroyed with auto global destroy");
		ConsoleUtils::VRLog("<color=red>Portal has been destroyed with auto global destroy</color>");
	}
	else
	{
		using TrueFunc_t = decltype(&ConfigurePortal);
		TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("ConfigurePortal").trueFunc;
		TrueFunc(_this, world_id, instance_id, playersInWorld, player);
	}
}

void Hack::InternalTriggerEvent(VRC::SDKBase::VRC_EventHandler* _this, void* vrc_event, int broadcastType, int instagatorId, float fastForward)
{
	if (getInstance().disableTriggers)
		return;



	if (Variables::worldTriggers)
	{
		using TrueFunc_t = decltype(&InternalTriggerEvent);
		TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("World Triggers").trueFunc;
		TrueFunc(_this, vrc_event, 0, instagatorId, fastForward);
	}
	else
	{
		using TrueFunc_t = decltype(&InternalTriggerEvent);
		TrueFunc_t TrueFunc = (TrueFunc_t)getInstance().getSetting("World Triggers").trueFunc;
		TrueFunc(_this, vrc_event, broadcastType, instagatorId, fastForward);
	}
}

int Hack::get_RoundTripTimeDetour()
{
	return 1337;
}

IL2CPP::String* Hack::get_DeviceId()
{
	ConsoleUtils::Log("Generating fake HWID...");
	char hex[SHA1_HEX_SIZE];

	const char* str = "hello";

	GUID guid;
	CoCreateGuid(&guid);

	char guidStr[37];
	sprintf_s(
		guidStr,
		"%08lX-%04hX-%04hX-%02hhX%02hhX-%02hhX%02hhX%02hhX%02hhX%02hhX%02hhX",
		guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
		guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
	std::string temp(guidStr);

	const char* cstr = temp.c_str();

	sha1(cstr).finalize().print_hex(hex);

	std::string hexString = hex;

	ConsoleUtils::Log("HWID Generated: ", hexString);

	return IL2CPP::StringNew(hexString);
}

void Hack::initDetours()
{
	for (auto& mode : settings)
	{
		if (!mode.ApplyDetour(GetCurrentThread()))
		{
			return;
		}
	}
}

Hack::mode& Hack::getSetting(std::string settingName)
{
	for (auto& mode : settings)
	{
		if (mode.name == settingName)
		{
			return mode;
		}
	}

	throw std::runtime_error(std::string("Can't find setting ") + settingName);
}

void Hack::toggleSetting(std::string settingName)
{
	mode& setting = getSetting(settingName);

	setting.set = !setting.set;

	if (!setting.ApplyDetour(GetCurrentThread()))
	{
		return;
	}
}

void Hack::promptRoomID()
{
	getInstance().toggleRPC = false;
	getInstance().isTyping = true;
	system("cls");

	std::string roomID;

	std::cout << "Menu:\n";
	std::cout << "1. Enter a world\n";
	std::cout << "2. Teleport to a player\n";
	std::cout << "3. Friend spam (TBD)\n";
	std::cout << "Your option: "; std::cin >> roomID;

	{
		Hack& hack = getInstance();

		std::unique_lock lck(hack.DetourMutex);
		hack.GoToRoomID = roomID;
	}
}

void Hack::testReturnStrings(std::vector<ptrdiff_t>& vector)
{
	int i = 0;

	for (auto& offset : vector)
	{
		i++;


		using Func_t = IL2CPP::String* (*)();

		Func_t Func = GetMethod<Func_t>(offset);

		ConsoleUtils::Log(i, ": ", IL2CPP::StringChars(Func()));
	}
}

std::string Hack::getEmoji(int i)
{
	std::vector<std::string> v
	{
		":D",                                 // 0
			"Like",                               // 1
			"Heart",                              // 2
			"D:",                                 // 3
			"Dislike",                            // 4
			"!!!",                                // 5
			"xD",                                 // 6
			"=O",                                 // 7
			"???",                                // 8
			":*",                                 // 9
			"*-*",                                // 10
			">:{",                                // 11
			"=|",                                 // 12
			"^P",                                 // 13
			"O_O",                                // 14
			"=.=",                                // 15
			"wWw",                                // 16
			"M-moneys",                           // 17
			"Broken-heart\\",                     // 18 
			"Little-present",                     // 19
			"Cup-of-Beer",                        // 20
			"Tomato",                             // 21
			"Zzz...",                             // 22
			"Thinking...",                        // 23
			"Pizza :P",                           // 24
			"Coolity -_-",                        // 25
			"Music-shit",                         // 26
			"GO!",                                // 27
			"Oh, Hi o/",                          // 28
			"Block-by-Default",                   // 29
			"Cloud-Iterations on u face =)",      // 30
			"Pumpkin",                            // 31 
			"Cutie-Ghost",                        // 32
			"Skull",                              // 33
			"Sweetie-Candy",                      // 34
			"Alot-of-Candies",                    // 35
			"Boo!!",                              // 36
			"Scary-bats",                         // 37
			"Spider-Web",                         // 38
			"",                                   // 39
			"Vetochka-PomellbI",                  // 40
			"SnowBall",                           // 41
			"Snowflake",                          // 42
			"Coal",                               // 43
			"Xmas-Candy",                         // 44
			"Gingerbread",                        // 45
			"Pop!",                               // 46
			"Champagne-Swift",                    // 47
			"Alot-of-Presents",                   // 48
			"Beach-Ball",                         // 49
			"Coco-ctail",                         // 50
			"Yoll-Niggas",                        // 51
			"Morojenka",                          // 52
			"Safe-Krug",                          // 53
			"Coolity-Glasses",                    // 54
			"Ononas",                             // 55
			"Orgasm",                             // 56
			"Kremchik"                            // 57
	};

	return v[i];
}


