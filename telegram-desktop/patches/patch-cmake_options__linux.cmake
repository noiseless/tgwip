--- cmake/options_linux.cmake.orig	Sun Aug 29 04:55:30 2021
+++ cmake/options_linux.cmake	Sun Aug 29 04:56:17 2021
@@ -40,11 +40,6 @@
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
@@ -89,18 +84,5 @@
     INTERFACE
         -pthread
         -rdynamic
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
     )
 endif()
