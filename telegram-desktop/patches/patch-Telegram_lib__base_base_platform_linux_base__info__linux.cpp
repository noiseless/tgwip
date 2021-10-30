--- Telegram/lib_base/base/platform/linux/base_info_linux.cpp.orig	Fri Oct 29 16:26:14 2021
+++ Telegram/lib_base/base/platform/linux/base_info_linux.cpp	Sat Oct 30 04:17:21 2021
@@ -19,9 +19,11 @@
 
 #include <sys/utsname.h>
 
+#if !defined(__OpenBSD__)
 #ifdef Q_OS_LINUX
 #include <gnu/libc-version.h>
 #endif // Q_OS_LINUX
+#endif // !OpenBSD
 
 namespace Platform {
 namespace {
@@ -199,9 +201,11 @@
 }
 
 QString GetLibcName() {
+#if !defined(__OpenBSD__)
 #ifdef Q_OS_LINUX
 	return "glibc";
 #endif // Q_OS_LINUX
+#endif // !OpenBSD
 
 	return QString();
 }
