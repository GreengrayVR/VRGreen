#pragma once

// public static void SendPutRequest(string target, ApiContainer responseContainer, Dictionary<string, object> requestParams, API.CredentialsBundle credentials) { }
#define OFFLINE_MODE 0x4D25E0

// public int get_RoundTripTime() { }
#define FAKE_PING 0xABDDF0

// private void InternalTriggerEvent(VRC_EventHandler.VrcEvent e, VRC_EventHandler.VrcBroadcastType broadcast, int instagatorId, float fastForward) { }
#define WORLD_TRIGGERS 0x84C3B0

// private void ConfigurePortal(string
#define CONFIGURE_PORTAL 0x2064870

// private void WarnUserRPC(string
#define WARNUSERRPC 0x1AD5A20

// private void KickUserRPC(string
#define KICKUSERRPC 0x1AC3070

// private void BlockStateChangeRPC
#define BLOCKSTATECHANGERPC 0x1AC2CC0

// private void OnTriggerEnter ( PortalTrigger : MonoBehaviour )
#define ANTI_PORTAL 0x2C2B110

// public List<Action>
#define RECEIVEAUDIO 0x1CE8F70

// public static string get_DeviceID() { }
#define DEVICEID 0x4D33E0

// ForceLogoutRPC
#define FORCELOGOUTRPC 0x1AC2DB0

// FriendStateChangeRPC
#define FRIENDSTATECHANGERPC 0x1AC2F50

// BanPublicOnlyRPC
#define BANPUBLICONLYRPC 0x1AC2730

// ResetShowUserAvatarToDefaultRPC
#define RESETSHOWUSERAVATARTODEFAULTRPC 0x1AC4580

// ModMicGainChangeRPC
#define MODMICGAINCHANGERPC 0x1AC35D0

// BanRPC
#define BANRPC 0x1AC2A30

// MuteChangeRPC
#define MUTECHANGERPC 0x1AC3800

// ModForceOffMicRPC
#define MODFORCEOFFMICRPC 0x1AC3410

// ShowUserAvatarChangedRPC
#define SHOWUSERAVATARCHANGERPC 0x1AC4660

// SpawnEmojiRPC
#define SPAWNEMOJIRPC 0x18553A0

// ShowSocialRankRPC
#define SHOWSOCIALRANKRPC 0x1855260

// GotoRoomTargetUserRPC
#define GOTOROOMTARGETUSERRPC 0x1854B70

// PlayEmoteRPC
#define PLAYEMOTERPC 0x1855030

// GotoRoomRPC
#define GOTOROOMRPC 0x18549B0

// private void _DestroyObject(int 
#define _DESTROYOBJECT 0x1BFF100

// public static bool IsFriendsWith(string userId) { }
#define ISFRIENDSWITH 0x4CC280

// public bool HasTag(string tag) { } ( APIUser : ApiModel )
#define HASTAG 0x4CBD50

// public static APIUser get_CurrentUser() { }
#define CURRENTUSER 0x4CF7D0

// public string get_displayName() { } ( APIUser : ApiModel )
#define DISPLAYNAME 0x39CEA0

// public\soverride\svoid\s\w+\(float ( VRCPlayer : VRCNetworkBehaviour )
#define VRCPLAYERCUSTOMPLATES 0x1857B90

// public void Update() { } ( UserInteractMenu : MonoBehaviour )
#define USERINTERACTMENU 0x238EBB0

// public\sPlayer\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define PLAYER_FROM_VRCPLAYER 0x18564C0

// internal\sstatic\sPlayer\s\w+\(\)\s{\s} ( class Player : MonoBehaviour )
#define PLAYERCURRENTUSER 0x1B90FD0

// public override string ToString() { } ( class Player : MonoBehaviour )
#define PLAYERTOSTRING 0x1B90740

// public string get_id() { } ( ApiModel : ApiCacheObject )
#define GETID 0x37B130

// public static bool GoToRoom(string roomID) { }
#define GOTOROOM 0x845740

// public int get_playerId() { }
#define GETPLAYERID 0x849DE0

// public static float get_deltaTime() { }
#define DELTATIME 0xD61D50

// public Transform Find(string
#define TRANSFORM_FIND 0xD63B20

