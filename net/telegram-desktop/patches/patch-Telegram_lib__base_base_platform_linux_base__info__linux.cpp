Index: Telegram/lib_base/base/platform/linux/base_info_linux.cpp
--- Telegram/lib_base/base/platform/linux/base_info_linux.cpp.orig
+++ Telegram/lib_base/base/platform/linux/base_info_linux.cpp
@@ -22,9 +22,11 @@
 
 #include <sys/utsname.h>
 
+#if !defined(__OpenBSD__)
 #ifdef Q_OS_LINUX
 #include <gnu/libc-version.h>
 #endif // Q_OS_LINUX
+#endif // !OpenBSD
 
 namespace Platform {
 namespace {
@@ -200,9 +202,11 @@ QString AutoUpdateKey() {
 }
 
 QString GetLibcName() {
+#if !defined(__OpenBSD__)
 #ifdef Q_OS_LINUX
 	return "glibc";
 #endif // Q_OS_LINUX
+#endif // !OpenBSD
 
 	return QString();
 }
