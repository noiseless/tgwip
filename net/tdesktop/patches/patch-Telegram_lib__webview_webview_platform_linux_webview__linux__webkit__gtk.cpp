$ OpenBSD: $

Adding the missing header

Index: Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.cpp
--- Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.cpp.orig
+++ Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.cpp
@@ -11,6 +11,8 @@
 
 #define LOAD_SYMBOL(handle, func) LoadSymbol(handle, #func, func)
 
+#include <gdk/gdkx.h>
+
 namespace Webview::WebkitGtk {
 namespace {
 
