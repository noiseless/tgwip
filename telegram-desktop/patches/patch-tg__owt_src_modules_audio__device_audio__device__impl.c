--- tg_owt/src/modules/audio_device/audio_device_impl.cc.orig	Fri Nov 20 03:20:08 2020
+++ tg_owt/src/modules/audio_device/audio_device_impl.cc	Fri Nov 20 03:25:51 2020
@@ -37,7 +37,7 @@
 #include "modules/audio_device/android/opensles_player.h"
 #include "modules/audio_device/android/opensles_recorder.h"
 #elif defined(WEBRTC_LINUX)
-#if defined(WEBRTC_ENABLE_LINUX_ALSA)
+#if defined(WEBRTC_ENABLE_LINUX_ALSA) && !defined(__OpenBSD__)
 #include "modules/audio_device/linux/audio_device_alsa_linux.h"
 #endif
 #if defined(WEBRTC_ENABLE_LINUX_PULSE)
@@ -247,7 +247,7 @@
 // TODO(bugs.webrtc.org/9127): improve support and make it more clear that
 // PulseAudio is the default selection.
 #elif defined(WEBRTC_LINUX)
-#if !defined(WEBRTC_ENABLE_LINUX_PULSE)
+#if !defined(WEBRTC_ENABLE_LINUX_PULSE) && !defined(__OpenBSD__)
   // Build flag 'rtc_include_pulse_audio' is set to false. In this mode:
   // - kPlatformDefaultAudio => ALSA, and
   // - kLinuxAlsaAudio => ALSA, and
@@ -270,9 +270,11 @@
     // Linux PulseAudio implementation is default.
     audio_device_.reset(new AudioDeviceLinuxPulse());
     RTC_LOG(INFO) << "Linux PulseAudio APIs will be utilized";
+#if !defined(__OpenBSD__)
   } else if (audio_layer == kLinuxAlsaAudio) {
     audio_device_.reset(new AudioDeviceLinuxALSA());
     RTC_LOG(WARNING) << "Linux ALSA APIs will be utilized.";
+#endif
   }
 #endif  // #if !defined(WEBRTC_ENABLE_LINUX_PULSE)
 #endif  // #if defined(WEBRTC_LINUX)
