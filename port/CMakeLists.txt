cmake_minimum_required(VERSION 3.16)
project(xanth_port C)

# ---------------------------------------------------------------------------
# C Standard Configuration
# ---------------------------------------------------------------------------
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# ---------------------------------------------------------------------------
# Build Options
# ---------------------------------------------------------------------------
option(XANTH_BUILD_TESTS "Build native port test suite" ON)
option(XANTH_ENABLE_ASAN "Enable AddressSanitizer (GCC/Clang)" OFF)
option(XANTH_USE_DUMMY_SDL "Build with built-in headless dummy SDL stubs if SDL2 missing" OFF)

# ---------------------------------------------------------------------------
# Platform-Specific Compiler Flags and Definitions
# ---------------------------------------------------------------------------
if(MSVC)
    add_compile_options(
        /W3
        /wd4996
        /wd4244
        /wd4018
    )
    add_compile_definitions(
        _CRT_SECURE_NO_WARNINGS
        WIN32_LEAN_AND_MEAN
        NOMINMAX
    )
else()
    add_compile_options(
        -Wall
        -Wextra
        -Wno-unused-parameter
        -Wno-unused-function
        -Wno-missing-field-initializers
    )
    if(UNIX AND NOT APPLE)
        add_compile_definitions(
            _POSIX_C_SOURCE=200809L
            _DEFAULT_SOURCE
        )
    endif()
    if(XANTH_ENABLE_ASAN)
        add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address)
    endif()
endif()

# ---------------------------------------------------------------------------
# SDL2 Dependency Resolution
# ---------------------------------------------------------------------------
set(SDL2_FOUND_ANY FALSE)

# Check Linuxbrew / Homebrew prefix if present
if(EXISTS "/home/linuxbrew/.linuxbrew/opt/sdl2")
    list(APPEND CMAKE_PREFIX_PATH "/home/linuxbrew/.linuxbrew/opt/sdl2")
    include_directories(SYSTEM
        "/home/linuxbrew/.linuxbrew/opt/sdl2/include"
        "/home/linuxbrew/.linuxbrew/opt/sdl2/include/SDL2"
    )
endif()
if(EXISTS "/home/linuxbrew/.linuxbrew")
    list(APPEND CMAKE_PREFIX_PATH "/home/linuxbrew/.linuxbrew")
    if(DEFINED ENV{PKG_CONFIG_PATH})
        set(ENV{PKG_CONFIG_PATH} "/home/linuxbrew/.linuxbrew/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")
    else()
        set(ENV{PKG_CONFIG_PATH} "/home/linuxbrew/.linuxbrew/lib/pkgconfig")
    endif()
endif()

# 1. CMake Config package (official SDL2 CMake package)
find_package(SDL2 CONFIG QUIET)
if(TARGET SDL2::SDL2)
    set(SDL2_FOUND_ANY TRUE)
    set(SDL2_TARGET_LIB SDL2::SDL2)
elseif(TARGET SDL2::SDL2-static)
    set(SDL2_FOUND_ANY TRUE)
    set(SDL2_TARGET_LIB SDL2::SDL2-static)
endif()

# 2. FindSDL2 module fallback
if(NOT SDL2_FOUND_ANY)
    find_package(SDL2 QUIET)
    if(SDL2_FOUND)
        set(SDL2_FOUND_ANY TRUE)
        add_library(SDL2_Imported UNKNOWN IMPORTED)
        set_target_properties(SDL2_Imported PROPERTIES
            IMPORTED_LOCATION "${SDL2_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${SDL2_INCLUDE_DIR}"
        )
        set(SDL2_TARGET_LIB SDL2_Imported)
    endif()
endif()

# 3. PkgConfig fallback
if(NOT SDL2_FOUND_ANY)
    find_package(PkgConfig QUIET)
    if(PKG_CONFIG_FOUND)
        pkg_check_modules(SDL2 QUIET sdl2)
        if(SDL2_FOUND)
            set(SDL2_FOUND_ANY TRUE)
            add_library(SDL2_Imported INTERFACE IMPORTED)
            set_target_properties(SDL2_Imported PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES "${SDL2_INCLUDE_DIRS}"
                INTERFACE_LINK_LIBRARIES "${SDL2_LIBRARIES}"
            )
            set(SDL2_TARGET_LIB SDL2_Imported)
        endif()
    endif()
endif()

