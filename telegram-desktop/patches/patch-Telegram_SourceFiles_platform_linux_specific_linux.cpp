--- Telegram/SourceFiles/platform/linux/specific_linux.cpp.orig	Sun Sep 12 07:41:40 2021
+++ Telegram/SourceFiles/platform/linux/specific_linux.cpp	Sun Sep 12 07:46:53 2021
@@ -46,7 +46,6 @@
 #include <QtGui/QWindow>
 
 #include <private/qguiapplication_p.h>
-#include <jemalloc/jemalloc.h>
 
 #ifndef DESKTOP_APP_DISABLE_DBUS_INTEGRATION
 #include <glibmm.h>
@@ -650,9 +649,6 @@
 namespace Platform {
 
 void start() {
-	auto backgroundThread = true;
-	mallctl("background_thread", nullptr, nullptr, &backgroundThread, sizeof(bool));
-
 	// Prevent any later calls into setlocale() by Qt
 	QCoreApplicationPrivate::initLocale();
 