// public void SetParent(Transform
#define TRANSFORM_SETPARENT 0xD65C00

// public void SetRunSpeed(float speed = 4) { }
#define SETRUNSPEED 0x848F10

// public void TeleportTo(Vector3 teleportPos, Quaternion teleportRot) { }
#define TELEPORTTO 0x8492C0

// public void SetWalkSpeed(float speed = 2) { }
#define SETWALKSPEED 0x8491A0

// private static bool GetKeyDownString(string name) { }
#define GETKEYDOWNSTRING 0xF68450

// public static Color get_cyan() { }
#define GETCYAN 0x2F12CA0

// public static Color get_red() { }
#define GETRED 0x2F12F20

// public void SetNamePlateColor(Color col) { }
#define SETNAMEPLATECOLOR 0x848D40

// public void SetMuteStatus(bool canSpeak, bool canHear) { }
#define SETMUTESTATUS 0x852B00

// public void SetActive(bool value) { }
#define SETACTIVE 0xF63540

// public void set_interactable(bool value) { } ( public class Selectable )
#define SETINTERACTABLE 0xC0A890

// public virtual void set_color(Color value) { }
#define SETCOLOR 0xAE5310

// public void SetJumpImpulse(float impulse = 3) { }
#define SETJUMPIMPULSE 0x848CB0

// public\sulong\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define GETSTEAMID 0x185CF80

// public\sstatic\sVRCUiPopupManager\s\w+\(\)\s{\s} ( VRCUiPopupManager : MonoBehaviour )
#define VRCUIPOPUPMANAGER 0x2333F50

// public\svoid\s\w+\(string\s\w+,\sstring\s\w+,\sfloat\s\w+\s=\s10\)\s{\s} ( VRCUiPopupManager : MonoBehaviour )
#define SHOWALERT 0x23352E0

// public\sstatic\sstring\s\w+\(APIUser\s\w+\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define SOCIALMENURANK 0x1859E10

// public GameObject get_gameObject() { } ( Component : Object )
#define GETGAMEOBJECT 0x2F13C70

// private void Update() { } ( VRCHandGrasper : MonoBehaviour )
#define VRCHANDGRASPER 0x1B1C430

// public static int ToInt32(byte[] buffer, int index) { } ( static class ProperBitConverter )
#define TOINT32 0x8F2470

// public void set_localPosition(Vector3 value) { } ( class Transform : Component )
#define SETLOCALPOSITION 0xD67D30

// public Transform get_transform() { } ( Component : Object )
#define GETTRANSFORM_COMPONENT 0x2F13D40

// public Transform get_transform() { } ( GameObject : Object )
#define GETTRANSFORM_GAMEOBJECT 0xF63BE0

// public void set_localScale(Vector3 value) { } ( Transform : Component )
#define SETLOCALSCALE 0xD67EF0

// ReceiveVoteToKickInitiation
#define VOTEKICKINIT 0x1AC3A20

// public Component GetComponent(string type) { } ( Component : Object )
#define GETCOMPONENT_COMPONENT 0x2F137A0

// public static Object Instantiate(Object original) { } ( public class Object )
#define INSTANTIATE1 0xFB8470

// public static Object Instantiate(Object original, Transform parent, bool instantiateInWorldSpace) { } ( public class Object )
#define INSTANTIATE2 0xFB85F0

// public string get_name() { } ( public class Object )
#define GETOBJECTNAME 0xFB9030

// public\sstatic\sVRCUiManager\s\w+\(\)\s{\s} ( VRCUiManager : MonoBehaviour )
#define VRCUIMANAGER 0x1C7FA10

// public\svoid\s\w+\(string\s\w+\)\s{\s} ( VRCUiManager : MonoBehaviour )
#define HUDMSG 0x1C80250

// public\sstatic\sQuickMenu\s\w+\(\)\s{\s} ( QuickMenu : MonoBehaviour )
#define QUICKMENU 0x188B030

// public\sVRCPlayerApi\s\w+\(\)\s{\s} ( class Player : MonoBehaviour )
#define GETVRCPLAYERAPI 0x3AF0D0

// public static void Destroy(Object obj, float t) { } ( public class Object )
#define DESTROY 0xFB7E30

// public Vector3 GetPosition() { } ( public class VRCPlayerApi )
#define GETPLAYERPOSITION 0x848160

