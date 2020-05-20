#pragma once

// public static void SendPutRequest(string target, ApiContainer responseContainer, Dictionary<string, object> requestParams, API.CredentialsBundle credentials) { }
#define OFFLINE_MODE 0xC4ABC0

// public int get_RoundTripTime() { }
#define FAKE_PING 0x166B0A0

// private void InternalTriggerEvent(VRC_EventHandler.VrcEvent e, VRC_EventHandler.VrcBroadcastType broadcast, int instagatorId, float fastForward) { }
#define WORLD_TRIGGERS 0x1463900

// private void ConfigurePortal(string
#define CONFIGURE_PORTAL 0x2509BB0

// private void WarnUserRPC(string
#define WARNUSERRPC 0x1F3A8B0

// private void KickUserRPC(string
#define KICKUSERRPC 0x1F25C50

// private void BlockStateChangeRPC
#define BLOCKSTATECHANGERPC 0x1F258A0

// private void OnTriggerEnter ( PortalTrigger : MonoBehaviour )
#define ANTI_PORTAL 0x2C325B0

// public List<Action>
#define RECEIVEAUDIO 0x1F83A60

// public static string get_DeviceID() { }
#define DEVICEID 0xC4B9C0

// ForceLogoutRPC
#define FORCELOGOUTRPC 0x1F25990

// FriendStateChangeRPC
#define FRIENDSTATECHANGERPC 0x1F25B30

// BanPublicOnlyRPC
#define BANPUBLICONLYRPC 0x1F25310

// ResetShowUserAvatarToDefaultRPC
#define RESETSHOWUSERAVATARTODEFAULTRPC 0x1F27100

// ModMicGainChangeRPC
#define MODMICGAINCHANGERPC 0x1F261B0

// BanRPC
#define BANRPC 0x1F25610

// MuteChangeRPC
#define MUTECHANGERPC 0x1F26380

// ModForceOffMicRPC
#define MODFORCEOFFMICRPC 0x1F25FF0

// ShowUserAvatarChangedRPC
#define SHOWUSERAVATARCHANGERPC 0x1F271E0

// SpawnEmojiRPC
#define SPAWNEMOJIRPC 0x1E311A0

// ShowSocialRankRPC
#define SHOWSOCIALRANKRPC 0x1E31060

// GotoRoomTargetUserRPC
#define GOTOROOMTARGETUSERRPC 0x1E309B0

// PlayEmoteRPC
#define PLAYEMOTERPC 0x1E30E30

// GotoRoomRPC
#define GOTOROOMRPC 0x1E307F0

// TakePhotoRPC
#define TAKEPHOTORPC 0x293D640

// private void _DestroyObject(int 
#define _DESTROYOBJECT 0x2014A20

// public static bool IsFriendsWith(string userId) { }
#define ISFRIENDSWITH 0xC44860

// public bool HasTag(string tag) { } ( APIUser : ApiModel )
#define HASTAG 0xC44330

// public static APIUser get_CurrentUser() { }
#define CURRENTUSER 0xC47DB0

// public string get_displayName() { } ( APIUser : ApiModel )
#define DISPLAYNAME 0x4E4C70

// public override void xxxx(float xxxx) { } ( VRCPlayer : VRCNetworkBehaviour )
#define VRCPLAYERCUSTOMPLATES 0x1E34090

// public void Update() { } ( UserInteractMenu : MonoBehaviour )
#define USERINTERACTMENU 0x20CD770

// public\sPlayer\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define PLAYER_FROM_VRCPLAYER 0x1E32EC0

// internal\sstatic\sPlayer\s\w+\(\)\s{\s} ( class Player : MonoBehaviour )
#define PLAYERCURRENTUSER 0x1F56900

// public override string ToString() { } ( class Player : MonoBehaviour )
#define PLAYERTOSTRING 0x1F566C0

// public string get_id() { } ( ApiGroup : ApiModel )
#define GETID 0x432E80

// public static bool GoToRoom(string roomID) { }
#define GOTOROOM 0x145CC90

// public int get_playerId() { }
#define GETPLAYERID 0x1461330

// public static float get_deltaTime() { }
#define DELTATIME 0x1830B10

// public Transform Find(string
#define TRANSFORM_FIND 0x18328E0

// public void SetParent(Transform
#define TRANSFORM_SETPARENT 0x18349C0

// public void SetRunSpeed(float speed = 4) { }
#define SETRUNSPEED 0x1460460

// public void TeleportTo(Vector3 teleportPos, Quaternion teleportRot) { }
#define TELEPORTTO 0x1460810

// public void SetWalkSpeed(float speed = 2) { }
#define SETWALKSPEED 0x14606F0

// private static bool GetKeyDownString(string name) { }
#define GETKEYDOWNSTRING 0x19657E0

// public static Color get_cyan() { }
#define GETCYAN 0x342BD00

// public static Color get_red() { }
#define GETRED 0x342BF80

// public void SetNamePlateColor(Color col) { }
#define SETNAMEPLATECOLOR 0x1460290

