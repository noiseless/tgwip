--- tg_owt/src/modules/video_capture/linux/device_info_linux.cc.orig	Fri Nov 20 03:36:07 2020
+++ tg_owt/src/modules/video_capture/linux/device_info_linux.cc	Fri Nov 20 03:39:15 2020
@@ -18,7 +18,11 @@
 #include <sys/ioctl.h>
 #include <unistd.h>
 // v4l includes
+#if defined(__OpenBSD__)
+#include <sys/videoio.h>
+#else
 #include <linux/videodev2.h>
+#endif
 
 #include <vector>
 
