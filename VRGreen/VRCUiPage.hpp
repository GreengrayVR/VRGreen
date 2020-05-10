#pragma once

#include <string>

struct VRCUiPage
{
	static VRCUiPage* GetPage(std::string path);
};

//
//inline void ShowQuickmenuPage(std::string pagename)
//{
//    IL2CPP::FieldInfo* currentPageGetter;
//    QuickMenu* quickMenuInstance = QuickMenuInstance();
//    
//    Transform* transform = (quickMenuInstance != nullptr) ? Find(get_transform(quickMenuInstance), pagename) : nullptr;
//    if (transform == nullptr)
//    {
//        ConsoleUtils::Log("[QuickMenuUtils] pageTransform is null !");
//    }
//    if (currentPageGetter == nullptr)
//    {
//        if (currentPageGetter == nullptr)
//        {
//            GameObject* gameObject = get_gameObject(Find(get_transform(quickMenuInstance), "ShortcutMenu"));
//
//
//            FieldInfo[] array = (from fi in typeof(QuickMenu).GetFields(BindingFlags.Instance | BindingFlags.NonPublic)
//            where fi.FieldType == typeof(GameObject)
//                select fi).ToArray<FieldInfo>();
//            //ConsoleUtils::Log("[QuickMenuUtils] GameObject Fields in QuickMenu:");
//            int num = 0;
//            foreach(FieldInfo fieldInfo in array)
//            {
//                if (fieldInfo.GetValue(quickMenuInstance) as GameObject == gameObject && ++num == 2)
//                {
//                    //ConsoleUtils::Log("[QuickMenuUtils] currentPage field: " + fieldInfo.Name);
//                    currentPageGetter = fieldInfo;
//                    break;
//                }
//            }
//        }
//        if (currentPageGetter == nullptr)
//        {
//            GameObject gameObject = quickMenuInstance.transform.Find("UserInteractMenu").gameObject;
//            FieldInfo[] array = (from fi in typeof(QuickMenu).GetFields(BindingFlags.Instance | BindingFlags.NonPublic)
//            where fi.FieldType == typeof(GameObject)
//                select fi).ToArray<FieldInfo>();
//            //ConsoleUtils::Log("[QuickMenuUtils] GameObject Fields in QuickMenu:");
//            int num = 0;
//            foreach(FieldInfo fieldInfo in array)
//            {
//                if (fieldInfo.GetValue(quickMenuInstance) as GameObject == gameObject && ++num == 2)
//                {
//                    //ConsoleUtils::Log("[QuickMenuUtils] currentPage field: " + fieldInfo.Name);
//                    currentPageGetter = fieldInfo;
//                    break;
//                }
//            }
//        }
//
//        if (currentPageGetter == nullptr)
//        {
//            ConsoleUtils::Log("[QuickMenuUtils] Unable to find field currentPage in QuickMenu");
//            return;
//        }
//    }
//    GameObject gameObject2 = (GameObject*)currentPageGetter.GetValue(quickMenuInstance);
//    if (gameObject2 != nullptr)
//    {
//        gameObject2.SetActive(false);
//    }
//    GetQuickMenuInstance().transform.Find("QuickMenu_NewElements/_InfoBar").gameObject.SetActive(false);
//    if (quickmenuContextualDisplayGetter != nullptr)
//    {
//        quickmenuContextualDisplayGetter = typeof(QuickMenu).GetFields(BindingFlags.Instance | BindingFlags.NonPublic).FirstOrDefault((FieldInfo fi) = > fi.FieldType == typeof(QuickMenuContextualDisplay));
//    }
//    FieldInfo fieldInfo2 = quickmenuContextualDisplayGetter;
//    QuickMenuContextualDisplay quickMenuContextualDisplay = ((fieldInfo2 != nullptr) ? fieldInfo2.GetValue(quickMenuInstance) : nullptr) as QuickMenuContextualDisplay;
//    if (quickMenuContextualDisplay != nullptr)
//    {
//        currentPageGetter.SetValue(quickMenuInstance, transform.gameObject);
//        MethodBase method = typeof(QuickMenuContextualDisplay).GetMethod("SetDefaultContext", BindingFlags.Instance | BindingFlags.Public);
//        object obj = quickMenuContextualDisplay;
//        object[] array3 = new object[3];
//        array3[0] = 0;
//        method.Invoke(obj, array3);
//    }
//    currentPageGetter.SetValue(quickMenuInstance, transform.gameObject);
//    MethodBase method2 = typeof(QuickMenu).GetMethod("SetContext", BindingFlags.Instance | BindingFlags.Public);
//    object obj2 = quickMenuInstance;
//    object[] array4 = new object[3];
//    array4[0] = 1;
//    method2.Invoke(obj2, array4);
//    transform.gameObject.SetActive(true);
//}
