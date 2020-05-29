#pragma once

// public static void SendPutRequest(string target, ApiContainer responseContainer, Dictionary<string, object> requestParams, API.CredentialsBundle credentials) { }
#define OFFLINE_MODE 0xC49030

// public int get_RoundTripTime() { }
#define FAKE_PING 0x16BEA60

// private void InternalTriggerEvent(VRC_EventHandler.VrcEvent e, VRC_EventHandler.VrcBroadcastType broadcast, int instagatorId, float fastForward) { }
#define WORLD_TRIGGERS 0x149BD70

// private void ConfigurePortal(string
#define CONFIGURE_PORTAL 0x233D890

// private void WarnUserRPC(string
#define WARNUSERRPC 0x2042840

// private void KickUserRPC(string
#define KICKUSERRPC 0x2032230

// private void BlockStateChangeRPC
#define BLOCKSTATECHANGERPC 0x2031E80

// private void OnTriggerEnter ( PortalTrigger : MonoBehaviour )
#define ANTI_PORTAL 0x3117A20

// public List<Action>
#define RECEIVEAUDIO 0x2133590

// public static string get_DeviceID() { }
#define DEVICEID 0xC49E30

// ForceLogoutRPC
#define FORCELOGOUTRPC 0x2031F70

// FriendStateChangeRPC
#define FRIENDSTATECHANGERPC 0x2032110

// BanPublicOnlyRPC
#define BANPUBLICONLYRPC 0x20318F0

// ResetShowUserAvatarToDefaultRPC
#define RESETSHOWUSERAVATARTODEFAULTRPC 0x2033740

// ModMicGainChangeRPC
#define MODMICGAINCHANGERPC 0x2032790

// BanRPC
#define BANRPC 0x2031BF0

// MuteChangeRPC
#define MUTECHANGERPC 0x20329C0

// ModForceOffMicRPC
#define MODFORCEOFFMICRPC 0x20325D0

// ShowUserAvatarChangedRPC
#define SHOWUSERAVATARCHANGERPC 0x2033820

// SpawnEmojiRPC
#define SPAWNEMOJIRPC 0x1EEE950

// ShowSocialRankRPC
#define SHOWSOCIALRANKRPC 0x1EEE810

// GotoRoomTargetUserRPC
#define GOTOROOMTARGETUSERRPC 0x1EEE160

// PlayEmoteRPC
#define PLAYEMOTERPC 0x1EEE5E0

// GotoRoomRPC
#define GOTOROOMRPC 0x1EEDFA0

// private void _DestroyObject(int 
#define _DESTROYOBJECT 0x2467B00

// public static bool IsFriendsWith(string userId) { }
#define ISFRIENDSWITH 0xC42CD0

// public bool HasTag(string tag) { } ( APIUser : ApiModel )
#define HASTAG 0xC427A0

// public static APIUser get_CurrentUser() { }
#define CURRENTUSER 0xC46220

// public string get_displayName() { } ( APIUser : ApiModel )
#define DISPLAYNAME 0x4E2C70

// public\soverride\svoid\s\w+\(float ( VRCPlayer : VRCNetworkBehaviour )
#define VRCPLAYERCUSTOMPLATES 0x1EF2ED0

// public void Update() { } ( UserInteractMenu : MonoBehaviour )
#define USERINTERACTMENU 0x2D248E0

// public\sPlayer\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define PLAYER_FROM_VRCPLAYER 0x1EF59D0

// internal\sstatic\sPlayer\s\w+\(\)\s{\s} ( class Player : MonoBehaviour )
#define PLAYERCURRENTUSER 0x20A65B0

// public override string ToString() { } ( class Player : MonoBehaviour )
#define PLAYERTOSTRING 0x20A5CB0

// public string get_id() { } ( ApiModel : ApiCacheObject )
#define GETID 0x430E80

// public static bool GoToRoom(string roomID) { }
#define GOTOROOM 0x1495100

// public int get_playerId() { }
#define GETPLAYERID 0x14997A0

// public static float get_deltaTime() { }
#define DELTATIME 0x18CB8F0

// public Transform Find(string
#define TRANSFORM_FIND 0x18CD6C0

// public void SetParent(Transform
#define TRANSFORM_SETPARENT 0x18CF7A0

// public void SetRunSpeed(float speed = 4) { }
#define SETRUNSPEED 0x14988D0

// public void TeleportTo(Vector3 teleportPos, Quaternion teleportRot) { }
#define TELEPORTTO 0x1498C80

// public void SetWalkSpeed(float speed = 2) { }
#define SETWALKSPEED 0x1498B60

