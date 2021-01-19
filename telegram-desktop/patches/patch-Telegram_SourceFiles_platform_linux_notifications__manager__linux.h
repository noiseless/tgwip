--- ./Telegram/SourceFiles/platform/linux/notifications_manager_linux.h.orig	Tue Jan 19 00:48:00 2021
+++ ./Telegram/SourceFiles/platform/linux/notifications_manager_linux.h	Tue Jan 19 00:48:48 2021
@@ -8,6 +8,7 @@
 #pragma once
 
 #include "platform/platform_notifications_manager.h"
+#include "base/platform/base_platform_info.h"
 #include "base/weak_ptr.h"
 
 namespace Platform {
