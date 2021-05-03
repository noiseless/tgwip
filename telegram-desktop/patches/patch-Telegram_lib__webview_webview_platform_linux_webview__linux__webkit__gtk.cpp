--- Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.cpp.orig	Sun May  2 04:20:21 2021
+++ Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.cpp	Sun May  2 04:21:05 2021
@@ -9,6 +9,8 @@
 #include "base/platform/linux/base_linux_gtk_integration.h"
 #include "base/platform/linux/base_linux_gtk_integration_p.h"
 
+#include <gdk/gdkx.h>
+
 namespace Webview::WebkitGtk {
 namespace {
 
