--- Telegram/SourceFiles/platform/linux/linux_gtk_integration_p.h.orig	Mon Jan 25 00:14:47 2021
+++ Telegram/SourceFiles/platform/linux/linux_gtk_integration_p.h	Mon Jan 25 00:15:10 2021
@@ -27,7 +27,7 @@
 #endif // !LINK_TO_GTK
 
 // To be able to compile with gtk-2.0 headers as well
-#define GdkMonitor GdkScreen
+typedef struct _GdkMonitor GdkMonitor;
 typedef struct _GtkAppChooser GtkAppChooser;
 
 namespace Platform {
