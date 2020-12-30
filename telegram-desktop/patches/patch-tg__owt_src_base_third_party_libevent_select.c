--- tg_owt/src/base/third_party/libevent/select.c.orig	Fri Nov 20 02:13:40 2020
+++ tg_owt/src/base/third_party/libevent/select.c	Fri Nov 20 02:21:58 2020
@@ -60,11 +60,13 @@
 #define        howmany(x, y)   (((x)+((y)-1))/(y))
 #endif
 
+#if !defined(__OpenBSD__)
 #ifndef _EVENT_HAVE_FD_MASK
 /* This type is mandatory, but Android doesn't define it. */
 #undef NFDBITS
 #define NFDBITS (sizeof(long)*8)
 typedef unsigned long fd_mask;
+#endif
 #endif
 
 struct selectop {
