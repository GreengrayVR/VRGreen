#pragma once

// public static void SendPutRequest(string target, ApiContainer responseContainer, Dictionary<string, object> requestParams, API.CredentialsBundle credentials) { }
#define OFFLINE_MODE 0x732130

// public int get_RoundTripTime() { }
#define FAKE_PING 0x186A720

// private void InternalTriggerEvent(VRC_EventHandler.VrcEvent e, VRC_EventHandler.VrcBroadcastType broadcast, int instagatorId, float fastForward) { }
#define WORLD_TRIGGERS 0x16DCEB0

// private void ConfigurePortal(string
#define CONFIGURE_PORTAL 0x2DB7470

// private void WarnUserRPC(string
#define WARNUSERRPC 0x2A3FFB0

// private void KickUserRPC(string
#define KICKUSERRPC 0x2A2CEC0

// private void BlockStateChangeRPC
#define BLOCKSTATECHANGERPC 0x2A2CB10

// private void OnTriggerEnter ( PortalTrigger : MonoBehaviour )
#define ANTI_PORTAL 0x33A50E0

// public List<Action>
#define RECEIVEAUDIO 0x2BEDF80

// public static string get_DeviceID() { }
#define DEVICEID 0x732F00

// ForceLogoutRPC
#define FORCELOGOUTRPC 0x2A2CC00

// FriendStateChangeRPC
#define FRIENDSTATECHANGERPC 0x2A2CDA0

// BanPublicOnlyRPC
#define BANPUBLICONLYRPC 0x2A2C580

// ResetShowUserAvatarToDefaultRPC
#define RESETSHOWUSERAVATARTODEFAULTRPC 0x2A2E370

// ModMicGainChangeRPC
#define MODMICGAINCHANGERPC 0x2A2D420

// BanRPC
#define BANRPC 0x2A2C880

// MuteChangeRPC
#define MUTECHANGERPC 0x2A2D5F0

// ModForceOffMicRPC
#define MODFORCEOFFMICRPC 0x2A2D260

// ShowUserAvatarChangedRPC
#define SHOWUSERAVATARCHANGERPC 0x2A2E450

// SpawnEmojiRPC
#define SPAWNEMOJIRPC 0x289BB60

// ShowSocialRankRPC
#define SHOWSOCIALRANKRPC 0x289BA20

// GotoRoomTargetUserRPC
#define GOTOROOMTARGETUSERRPC 0x289B370

// PlayEmoteRPC
#define PLAYEMOTERPC 0x289B7F0

// GotoRoomRPC
#define GOTOROOMRPC 0x289B1B0

// TakePhotoRPC
#define TAKEPHOTORPC 0x35AED30

// private void _DestroyObject(int 
#define _DESTROYOBJECT 0x2ED0EE0

// public static bool IsFriendsWith(string userId) { }
#define ISFRIENDSWITH 0x72BCE0

// public bool HasTag(string tag) { } ( APIUser : ApiModel )
#define HASTAG 0x72B7B0

// public static APIUser get_CurrentUser() { }
#define CURRENTUSER 0x72F1F0

// public string get_displayName() { } ( APIUser : ApiModel )
#define DISPLAYNAME 0x4E4C70

// public override void xxxx(float xxxx) { } ( VRCPlayer : VRCNetworkBehaviour )
#define VRCPLAYERCUSTOMPLATES 0x28A2F30

// public void Update() { } ( UserInteractMenu : MonoBehaviour )
#define USERINTERACTMENU 0x2EA02F0

// public\sPlayer\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define PLAYER_FROM_VRCPLAYER 0x289CDE0

// internal\sstatic\sPlayer\s\w+\(\)\s{\s} ( class Player : MonoBehaviour )
#define PLAYERCURRENTUSER 0x298CD30

// public override string ToString() { } ( class Player : MonoBehaviour )
#define PLAYERTOSTRING 0x298BE90

// public string get_Id() { } ( ApiGroup : ApiModel )
#define GETID 0x432E80

// public static bool GoToRoom(string roomID) { }
#define GOTOROOM 0x16D2BA0

// public int get_playerId() { }
#define GETPLAYERID 0x16D6F70

// public static float get_deltaTime() { }
#define DELTATIME 0x1AC3960

// public Transform Find(string
#define TRANSFORM_FIND 0x1AC5730

// public void SetParent(Transform
#define TRANSFORM_SETPARENT 0x1AC7810

// public void SetRunSpeed(float speed = 4) { }
#define SETRUNSPEED 0x16D60A0

// public void TeleportTo(Vector3 teleportPos, Quaternion teleportRot) { }
#define TELEPORTTO 0x16D6450

// public void SetWalkSpeed(float speed = 2) { }
#define SETWALKSPEED 0x16D6330

// private static bool GetKeyDownString(string name) { }
#define GETKEYDOWNSTRING 0x1C9FEE0

// public static Color get_cyan() { }
#define GETCYAN 0x19F6340

// public static Color get_red() { }
#define GETRED 0x19F65C0

// public void SetNamePlateColor(Color col) { }
#define SETNAMEPLATECOLOR 0x16D5ED0

// public void SetMuteStatus(bool canSpeak, bool canHear) { }
#define SETMUTESTATUS 0x16E3590

// public void SetActive(bool value) { }
#define SETACTIVE 0x1C9B140

// public void set_interactable(bool value) { } ( public class Selectable )
#define SETINTERACTABLE 0x19B06B0

// public virtual void set_color(Color value) { }
#define SETCOLOR 0x18C6260

// public void SetJumpImpulse(float impulse = 3) { }
#define SETJUMPIMPULSE 0x16D5E40

// public\sulong\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define GETSTEAMID 0x28A1AE0

