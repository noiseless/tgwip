Index: Telegram/ThirdParty/libtgvoip/VoIPController.cpp
--- Telegram/ThirdParty/libtgvoip/VoIPController.cpp.orig
+++ Telegram/ThirdParty/libtgvoip/VoIPController.cpp
@@ -3009,7 +3009,7 @@ static void initMachTimestart() {
 #endif
 
 double VoIPController::GetCurrentTime(){
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 	struct timespec ts;
 	clock_gettime(CLOCK_MONOTONIC, &ts);
 	return ts.tv_sec+(double)ts.tv_nsec/1000000000.0;