// public Quaternion GetRotation() { } ( public class VRCPlayerApi )
#define GETPLAYERROTATION 0x848200

// public static Type GetType(string typeName) { } ( public abstract class Type : MemberInfo )
#define GETTYPE 0xD83FD0

// public virtual Type[] GetTypes() { } ( public class Assembly : ICustomAttributeProvider )
#define GETTYPES 0xD25B70

// public override string ToString() { } ( public abstract class Type : MemberInfo )
#define TYPETOSTRING 0xD852B0

// public string get_name() { } ( public class ApiAvatar : ApiModel )
#define APIAVATARNAME 0x3788C0

// public string get_name() { } ( public class ApiWorld : ApiModel )
#define APIWORLDNAME 0x3788C0

// public ApiWorldInstance.AccessType GetAccessType() { } ( public class ApiWorldInstance )
#define GETACCESSTYPE 0x708B90

// public string get_authorName() { } ( public class ApiAvatar : ApiModel )
#define AUTHORNAME 0x38B080

// public T GetComponentInChildren() { } ( public class Component : Object )
#define COMPONENTINCHILDREN 0x1BC6770

// public void .ctor(object object, IntPtr method) { } ( public sealed class UnityAction : MulticastDelegate )
#define UNITYACTIONCTOR 0x3C3290

// public string get_currentAvatarAssetUrl() { } ( public class APIUser : ApiModel )
#define VRCAURL 0x38AF70

// public void set_name(string value) { } ( Instantiate failed because the clone was destroyed during creation. This can happen )
#define OBJECTSETNAME 0xFB92D0

// public Vector3 get_localPosition() { } ( public class Transform : Component )
#define GETLOCALPOS 0xD66EF0

// public Transform GetChild(int index) { } ( public class Transform : Component )
#define GETCHILD 0xD63CC0

// public int get_childCount() { } ( public class Transform : Component )
#define GETCHILDCOUNT 0xD66A30

// public void SetParent(Transform parent, bool worldPositionStays) { } ( public class Transform : Component )
#define SETPARENTBOOL 0xD65B80

// public\sApiAvatar\s\w+\(\)\s{\s} ( VRCPlayer : VRCNetworkBehaviour )
#define GETAPIAVATAR 0x185EE70

// public string get_assetUrl() { } ( public class ApiAvatar : ApiModel )
#define GETASSETURL 0x3F15A0

// static string get_deviceUniqueIdentifier ( public sealed class SystemInfo // )
#define GETHWID 0xD5D810

// public static Object[] FindObjectsOfTypeAll(Type type) { } ( public sealed class Resources )
#define FINDOBJECTSOFTYPEALL 0xD55750

// public static bool get_isFocused() { } ( class Application // )
#define ISFOCUSED 0x2F05E10

// static GameObject CreatePrimitive(PrimitiveType ( class GameObject : Object )
#define CREATEPRIMITIVE 0xF628F0

// Component GetComponent(string type) { } ( class GameObject : Object )
#define GETCOMPONENT_GAMEOBJECT 0xF62A60

// public void set_position(Vector3 value) { } ( Transform : Component )
#define SETPOSITION_TRANSFORM 0xD680A0

// public Vector3 get_position() { } ( Transform : Component )
#define GETPOSITION_TRANSFORM 0xD67400

// public void set_enabled(bool value) { } ( public class Renderer : Component )
#define SETENABLED_RENDERER 0xFCE260

// public void .ctor() { } ( class ArrayList : IList )
#define ARRAYLIST_CTOR 0xCA4670

// public virtual int Add(object value) { } ( class ArrayList : IList )
#define ARRAYLIST_ADD 0xCA3170

// public virtual object[] ToArray() { } ( class ArrayList : IList )
#define ARRAYLIST_TOARRAY 0xCA4350

// public Button.ButtonClickedEvent get_onClick() { } ( class Button : Selectable )
#define GETONCLICK 0x7FA550

// public void set_onClick(Button.ButtonClickedEvent value) { } ( class Button : Selectable )
#define SETONCLICK 0x4A1D10

// void .ctor() ( public class Button.ButtonClickedEvent : UnityEvent )
#define BUTTONCLICKCTOR 0x7FA2C0

