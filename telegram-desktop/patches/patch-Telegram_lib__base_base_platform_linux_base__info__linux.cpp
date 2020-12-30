--- Telegram/lib_base/base/platform/linux/base_info_linux.cpp.orig	Mon Nov  2 13:34:16 2020
+++ Telegram/lib_base/base/platform/linux/base_info_linux.cpp	Tue Dec 22 06:43:55 2020
@@ -13,9 +13,11 @@
 #include <QtGui/QGuiApplication>
 
 // this file is used on both Linux & BSD
+#if !defined(__OpenBSD__)
 #ifdef Q_OS_LINUX
 #include <gnu/libc-version.h>
 #endif // Q_OS_LINUX
+#endif // !OpenBSD
 
 namespace Platform {
 namespace {
@@ -43,11 +45,15 @@
 	static const auto result = [&] {
 		QStringList resultList{};
 
+#if !defined(__OpenBSD__)
 #ifdef Q_OS_LINUX
 		resultList << "Linux";
 #else // Q_OS_LINUX
 		resultList << QSysInfo::kernelType();
-#endif // !Q_OS_LINUX
+#endif // Q_OS_LINUX
+#else // !OpenBSD
+		resultList << "OpenBSD";
+#endif // !OpenBSD
 
 		const auto desktopEnvironment = GetDesktopEnvironment();
 		if (!desktopEnvironment.isEmpty()) {
@@ -123,14 +129,17 @@
 }
 
 QString GetLibcName() {
+#if !defined(__OpenBSD__)
 #ifdef Q_OS_LINUX
 	return "glibc";
 #endif // Q_OS_LINUX
+#endif // !OpenBSD 
 
 	return QString();
 }
 
 QString GetLibcVersion() {
+#if !defined(__OpenBSD__)
 #ifdef Q_OS_LINUX
 	static const auto result = [&] {
 		const auto version = QString::fromLatin1(gnu_get_libc_version());
@@ -138,6 +147,7 @@
 	}();
 	return result;
 #endif // Q_OS_LINUX
+#endif // !OpenBSD
 
 	return QString();
 }
