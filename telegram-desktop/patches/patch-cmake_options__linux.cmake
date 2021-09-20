Index: cmake/options_linux.cmake
--- cmake/options_linux.cmake.orig
+++ cmake/options_linux.cmake
@@ -45,11 +45,6 @@ if (DESKTOP_APP_SPECIAL_TARGET)
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
@@ -96,18 +91,5 @@ if (NOT DESKTOP_APP_USE_PACKAGED)
         -pthread
         -rdynamic
         -fwhole-program
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