// public static void RPC(RPC.Destination targetClients, GameObject targetObject, string methodName, object[] parameters) { } ( public static class Networking )
#define NETWORKING_RPC 0x845C00

// public static GameObject Instantiate(VRC_EventHandler.VrcBroadcastType broadcast, string prefabPathOrDynamicPrefabName, Vector3 position, Quaternion rotation) { } ( public static class Networking )
#define NETWORKING_INSTANTIATE 0x8457F0

// public static Type GetType(string typeName, bool throwOnError, bool ignoreCase) { } ( abstract class Type : MemberInfo )
#define GETTYPE_TYPE_BOOL_BOOL 0xD83D70

// public void AddListener(UnityAction call) { } ( public class UnityEvent : UnityEventBase )
#define ADDLISTENER 0x2F1CCC0

// public virtual void set_text(string value) { } ( public class Text : MaskableGraphic )
#define SET_TEXT 0xC101E0

// public static Camera get_main() { } ( public sealed class Camera : Behaviour )
#define CAMERA_GET_MAIN 0x2F0EE70

// public void set_enabled(bool value) { } ( public class Collider : Component )
#define SETENABLED_COLLIDER 0x17A3970

// public Component GetComponent(Type type) { } ( public class Component : Object )
#define GETCOMPONENT_TYPE_TYPE 0x2F13720

// public Component AddComponent(Type componentType) { } ( public sealed class GameObject : Object )
#define ADDCOMPONENT 0xF62720

// public bool get_activeSelf() { } ( public sealed class GameObject : Object )
#define GET_ACTIVESELF 0xF638B0

// public static GameObject Find(string name) { } ( public sealed class GameObject : Object )
#define GAMEOBJECT_FIND 0xF62A00

// public Component GetComponent(Type type) { } ( public sealed class GameObject : Object )
#define GAMEOBJECT_GETCOMPONENT 0xF62CB0

// public static bool GetKey(KeyCode key) { } ( public class Input // )
#define GETKEYPRESSED 0xF684B0

// public static float GetAxis(string axisName) { } ( public class Input // )
#define INPUT_GETAXIS 0xF68230

// public Vector3 get_forward() { } ( public class Transform : Component )
#define GET_FORWARD 0xD66B40

// public Vector3 get_right() { } ( public class Transform : Component )
#define GET_RIGHT 0xD67490

// public Vector3 get_up() { } ( public class Transform : Component )
#define GET_UP 0xD676F0

// public static void SendRequest(string endpoint, HTTPMethods method, ApiContainer responseContainer, Dictionary<string, object> requestParams, bool authenticationRequired = True, bool disableCache = False, float cacheLifetime = 3600, int retryCount = 2, API.CredentialsBundle credentials) ( public static class API // )
#define SENDREQUEST 0x4D2AD0

// private\svoid\s\w+\(bool\s\w+\s=\sFalse\) ( public class ModerationManager : MonoBehaviour )
#define KICKPATCH1 0x1AD3FD0

// public static string ToHtmlStringRGB(Color color) { } ( ColorUtility )
#define TOHTMLSTRINGRGB 0x2F11FF0

// public static Color HSVToRGB(float H, float S, float V) { } ( struct Color : IEquatable )
#define HSVTORGB 0x2F12530

// public\sColor\s\w+\(\) ( VRCUiShadowPlate : MonoBehaviour )
#define UISHADOWPLATECOLOR 0x1C80EE0

// public void .ctor() { } ( class ApiAvatar : ApiModel )
#define APIAVATARCTOR 0x4D5280

// public void set_id(string value) { } ( class ApiModel : ApiCacheObject )
#define APIMODELSETID 0x37B140

// public void ChangeToSelectedAvatar() { } ( class PageAvatar : VRCUiPage )
#define CHANGETOSELECTEDAVATAR 0x18BAA00

// public Sprite get_sprite() { } ( Image : MaskableGraphic )
#define GETSPRITEIMAGE 0xAEF2F0

// public void set_sprite(Sprite value) { } ( Image : MaskableGraphic )
#define SETSPRITEIMAGE 0xAEF690

// public override Material get_material() { } ( Image : MaskableGraphic )
#define GETMATERIALIMAGE 0xAEED30

