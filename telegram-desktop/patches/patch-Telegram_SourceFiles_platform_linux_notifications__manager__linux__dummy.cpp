--- Telegram/SourceFiles/platform/linux/notifications_manager_linux_dummy.cpp.orig	Sun May  2 19:26:59 2021
+++ Telegram/SourceFiles/platform/linux/notifications_manager_linux_dummy.cpp	Sun May  2 19:28:17 2021
@@ -13,15 +13,15 @@
 namespace Platform {
 namespace Notifications {
 
-bool SkipAudio() {
+bool SkipAudioForCustom() {
 	return false;
 }
 
-bool SkipToast() {
+bool SkipToastForCustom() {
 	return false;
 }
 
-bool SkipFlashBounce() {
+bool SkipFlashBounceForCustom() {
 	return false;
 }
 
