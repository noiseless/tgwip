--- cmake/options_linux.cmake.orig	Sun May  2 23:57:19 2021
+++ cmake/options_linux.cmake	Sun May  2 23:59:55 2021
@@ -47,16 +47,3 @@
         target_link_options(common_options INTERFACE $<IF:$<CONFIG:Debug>,,-g -flto -fuse-linker-plugin>)
     endif()
 endif()
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
-    )
-endif()