# 4. sdl2-config shell fallback
if(NOT SDL2_FOUND_ANY)
    find_program(SDL2_CONFIG_BIN sdl2-config PATHS /home/linuxbrew/.linuxbrew/bin)
    if(SDL2_CONFIG_BIN)
        execute_process(COMMAND ${SDL2_CONFIG_BIN} --cflags OUTPUT_VARIABLE SDL2_CFLAGS_RAW OUTPUT_STRIP_TRAILING_WHITESPACE)
        execute_process(COMMAND ${SDL2_CONFIG_BIN} --libs OUTPUT_VARIABLE SDL2_LIBS_RAW OUTPUT_STRIP_TRAILING_WHITESPACE)
        if(SDL2_LIBS_RAW)
            set(SDL2_FOUND_ANY TRUE)
            add_library(SDL2_Imported INTERFACE IMPORTED)
            separate_arguments(SDL2_CFLAGS_LIST NATIVE_COMMAND "${SDL2_CFLAGS_RAW}")
            separate_arguments(SDL2_LIBS_LIST NATIVE_COMMAND "${SDL2_LIBS_RAW}")
            set_target_properties(SDL2_Imported PROPERTIES
                INTERFACE_COMPILE_OPTIONS "${SDL2_CFLAGS_LIST}"
                INTERFACE_LINK_LIBRARIES "${SDL2_LIBS_LIST}"
            )
            set(SDL2_TARGET_LIB SDL2_Imported)
        endif()
    endif()
endif()

# 5. Fallback or Error
if(NOT SDL2_FOUND_ANY)
    if(XANTH_USE_DUMMY_SDL)
        message(STATUS "SDL2 not found on system: compiling with built-in headless dummy stubs (-DXANTH_USE_DUMMY_SDL=ON)")
        add_compile_definitions(XANTH_HEADLESS_STUB=1)
    else()
        message(FATAL_ERROR "SDL2 library not found! Install SDL2 development package (e.g. 'sudo dnf install SDL2-devel' or 'sudo apt install libsdl2-dev') or pass -DXANTH_USE_DUMMY_SDL=ON for headless dummy builds.")
    endif()
endif()

# ---------------------------------------------------------------------------
# Source Files and Target Definitions
# ---------------------------------------------------------------------------
set(XANTH_COMMON_SOURCES
    src/hal_video.c
    src/hal_audio.c
    src/hal_input.c
    src/hal_fs.c
    src/engine_glue.c
    src/blast.c
    src/pic_loader.c
    src/story_loader.c
)

set(XANTH_PORT_SOURCES
    src/main.c
    ${XANTH_COMMON_SOURCES}
)

add_executable(xanth_port ${XANTH_PORT_SOURCES})

target_include_directories(xanth_port PRIVATE
    include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(SDL2_FOUND_ANY)
    target_link_libraries(xanth_port PRIVATE ${SDL2_TARGET_LIB})
endif()

if(UNIX AND NOT APPLE)
    target_link_libraries(xanth_port PRIVATE m)
endif()

# ---------------------------------------------------------------------------
# Installation and Output Location
# ---------------------------------------------------------------------------
set_target_properties(xanth_port PROPERTIES
    OUTPUT_NAME "xanth_port"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# ---------------------------------------------------------------------------
# CTest Integration & Unit Test Target
# ---------------------------------------------------------------------------
if(XANTH_BUILD_TESTS)
    enable_testing()

    add_executable(xanth_tests
        tests/test_smoke.c
        ${XANTH_COMMON_SOURCES}
    )

    target_include_directories(xanth_tests PRIVATE
        include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

    if(SDL2_FOUND_ANY)
        target_link_libraries(xanth_tests PRIVATE ${SDL2_TARGET_LIB})
    endif()

    if(UNIX AND NOT APPLE)
        target_link_libraries(xanth_tests PRIVATE m)
    endif()

    add_executable(xanth_hal_stress
        tests/test_hal_stress.c
        ${XANTH_COMMON_SOURCES}
    )

    target_include_directories(xanth_hal_stress PRIVATE
        include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

    if(SDL2_FOUND_ANY)
        target_link_libraries(xanth_hal_stress PRIVATE ${SDL2_TARGET_LIB})
    endif()

    if(UNIX AND NOT APPLE)
        target_link_libraries(xanth_hal_stress PRIVATE m)
    endif()

    add_executable(test_stress_audio_engine
        tests/test_stress_audio_engine.c
        src/hal_fs.c
    )

    target_include_directories(test_stress_audio_engine PRIVATE
        include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

    if(SDL2_FOUND_ANY)
        target_link_libraries(test_stress_audio_engine PRIVATE ${SDL2_TARGET_LIB})
    endif()

    if(UNIX AND NOT APPLE)
        target_link_libraries(test_stress_audio_engine PRIVATE m)
    endif()

    add_test(NAME NativeUnitTests COMMAND xanth_tests)
    set_tests_properties(NativeUnitTests PROPERTIES
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
        ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy"
        TIMEOUT 30
    )

    add_test(NAME NativeHalStressTests COMMAND xanth_hal_stress)
    set_tests_properties(NativeHalStressTests PROPERTIES
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
        ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy"
        TIMEOUT 30
    )

    add_test(NAME HeadlessBootSmokeTest
        COMMAND xanth_port --headless --frames 300 --data ${CMAKE_CURRENT_SOURCE_DIR}/../original --test-boot
    )
    set_tests_properties(HeadlessBootSmokeTest PROPERTIES
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
        ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy"
        TIMEOUT 30
    )
endif()