// private static bool GetKeyDownString(string name) { }
#define GETKEYDOWNSTRING 0x19FF8F0

// public static Color get_cyan() { }
#define GETCYAN 0x180B790

// public static Color get_red() { }
#define GETRED 0x180BA10

// public void SetNamePlateColor(Color col) { }
#define SETNAMEPLATECOLOR 0x1498700

// public void SetMuteStatus(bool canSpeak, bool canHear) { }
#define SETMUTESTATUS 0x14A24C0

// public void SetActive(bool value) { }
#define SETACTIVE 0x19FA9F0

// public void set_interactable(bool value) { } ( public class Selectable )
#define SETINTERACTABLE 0x17CD1A0

// public virtual void set_color(Color value) { }
#define SETCOLOR 0x16E5F80

// public void SetJumpImpulse(float impulse = 3) { }
#define SETJUMPIMPULSE 0x1498670

// public\sulong\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define GETSTEAMID 0x1EF9800

// public\sstatic\sVRCUiPopupManager\s\w+\(\)\s{\s} ( VRCUiPopupManager : MonoBehaviour )
#define VRCUIPOPUPMANAGER 0x2871470

// public\svoid\s\w+\(string\s\w+,\sstring\s\w+,\sfloat\s\w+\s=\s10\)\s{\s} ( VRCUiPopupManager : MonoBehaviour )
#define SHOWALERT 0x2873FA0

// public\sstatic\sstring\s\w+\(APIUser\s\w+\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define SOCIALMENURANK 0x1EF7BC0

// public GameObject get_gameObject() { } ( Component : Object )
#define GETGAMEOBJECT 0x180C980

// private void Update() { } ( VRCHandGrasper : MonoBehaviour )
#define VRCHANDGRASPER 0x1F996B0

// public static int ToInt32(byte[] buffer, int index) { } ( static class ProperBitConverter )
#define TOINT32 0x1541E40

// public void set_localPosition(Vector3 value) { } ( class Transform : Component )
#define SETLOCALPOSITION 0x18D18D0

// public Transform get_transform() { } ( Component : Object )
#define GETTRANSFORM_COMPONENT 0x180CA50

// public Transform get_transform() { } ( GameObject : Object )
#define GETTRANSFORM_GAMEOBJECT 0x19FB090

// public void set_localScale(Vector3 value) { } ( Transform : Component )
#define SETLOCALSCALE 0x18D1A90

// ReceiveVoteToKickInitiation
#define VOTEKICKINIT 0x2032BE0

// public Component GetComponent(string type) { } ( Component : Object )
#define GETCOMPONENT_COMPONENT 0x180C4B0

// public static Object Instantiate(Object original) { } ( public class Object )
#define INSTANTIATE1 0x1A37B80

// public static Object Instantiate(Object original, Transform parent, bool instantiateInWorldSpace) { } ( public class Object )
#define INSTANTIATE2 0x1A37D00

// public string get_name() { } ( public class Object )
#define GETOBJECTNAME 0x1A38740

// public\sstatic\sVRCUiManager\s\w+\(\)\s{\s} ( VRCUiManager : MonoBehaviour )
#define VRCUIMANAGER 0x23271D0

// public\svoid\s\w+\(string\s\w+\)\s{\s} ( VRCUiManager : MonoBehaviour )
#define HUDMSG 0x2325810

// public\sstatic\sQuickMenu\s\w+\(\)\s{\s} ( QuickMenu : MonoBehaviour )
#define QUICKMENU 0x1F56240

// public\sVRCPlayerApi\s\w+\(\)\s{\s} ( class Player : MonoBehaviour )
#define GETVRCPLAYERAPI 0x4F4EA0

// public static void Destroy(Object obj, float t) { } ( public class Object )
#define DESTROY 0x1A37540

// public Vector3 GetPosition() { } ( public class VRCPlayerApi )
#define GETPLAYERPOSITION 0x1497B20

// public Quaternion GetRotation() { } ( public class VRCPlayerApi )
#define GETPLAYERROTATION 0x1497BC0

// public static Type GetType(string typeName) { } ( public abstract class Type : MemberInfo )
#define GETTYPE 0x186C500

// public virtual Type[] GetTypes() { } ( public class Assembly : ICustomAttributeProvider )
#define GETTYPES 0x3529E30

// public override string ToString() { } ( public abstract class Type : MemberInfo )
#define TYPETOSTRING 0x186D7E0

// public string get_name() { } ( public class ApiAvatar : ApiModel )
#define APIAVATARNAME 0x42E620

// public string get_name() { } ( public class ApiWorld : ApiModel )
#define APIWORLDNAME 0x42E620