// public void SetMuteStatus(bool canSpeak, bool canHear) { }
#define SETMUTESTATUS 0x146A050

// public void SetActive(bool value) { }
#define SETACTIVE 0x19608D0

// public void set_interactable(bool value) { } ( public class Selectable )
#define SETINTERACTABLE 0x17797B0

// public virtual void set_color(Color value) { }
#define SETCOLOR 0x16925C0

// public void SetJumpImpulse(float impulse = 3) { }
#define SETJUMPIMPULSE 0x1460200

// public\sulong\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define GETSTEAMID 0x1E372D0

// public\sstatic\sVRCUiPopupManager\s\w+\(\)\s{\s} ( VRCUiPopupManager : MonoBehaviour )
#define VRCUIPOPUPMANAGER 0x22F2FA0

// public\svoid\s\w+\(string\s\w+,\sstring\s\w+,\sfloat\s\w+\s=\s10\)\s{\s} ( VRCUiPopupManager : MonoBehaviour )
#define SHOWALERT 0x22F5A30

// public\sstatic\sstring\s\w+\(APIUser\s\w+\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define SOCIALMENURANK 0x1E39490

// public GameObject get_gameObject() { } ( Component : Object )
#define GETGAMEOBJECT 0x342CCE0

// private void Update() { } ( VRCHandGrasper : MonoBehaviour )
#define VRCHANDGRASPER 0x23B87E0

// public static int ToInt32(byte[] buffer, int index) { } ( static class ProperBitConverter )
#define TOINT32 0x15099C0

// public void set_localPosition(Vector3 value) { } ( class Transform : Component )
#define SETLOCALPOSITION 0x1836AF0

// public Transform get_transform() { } ( Component : Object )
#define GETTRANSFORM_COMPONENT 0x342CDB0

// public Transform get_transform() { } ( GameObject : Object )
#define GETTRANSFORM_GAMEOBJECT 0x1960F70

// public void set_localScale(Vector3 value) { } ( Transform : Component )
#define SETLOCALSCALE 0x1836CB0

// ReceiveVoteToKickInitiation
#define VOTEKICKINIT 0x1F265A0

// public Component GetComponent(string type) { } ( Component : Object )
#define GETCOMPONENT_COMPONENT 0x342C810

// public static Object Instantiate(Object original) { } ( public class Object )
#define INSTANTIATE1 0x390ACC0

// public static Object Instantiate(Object original, Transform parent, bool instantiateInWorldSpace) { } ( public class Object )
#define INSTANTIATE2 0x390AE40

// public string get_name() { } ( public class Object )
#define GETOBJECTNAME 0x390B880

// public\sstatic\sVRCUiManager\s\w+\(\)\s{\s} ( VRCUiManager : MonoBehaviour )
#define VRCUIMANAGER 0x26ED190

// public\svoid\s\w+\(string\s\w+\)\s{\s} ( VRCUiManager : MonoBehaviour )
#define HUDMSG 0x26EC1B0

// public\sstatic\sQuickMenu\s\w+\(\)\s{\s} ( QuickMenu : MonoBehaviour )
#define QUICKMENU 0x1E5FF20

// public\sVRCPlayerApi\s\w+\(\)\s{\s} ( class Player : MonoBehaviour )
#define GETVRCPLAYERAPI 0x4F6EA0

// public static void Destroy(Object obj, float t) { } ( public class Object )
#define DESTROY 0x390A690

// public Vector3 GetPosition() { } ( public class VRCPlayerApi )
#define GETPLAYERPOSITION 0x145F6B0

// public Quaternion GetRotation() { } ( public class VRCPlayerApi )
#define GETPLAYERROTATION 0x145F750

// public static Type GetType(string typeName) { } ( public abstract class Type : MemberInfo )
#define GETTYPE 0x1852D90

// public virtual Type[] GetTypes() { } ( public class Assembly : ICustomAttributeProvider )
#define GETTYPES 0x1811520

// public override string ToString() { } ( public abstract class Type : MemberInfo )
#define TYPETOSTRING 0x1854070

// public string get_name() { } ( public class ApiAvatar : ApiModel )
#define APIAVATARNAME 0x430620

// public string get_name() { } ( public class ApiWorld : ApiModel )
#define APIWORLDNAME 0x430620

// public ApiWorldInstance.AccessType GetAccessType() { } ( public class ApiWorldInstance )
#define GETACCESSTYPE 0x12624E0

// public string get_authorName() { } ( public class ApiAvatar : ApiModel )
#define AUTHORNAME 0x442DD0

// public T GetComponentInChildren() { } ( public class Component : Object )
#define COMPONENTINCHILDREN 0x2095730

// public void .ctor(object object, IntPtr method) { } ( public sealed class UnityAction : MulticastDelegate )
#define UNITYACTIONCTOR 0x50B060

// public string get_currentAvatarAssetUrl() { } ( public class APIUser : ApiModel )
#define VRCAURL 0x442CC0

