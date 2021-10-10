--- cmake/options_linux.cmake.orig	Fri Oct  8 09:31:21 2021
+++ cmake/options_linux.cmake	Sun Oct 10 01:37:31 2021
@@ -7,7 +7,6 @@
 target_compile_options(common_options
 INTERFACE
     -fstack-protector-all
-    -fstack-clash-protection
     -fPIC
     $<IF:$<CONFIG:Debug>,,-fno-strict-aliasing>
     -pipe
@@ -52,11 +51,6 @@
     target_link_options(common_options INTERFACE $<IF:$<CONFIG:Debug>,,-g -flto -fuse-linker-plugin>)
 endif()
 
-target_link_libraries(common_options
-INTERFACE
-    desktop-app::external_jemalloc
-)
-
 if (DESKTOP_APP_USE_ALLOCATION_TRACER)
     target_link_options(common_options
     INTERFACE
@@ -104,19 +98,6 @@
         -rdynamic
         -fwhole-program
         -Wl,-z,relro
-        # -pie # https://gitlab.gnome.org/GNOME/nautilus/-/issues/1601
-    )
-endif()
-
-if (DESKTOP_APP_USE_PACKAGED)
-    find_library(ATOMIC_LIBRARY atomic)
-else()
-    find_library(ATOMIC_LIBRARY libatomic.a)
-endif()
-
-if (ATOMIC_LIBRARY)
-    target_link_libraries(common_options
-    INTERFACE
-        ${ATOMIC_LIBRARY}
+        -pie
     )
 endif()
