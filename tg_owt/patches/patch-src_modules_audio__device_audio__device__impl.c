$OpenBSD$

Index: src/modules/audio_device/audio_device_impl.cc
--- src/modules/audio_device/audio_device_impl.cc.orig
+++ src/modules/audio_device/audio_device_impl.cc
@@ -135,6 +135,9 @@ int32_t AudioDeviceModuleImpl::CheckPlatform() {
 #elif defined(WEBRTC_LINUX)
   platform = kPlatformLinux;
   RTC_LOG(INFO) << "current platform is Linux";
+#elif defined(__OpenBSD__)
+  platform = kPlatformNotSupported;
+  RTC_LOG(INFO) << "current platform is OpenBSD";
 #elif defined(WEBRTC_IOS)
   platform = kPlatformIOS;
   RTC_LOG(INFO) << "current platform is IOS";