// public ApiWorldInstance.AccessType GetAccessType() { } ( public class ApiWorldInstance )
#define GETACCESSTYPE 0x12827A0

// public string get_authorName() { } ( public class ApiAvatar : ApiModel )
#define AUTHORNAME 0x440DD0

// public T GetComponentInChildren() { } ( public class Component : Object )
#define COMPONENTINCHILDREN 0x21161B0

// public void .ctor(object object, IntPtr method) { } ( public sealed class UnityAction : MulticastDelegate )
#define UNITYACTIONCTOR 0x509060

// public string get_currentAvatarAssetUrl() { } ( public class APIUser : ApiModel )
#define VRCAURL 0x440CC0

// public void set_name(string value) { } ( Instantiate failed because the clone was destroyed during creation. This can happen )
#define OBJECTSETNAME 0x1A389E0

// public Vector3 get_localPosition() { } ( public class Transform : Component )
#define GETLOCALPOS 0x18D0A90

// public Transform GetChild(int index) { } ( public class Transform : Component )
#define GETCHILD 0x18CD860

// public int get_childCount() { } ( public class Transform : Component )
#define GETCHILDCOUNT 0x18D05D0

// public void SetParent(Transform parent, bool worldPositionStays) { } ( public class Transform : Component )
#define SETPARENTBOOL 0x18CF720

// public\sApiAvatar\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define GETAPIAVATAR 0x1EF81B0

// public string get_assetUrl() { } ( public class ApiAvatar : ApiModel )
#define GETASSETURL 0x5A1B20

// static string get_deviceUniqueIdentifier ( public sealed class SystemInfo // )
#define GETHWID 0x18C7360

// public static Object[] FindObjectsOfTypeAll(Type type) { } ( public sealed class Resources )
#define FINDOBJECTSOFTYPEALL 0x18BF2A0

// public static bool get_isFocused() { } ( class Application // )
#define ISFOCUSED 0x17FE770

// static GameObject CreatePrimitive(PrimitiveType ( class GameObject : Object )
#define CREATEPRIMITIVE 0x19F9DA0

// Component GetComponent(string type) { } ( class GameObject : Object )
#define GETCOMPONENT_GAMEOBJECT 0x19F9F10

// public void set_position(Vector3 value) { } ( Transform : Component )
#define SETPOSITION_TRANSFORM 0x18D1C40

// public Vector3 get_position() { } ( Transform : Component )
#define GETPOSITION_TRANSFORM 0x18D0FA0

// public void set_enabled(bool value) { } ( public class Renderer : Component )
#define SETENABLED_RENDERER 0x1A4D900

// public void .ctor() { } ( class ArrayList : IList )
#define ARRAYLIST_CTOR 0x1840AF0

// public virtual int Add(object value) { } ( class ArrayList : IList )
#define ARRAYLIST_ADD 0x183F5F0

// public virtual object[] ToArray() { } ( class ArrayList : IList )
#define ARRAYLIST_TOARRAY 0x18407D0

// public Button.ButtonClickedEvent get_onClick() { } ( class Button : Selectable )
#define GETONCLICK 0x1425DC0

// public void set_onClick(Button.ButtonClickedEvent value) { } ( class Button : Selectable )
#define SETONCLICK 0xABC6A0

// void .ctor() ( public class Button.ButtonClickedEvent : UnityEvent )
#define BUTTONCLICKCTOR 0x1425B30

// public static void RPC(RPC.Destination targetClients, GameObject targetObject, string methodName, object[] parameters) { } ( public static class Networking )
#define NETWORKING_RPC 0x14955C0

// public static GameObject Instantiate(VRC_EventHandler.VrcBroadcastType broadcast, string prefabPathOrDynamicPrefabName, Vector3 position, Quaternion rotation) { } ( public static class Networking )
#define NETWORKING_INSTANTIATE 0x14951B0

// public static Type GetType(string typeName, bool throwOnError, bool ignoreCase) { } ( abstract class Type : MemberInfo )
#define GETTYPE_TYPE_BOOL_BOOL 0x186C2A0

// public void AddListener(UnityAction call) { } ( public class UnityEvent : UnityEventBase )
#define ADDLISTENER 0x1815DA0

// public virtual void set_text(string value) { } ( public class Text : MaskableGraphic )
#define SET_TEXT 0x17D2AF0

// public static Camera get_main() { } ( public sealed class Camera : Behaviour )
#define CAMERA_GET_MAIN 0x1807850

// public void set_enabled(bool value) { } ( public class Collider : Component )
#define SETENABLED_COLLIDER 0x1E4D950