// public void set_name(string value) { } ( Instantiate failed because the clone was destroyed during creation. This can happen )
#define OBJECTSETNAME 0x390BB20

// public Vector3 get_localPosition() { } ( public class Transform : Component )
#define GETLOCALPOS 0x1835CB0

// public Transform GetChild(int index) { } ( public class Transform : Component )
#define GETCHILD 0x1832A80

// public int get_childCount() { } ( public class Transform : Component )
#define GETCHILDCOUNT 0x18357F0

// public void SetParent(Transform parent, bool worldPositionStays) { } ( public class Transform : Component )
#define SETPARENTBOOL 0x1834940

// public\sApiAvatar\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define GETAPIAVATAR 0x1E330E0

// public string get_assetUrl() { } ( public class ApiAvatar : ApiModel )
#define GETASSETURL 0x5A3B20

// static string get_deviceUniqueIdentifier ( public sealed class SystemInfo // )
#define GETHWID 0x182C580

// public static Object[] FindObjectsOfTypeAll(Type type) { } ( public sealed class Resources )
#define FINDOBJECTSOFTYPEALL 0x18244C0

// public static bool get_isFocused() { } ( None )
#define ISFOCUSED 0x341EE60

// static GameObject CreatePrimitive(PrimitiveType ( class GameObject : Object )
#define CREATEPRIMITIVE 0x195FC80

// Component GetComponent(string type) { } ( class GameObject : Object )
#define GETCOMPONENT_GAMEOBJECT 0x195FDF0

// public void set_position(Vector3 value) { } ( Transform : Component )
#define SETPOSITION_TRANSFORM 0x1836E60

// public Vector3 get_position() { } ( Transform : Component )
#define GETPOSITION_TRANSFORM 0x18361C0

// public void set_enabled(bool value) { } ( public class Renderer : Component )
#define SETENABLED_RENDERER 0x3920B30

// public void .ctor() { } ( class ArrayList : IList )
#define ARRAYLIST_CTOR 0x17AAF80

// public virtual int Add(object value) { } ( class ArrayList : IList )
#define ARRAYLIST_ADD 0x17A9A80

// public virtual object[] ToArray() { } ( class ArrayList : IList )
#define ARRAYLIST_TOARRAY 0x17AAC60

// public Button.ButtonClickedEvent get_onClick() { } ( class Button : Selectable )
#define GETONCLICK 0x13ED860

// public void set_onClick(Button.ButtonClickedEvent value) { } ( class Button : Selectable )
#define SETONCLICK 0xABE230

// void .ctor() ( public class Button.ButtonClickedEvent : UnityEvent )
#define BUTTONCLICKCTOR 0x13ED5D0

// public static void RPC(RPC.Destination targetClients, GameObject targetObject, string methodName, object[] parameters) { } ( public static class Networking )
#define NETWORKING_RPC 0x145D150

// public static GameObject Instantiate(VRC_EventHandler.VrcBroadcastType broadcast, string prefabPathOrDynamicPrefabName, Vector3 position, Quaternion rotation) { } ( public static class Networking )
#define NETWORKING_INSTANTIATE 0x145CD40

// public static Type GetType(string typeName, bool throwOnError, bool ignoreCase) { } ( abstract class Type : MemberInfo )
#define GETTYPE_TYPE_BOOL_BOOL 0x1852B30

// public void AddListener(UnityAction call) { } ( public class UnityEvent : UnityEventBase )
#define ADDLISTENER 0x3435D30

// public virtual void set_text(string value) { } ( public class Text : MaskableGraphic )
#define SET_TEXT 0x177F100

// public static Camera get_main() { } ( public sealed class Camera : Behaviour )
#define CAMERA_GET_MAIN 0x3427EC0

// public void set_enabled(bool value) { } ( public class Collider : Component )
#define SETENABLED_COLLIDER 0x1D86940

// public Component GetComponent(Type type) { } ( public class Component : Object )
#define GETCOMPONENT_TYPE_TYPE 0x342C790

// public Component AddComponent(Type componentType) { } ( public sealed class GameObject : Object )
#define ADDCOMPONENT 0x195FAB0

// public bool get_activeSelf() { } ( public sealed class GameObject : Object )
#define GET_ACTIVESELF 0x1960C40

// public static GameObject Find(string name) { } ( public sealed class GameObject : Object )
#define GAMEOBJECT_FIND 0x195FD90

// public Component GetComponent(Type type) { } ( public sealed class GameObject : Object )
#define GAMEOBJECT_GETCOMPONENT 0x1960040

// public static bool GetKey(KeyCode key) { } ( public class Input // )
#define GETKEYPRESSED 0x1965840

// public static float GetAxis(string axisName) { } ( public class Input // )
#define INPUT_GETAXIS 0x19655C0

// public Vector3 get_forward() { } ( public class Transform : Component )
#define GET_FORWARD 0x1835900

// public Vector3 get_right() { } ( public class Transform : Component )
#define GET_RIGHT 0x1836250

// public Vector3 get_up() { } ( public class Transform : Component )
#define GET_UP 0x18364B0