// public\sstatic\sVRCUiPopupManager\s\w+\(\)\s{\s} ( VRCUiPopupManager : MonoBehaviour )
#define VRCUIPOPUPMANAGER 0x31D7A30

// public\svoid\s\w+\(string\s\w+,\sstring\s\w+,\sfloat\s\w+\s=\s10\)\s{\s} ( VRCUiPopupManager : MonoBehaviour )
#define SHOWALERT 0x31D7AE0

// public\sstatic\sstring\s\w+\(APIUser\s\w+\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define SOCIALMENURANK 0x289C1F0

// public GameObject get_gameObject() { } ( Component : Object )
#define GETGAMEOBJECT 0x19F7530

// private void Update() { } ( VRCHandGrasper : MonoBehaviour )
#define VRCHANDGRASPER 0x2FCF930

// public static int ToInt32(byte[] buffer, int index) { } ( static class ProperBitConverter )
#define TOINT32 0x1636760

// public void set_localPosition(Vector3 value) { } ( class Transform : Component )
#define SETLOCALPOSITION 0x1AC9940

// public Transform get_transform() { } ( Component : Object )
#define GETTRANSFORM_COMPONENT 0x19F7600

// public Transform get_transform() { } ( GameObject : Object )
#define GETTRANSFORM_GAMEOBJECT 0x1C9B7D0

// public void set_localScale(Vector3 value) { } ( Transform : Component )
#define SETLOCALSCALE 0x1AC9B00

// ReceiveVoteToKickInitiation
#define VOTEKICKINIT 0x2A2D810

// public Component GetComponent(string type) { } ( Component : Object )
#define GETCOMPONENT_COMPONENT 0x19F7060

// public static Object Instantiate(Object original) { } ( public class Object )
#define INSTANTIATE1 0x1CBEE50

// public static Object Instantiate(Object original, Transform parent, bool instantiateInWorldSpace) { } ( public class Object )
#define INSTANTIATE2 0x1CBEFD0

// public string get_name() { } ( public class Object )
#define GETOBJECTNAME 0x1CBFA10

// public\sstatic\sVRCUiManager\s\w+\(\)\s{\s} ( VRCUiManager : MonoBehaviour )
#define VRCUIMANAGER 0x2C2E2F0

// public\svoid\s\w+\(string\s\w+\)\s{\s} ( VRCUiManager : MonoBehaviour )
#define HUDMSG 0x2C2C550

// public\sstatic\sQuickMenu\s\w+\(\)\s{\s} ( QuickMenu : MonoBehaviour )
#define QUICKMENU 0x28ECA40

// public\sVRCPlayerApi\s\w+\(\)\s{\s} ( class Player : MonoBehaviour )
#define GETVRCPLAYERAPI 0x4F6EA0

// public static void Destroy(Object obj, float t) { } ( public class Object )
#define DESTROY 0x1CBE810

// public Vector3 GetPosition() { } ( public class VRCPlayerApi )
#define GETPLAYERPOSITION 0x16D52F0

// public Quaternion GetRotation() { } ( public class VRCPlayerApi )
#define GETPLAYERROTATION 0x16D5390

// public static Type GetType(string typeName) { } ( public abstract class Type : MemberInfo )
#define GETTYPE 0x1AE5840

// public virtual Type[] GetTypes() { } ( public class Assembly : ICustomAttributeProvider )
#define GETTYPES 0x1A90060

// public override string ToString() { } ( public abstract class Type : MemberInfo )
#define TYPETOSTRING 0x1AE6B20

// public string get_name() { } ( public class ApiAvatar : ApiModel )
#define APIAVATARNAME 0x430620

// public string get_name() { } ( public class ApiWorld : ApiModel )
#define APIWORLDNAME 0x430620

// public ApiWorldInstance.AccessType GetAccessType() { } ( public class ApiWorldInstance )
#define GETACCESSTYPE 0x1095CF0

// public string get_authorName() { } ( public class ApiAvatar : ApiModel )
#define AUTHORNAME 0x442DD0

// public T GetComponentInChildren() { } ( public class Component : Object )
#define COMPONENTINCHILDREN 0x29D1DF0

// public void .ctor(object object, IntPtr method) { } ( public sealed class UnityAction : MulticastDelegate )
#define UNITYACTIONCTOR 0x50B060

// public string get_currentAvatarAssetUrl() { } ( public class APIUser : ApiModel )
#define VRCAURL 0x442CC0

// public void set_name(string value) { } ( Instantiate failed because the clone was destroyed during creation. This can happen )
#define OBJECTSETNAME 0x1CBFCB0

// public Vector3 get_localPosition() { } ( public class Transform : Component )
#define GETLOCALPOS 0x1AC8B00

// public Transform GetChild(int index) { } ( public class Transform : Component )
#define GETCHILD 0x1AC58D0

// public int get_childCount() { } ( public class Transform : Component )
#define GETCHILDCOUNT 0x1AC8640

// public void SetParent(Transform parent, bool worldPositionStays) { } ( public class Transform : Component )
#define SETPARENTBOOL 0x1AC7790

// public\sApiAvatar\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define GETAPIAVATAR 0x289CA80

// public string get_assetUrl() { } ( public class ApiAvatar : ApiModel )
#define GETASSETURL 0x5A3B20

#define GETHWID 0x1ABF420

#define FINDOBJECTSOFTYPEALL 0x1AB7360

#define ISFOCUSED 0x19E9320

#define CREATEPRIMITIVE 0x1C9A4F0

#define GETCOMPONENT_GAMEOBJECT 0x1C9A660

#define SETPOSITION_TRANSFORM 0x1AC9CB0

#define GETPOSITION_TRANSFORM 0x1AC9010

#define SETENABLED_RENDERER 0x1CD4CD0