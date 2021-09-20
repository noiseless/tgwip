Index: Telegram/SourceFiles/platform/linux/specific_linux.cpp
--- Telegram/SourceFiles/platform/linux/specific_linux.cpp.orig
+++ Telegram/SourceFiles/platform/linux/specific_linux.cpp
@@ -47,11 +47,13 @@ https://github.com/telegramdesktop/tdesktop/blob/maste
 
 #include <private/qguiapplication_p.h>
 
+#if !defined(__OpenBSD__)
 #ifdef Q_OS_FREEBSD
 #include <malloc_np.h>
 #else // Q_OS_FREEBSD
 #include <jemalloc/jemalloc.h>
 #endif // Q_OS_FREEBSD
+#endif
 
 #ifndef DESKTOP_APP_DISABLE_DBUS_INTEGRATION
 #include <glibmm.h>
@@ -661,8 +663,10 @@ int psFixPrevious() {
 namespace Platform {
 
 void start() {
+#if !defined(__OpenBSD__)
 	auto backgroundThread = true;
 	mallctl("background_thread", nullptr, nullptr, &backgroundThread, sizeof(bool));
+#endif
 
 	// Prevent any later calls into setlocale() by Qt
 	QCoreApplicationPrivate::initLocale();
