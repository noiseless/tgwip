Index: Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.cpp
--- Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.cpp.orig
+++ Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.cpp
@@ -13,6 +13,8 @@ extern "C" {
 #include <gdk/gdkx.h>
 } // extern "C"
 
+#include <gdk/gdkx.h>
+
 namespace Webview::WebkitGtk {
 namespace {
 