// public Component GetComponent(Type type) { } ( public class Component : Object )
#define GETCOMPONENT_TYPE_TYPE 0x180C430

// public Component AddComponent(Type componentType) { } ( public sealed class GameObject : Object )
#define ADDCOMPONENT 0x19F9BD0

// public bool get_activeSelf() { } ( public sealed class GameObject : Object )
#define GET_ACTIVESELF 0x19FAD60

// public static GameObject Find(string name) { } ( public sealed class GameObject : Object )
#define GAMEOBJECT_FIND 0x19F9EB0

// public Component GetComponent(Type type) { } ( public sealed class GameObject : Object )
#define GAMEOBJECT_GETCOMPONENT 0x19FA160

// public static bool GetKey(KeyCode key) { } ( public class Input // )
#define GETKEYPRESSED 0x19FF950

// public static float GetAxis(string axisName) { } ( public class Input // )
#define INPUT_GETAXIS 0x19FF6D0

// public Vector3 get_forward() { } ( public class Transform : Component )
#define GET_FORWARD 0x18D06E0

// public Vector3 get_right() { } ( public class Transform : Component )
#define GET_RIGHT 0x18D1030

// public Vector3 get_up() { } ( public class Transform : Component )
#define GET_UP 0x18D1290

// public static void SendRequest(string endpoint, HTTPMethods method, ApiContainer responseContainer, Dictionary<string, object> requestParams, bool authenticationRequired = True, bool disableCache = False, float cacheLifetime = 3600, int retryCount = 2, API.CredentialsBundle credentials) ( public static class API // )
#define SENDREQUEST 0xC49520

// private\svoid\s\w+\(bool\s\w+\s=\sFalse\) ( public class ModerationManager : MonoBehaviour )
#define KICKPATCH1 0x203C9D0

// public static string ToHtmlStringRGB(Color color) { } ( ColorUtility )
#define TOHTMLSTRINGRGB 0x180A9D0

// public static Color HSVToRGB(float H, float S, float V) { } ( struct Color : IEquatable )
#define HSVTORGB 0x180AF90

// public\sColor\s\w+\(\) ( VRCUiShadowPlate : MonoBehaviour )
#define UISHADOWPLATECOLOR 0x232A0F0

// public void .ctor() { } ( class ApiAvatar : ApiModel )
#define APIAVATARCTOR 0xC4BCD0

// public void set_id(string value) { } ( class ApiModel : ApiCacheObject )
#define APIMODELSETID 0x430E90

// public void ChangeToSelectedAvatar() { } ( class PageAvatar : VRCUiPage )
#define CHANGETOSELECTEDAVATAR 0x2091B80

// public Sprite get_sprite() { } ( Image : MaskableGraphic )
#define GETSPRITEIMAGE 0x16EFF60

// public void set_sprite(Sprite value) { } ( Image : MaskableGraphic )
#define SETSPRITEIMAGE 0x16F0300

// public override Material get_material() { } ( Image : MaskableGraphic )
#define GETMATERIALIMAGE 0x16EF9A0

// public override void set_material(Material value) { } ( Image : MaskableGraphic )
#define SETMATERIALIMAGE 0x16E5FD0

// public virtual Color get_color() { } ( abstract class Graphic : UIBehaviour )
#define GRAPHICGETCOLOR 0x1428A50

// public Transform GetBoneTransform(HumanBodyBones humanBoneId) { } ( class Animator : Behaviour )
#define GETBONETRANSFORM 0x1DFCCE0

// public void SetColor(string name, Color value) { } ( class Material : Object )
#define SETCOLOR_MATERIAL 0x1A0BB10

// public static float get_time() { } ( public class Time // )
#define GETTIME_FROMTIME 0x18CBD00

// private\svoid\s\w+\(VRC_EventHandler.VrcBroadcastType\s\w+,\sint\s\w+,\sVRC_EventHandler.VrcTargetType\s\w+,\sGameObject\s\w+ ( class VRC_EventDispatcherRFC : VRC_EventDispatcher )
#define RPCDISPATCHER 0x1FFDE70

// public\sbool\s\w+\(ApiAvatar\s\w+,\sstring\s\w+,\sfloat\s\w+\s=\s1,\sVRCAvatarManager.\w+\s\w+\) ( class VRCAvatarManager : MonoBehaviour )
#define SWITCHAVATARRPC 0x1F25040

// public override void TriggerEvent(VRC_EventHandler ( class VRC_EventDispatcherRFC : VRC_EventDispatcher )
#define ANTIWORLDTRIGGERS 0x1FFA5C0

