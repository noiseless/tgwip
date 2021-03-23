--- Telegram/SourceFiles/platform/linux/specific_linux.cpp.orig	Mon Mar 22 05:05:32 2021
+++ Telegram/SourceFiles/platform/linux/specific_linux.cpp	Mon Mar 22 23:23:24 2021
@@ -754,10 +754,12 @@
 
 void RegisterCustomScheme(bool force) {
 	try {
+#ifndef DESKTOP_APP_DISABLE_DBUS_INTEGRATION
 		if (InSnap()) {
 			SnapDefaultHandler(qsl("tg"));
 			return;
 		}
+#endif
 
 		if (cExeName().isEmpty()) {
 			return;
