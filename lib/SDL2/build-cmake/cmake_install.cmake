# Install script for directory: /home/dmlasko/_cursus/cub3d/lib/SDL2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/dmlasko/_cursus/cub3d/lib/SDL2/build")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/libSDL2-2.0.so.0.3000.2"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/libSDL2-2.0.so.0"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.so.0.3000.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.so.0"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/libSDL2-2.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/libSDL2main.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/libSDL2.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/libSDL2_test.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2Targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2Targets.cmake"
         "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2Targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2Targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2Targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2Targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2Targets-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2mainTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2mainTargets.cmake"
         "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2mainTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2mainTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2mainTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2mainTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2mainTargets-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2staticTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2staticTargets.cmake"
         "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2staticTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2staticTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2staticTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2staticTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2staticTargets-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2testTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2testTargets.cmake"
         "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2testTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2testTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2/SDL2testTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2testTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/CMakeFiles/Export/lib/cmake/SDL2/SDL2testTargets-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2" TYPE FILE FILES
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/SDL2Config.cmake"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/SDL2ConfigVersion.cmake"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/cmake/sdlfind.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_assert.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_atomic.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_audio.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_bits.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_blendmode.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_clipboard.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_copying.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_cpuinfo.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_egl.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_endian.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_error.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_events.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_filesystem.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_gamecontroller.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_gesture.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_guid.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_haptic.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_hidapi.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_hints.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_joystick.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_keyboard.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_keycode.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_loadso.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_locale.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_log.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_main.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_messagebox.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_metal.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_misc.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_mouse.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_mutex.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_name.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_opengl.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_opengl_glext.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_opengles.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_opengles2.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_opengles2_gl2.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_opengles2_gl2ext.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_opengles2_gl2platform.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_opengles2_khrplatform.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_pixels.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_platform.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_power.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_quit.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_rect.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_render.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_rwops.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_scancode.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_sensor.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_shape.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_stdinc.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_surface.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_system.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_syswm.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_assert.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_common.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_compare.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_crc32.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_font.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_fuzzer.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_harness.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_images.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_log.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_md5.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_memory.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_test_random.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_thread.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_timer.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_touch.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_types.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_version.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_video.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/SDL_vulkan.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/begin_code.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/include/close_code.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/include/SDL2/SDL_revision.h"
    "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/include-config-/SDL2/SDL_config.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/SDL2" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/LICENSE.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/sdl2.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
            execute_process(COMMAND /usr/bin/cmake -E create_symlink
              "libSDL2-2.0.so" "libSDL2.so"
              WORKING_DIRECTORY "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/libSDL2.so")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/sdl2-config")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/aclocal" TYPE FILE FILES "/home/dmlasko/_cursus/cub3d/lib/SDL2/sdl2.m4")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/dmlasko/_cursus/cub3d/lib/SDL2/build-cmake/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
