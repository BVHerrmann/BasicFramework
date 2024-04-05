#ifndef BasicFrameworkDEFINES_H
#define BasicFrameworkDEFINES_H

#include <QString>

const QString kOrganizationName     = "Br Bildverarbeitung GmbH";
const QString kOrganizationDomain   = "br.eu";
//const QString kApplicationName      = TARGET;
//const QString kApplicationVersion   = VERSION;

const QString kVirtualKeyboard      = "BasicFramework/VirtualKeyboard";
const bool kDefaultVirtualKeyboard  = true;
const QString kCustomAppName        = "BasicFramework/ApplicationName";
const QString kAllowMachineState    = "BasicFramework/MachineStateChangeUserLevel";
const QString kLocale               = "BasicFramework/Language";
const QString kFullscreen           = "BasicFramework/FullScreen";
const QString kSystemTrayIcon		= "BasicFramework/SystemTrayIcon";
const bool kDefaultSystemTrayIcon	= false;
const bool kDefaultFullscreen       = true;
const QString kCheckPriority        = "BasicFramework/CheckPriority";
const bool kDefaultCheckPriority    = true;
const QString kHideLogo				= "BasicFramework/HideLogo";
const QString kWindowGeometry       = "BasicFramework/WindowGeometry";
const QString kWindowState          = "BasicFramework/WindowState";
const QString kLogoutTimeout        = "BasicFramework/LogoutTimeout";
const uint32_t kDefaultLogoutTimeout = 5 * 60 * 1000; // 5 min

const QString kDeviceComPort		= "BasicFramework/COM-Port";
const QString kUsers				= "BasicFramework/Users";
const QString kPassword				= "BasicFramework/PasswordLevel%1";

#endif // BasicFrameworkDEFINES_H
