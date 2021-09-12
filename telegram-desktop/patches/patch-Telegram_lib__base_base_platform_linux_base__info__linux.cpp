--- Telegram/lib_base/base/platform/linux/base_info_linux.cpp.orig	Tue Aug 17 15:17:10 2021
+++ Telegram/lib_base/base/platform/linux/base_info_linux.cpp	Sun Aug 29 05:20:29 2021
@@ -16,9 +16,11 @@
 #include <QtCore/QDate>
 #include <QtGui/QGuiApplication>
 
+#if !defined(__OpenBSD__)
 #ifdef Q_OS_LINUX
 #include <gnu/libc-version.h>
 #endif // Q_OS_LINUX
+#endif // !OpenBSD
 
 namespace Platform {
 namespace {
@@ -46,12 +48,16 @@
 	static const auto result = [&] {
 		QStringList resultList{};
 
+#if !defined(__OpenBSD__)
 // this file is used on both Linux & BSD
 #ifdef Q_OS_LINUX
 		resultList << "Linux";
 #else // Q_OS_LINUX
 		resultList << QSysInfo::kernelType();
 #endif // !Q_OS_LINUX
+#else // !OpenBSD
+		resultList << "OpenBSD";
+#endif // !OpenBSD
 
 		if (const auto desktopEnvironment = GetDesktopEnvironment();
 			!desktopEnvironment.isEmpty()) {
@@ -109,14 +115,17 @@
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
@@ -124,6 +133,7 @@
 	}();
 	return result;
 #endif // Q_OS_LINUX
+#endif // !OpenBSD
 
 	return QString();
 }