// public override void set_material(Material value) { } ( Image : MaskableGraphic )
#define SETMATERIALIMAGE 0xAE5360

// public virtual Color get_color() { } ( abstract class Graphic : UIBehaviour )
#define GRAPHICGETCOLOR 0x7FD1E0

// public Transform GetBoneTransform(HumanBodyBones humanBoneId) { } ( class Animator : Behaviour )
#define GETBONETRANSFORM 0x1764EE0

// public void SetColor(string name, Color value) { } ( class Material : Object )
#define SETCOLOR_MATERIAL 0xF74670

// public static float get_time() { } ( public class Time // )
#define GETTIME_FROMTIME 0xD62160

// private\svoid\s\w+\(VRC_EventHandler.VrcBroadcastType\s\w+,\sint\s\w+,\sVRC_EventHandler.VrcTargetType\s\w+,\sGameObject\s\w+ ( class VRC_EventDispatcherRFC : VRC_EventDispatcher )
//#define RPCDISPATCHER None

// public\sbool\s\w+\(ApiAvatar\s\w+,\sstring\s\w+,\sfloat\s\w+\s=\s1,\sVRCAvatarManager.\w+\s\w+\) ( class VRCAvatarManager : MonoBehaviour )
#define SWITCHAVATARRPC 0x18733F0

// public override void TriggerEvent(VRC_EventHandler ( class VRC_EventDispatcherRFC : VRC_EventDispatcher )
#define ANTIWORLDTRIGGERS 0x19D8410

// public Component GetComponentInChildren(Type type) { } ( public sealed class GameObject : Object )
#define GETCOMPONENTINCHILDREN_GAMEOBJECT 0xF62BD0

// public static object[] xxx(byte[] xxx) { } ( internal static class )
#define RPCS_INTERNAL_FUNC 0x32059C0

// private bool xxx(Player xxx, string xxx) { } ( class ObjectInstantiator : MonoBehaviour )
#define OBJECTINSTANTIATION_RPC 0x1BFB970

// public virtual void OnEvent(EventData xxx) { } ( public class )
#define ONEVENTPATCH 0x1AD8B60

// public void xxx(VRCPlayer xxx) { } ( class QuickMenu : MonoBehaviour )
#define SELECTYOURSELF2 0x188AC70

// public static ModerationManager xxx() { } ( public class ModerationManager : MonoBehaviour )
#define MODERATIONMANAGER_INSTANCE 0x1ACF240

// public virtual string get_text() { } ( class Text : MaskableGraphic )
#define GET_UI_TEXT 0xC0FBC0

// public MethodInfo[] GetMethods() { } ( public abstract class Type : MemberInfo )
#define TYPE_GETMETHODS 0xD834D0

// public Type GetType() { } ( public abstract class Type : MemberInfo )
#define TYPE_GETTYPE 0x897430

// public static Type GetType(string typeName) { } ( public abstract class Type : MemberInfo )
#define TYPE_GETTYPE_WITHNAME 0xD83FD0

// public Type GetType() { } ( public class Object // )
#define OBJECT_GETTYPE 0x2ACF6E0

// public virtual string ToString() { } ( public class Object // )
#define OBJECT_TOSTRING 0x2ACF700

// public MethodInfo GetMethod(string name) { } ( public abstract class Type : MemberInfo )
#define TYPE_GETMETHOD 0xD83420

// public ConstructorInfo GetConstructor(Type[] types) { } ( class )
#define GETCONSTRUCTORINFO 0xD81F10

// public object Invoke(object obj, object[] parameters) { } ( public abstract class MethodBase : MemberInfo )
#define METHODBASE_INVOKE 0xD2C440

// public virtual string get_Name() { } ( public class ParameterInfo : ICustomAttributeProvider )
#define PARAMAETERINFO_GETNAME 0x3788A0

// public object Invoke(object[] parameters) { } ( public abstract class ConstructorInfo : MethodBase )
#define CONSTRUCTORINFO_INVOKE 0xD26620

// public Component GetComponentInChildren(Type t) { } ( public class Component : Object )
#define COMPONENT_GETCOMPONENTINCHILDREN_TYPE_T 0x2F13590

// public Vector3 get_localScale() { } ( public class Transform : Component )
#define TRANSFORM_GETLOCALSCALE 0xD670E0

