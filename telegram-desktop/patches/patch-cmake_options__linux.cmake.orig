--- cmake/options_linux.cmake.orig	Wed Nov  3 20:34:06 2021
+++ cmake/options_linux.cmake	Thu Nov  4 10:37:02 2021
@@ -7,7 +7,6 @@
 target_compile_options(common_options
 INTERFACE
     -fstack-protector-all
-    -fstack-clash-protection
     -fPIC
     $<IF:$<CONFIG:Debug>,,-fno-strict-aliasing>
     -pipe
@@ -60,11 +59,6 @@
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
@@ -113,19 +107,6 @@
         -fwhole-program
         -Wl,-z,relro
         -Wl,-z,now
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
