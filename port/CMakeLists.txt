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
# ---------------------------------------------------------------------------
# Emulation core (16-bit x86 + DOS/BIOS shims).
#
# Deliberately links WITHOUT SDL so the conformance suite runs in asset-free,
# headless CI and the core stays free of HAL dependencies.
# ---------------------------------------------------------------------------
set(XANTH_EMU_SOURCES
    src/asset_check.c
    src/emu/cpu86.c
    src/emu/cpu86_alu.c
    src/emu/mzload.c
    src/emu/dos_mcb.c
    src/emu/vm.c
)

add_library(xanth_emu OBJECT ${XANTH_EMU_SOURCES})
target_include_directories(xanth_emu PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/emu
)

set(XANTH_COMMON_SOURCES
    src/dos_mem.c
    src/asset_oracle.c
    src/hal_video.c
    src/controller_help.c
    src/hal_audio.c
    src/hal_input.c
    src/hal_fs.c
    src/blast.c
    src/pic_loader.c
    src/story_loader.c
    src/rgn_loader.c
    src/midi_player.c
)

# The port executable runs the retail image under the VM. It deliberately
# does NOT link engine_glue.c: that file is the hand-written reimplementation
# being retired, and linking it here is what let the port drift into being a
# replacement implementation.
set(XANTH_PORT_SOURCES
    src/emu/main_vm.c
    src/emu/native_stage2.c
    src/dos_mem.c
    src/hal_video.c
    src/controller_help.c
    src/hal_audio.c
    src/hal_input.c
    src/hal_fs.c
    src/midi_player.c   # hal_audio depends on midi_tick; retired with audio rework
)

add_executable(xanth_port ${XANTH_PORT_SOURCES} $<TARGET_OBJECTS:xanth_emu>)

target_include_directories(xanth_port PRIVATE
    include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/emu
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
        src/midi_player.c
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

    # CPU conformance: no SDL, no retail assets, so it can gate public CI.
    add_executable(xanth_cpu_tests
        tests/test_cpu86.c
        src/dos_mem.c
        $<TARGET_OBJECTS:xanth_emu>
    )
    target_include_directories(xanth_cpu_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/emu
    )
    set_target_properties(xanth_cpu_tests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

    # Loader dump tool: the Python side of tests/test_mzload.py drives this
    # and asserts the C loader and the decomp pipeline's reference agree.
    add_executable(tool_mzdump
        tests/tool_mzdump.c
        src/dos_mem.c
        $<TARGET_OBJECTS:xanth_emu>
    )
    target_include_directories(tool_mzdump PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/emu
    )
    set_target_properties(tool_mzdump PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

    # Boot driver: runs the retail image under the VM. Fatal on any
    # unimplemented service, so its output is the work queue.
    add_executable(tool_vmboot
        tests/tool_vmboot.c
        src/emu/native_stage2.c
        src/dos_mem.c
        src/hal_audio.c
        src/midi_player.c
        src/hal_fs.c
        $<TARGET_OBJECTS:xanth_emu>
    )
    target_include_directories(tool_vmboot PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/emu
    )
    target_compile_definitions(tool_vmboot PRIVATE XANTH_NATIVE_STAGE2_TESTING=1)
    if(SDL2_FOUND_ANY)
        target_link_libraries(tool_vmboot PRIVATE ${SDL2_TARGET_LIB})
    endif()
    if(UNIX AND NOT APPLE)
        target_link_libraries(tool_vmboot PRIVATE m)
    endif()
    set_target_properties(tool_vmboot PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

    if(SDL2_FOUND_ANY)
        add_executable(tool_vmclick tests/tool_vmclick.c src/emu/native_stage2.c
            src/dos_mem.c src/hal_audio.c src/midi_player.c src/hal_fs.c
            src/hal_input.c src/hal_video.c src/controller_help.c $<TARGET_OBJECTS:xanth_emu>)
        target_include_directories(tool_vmclick PRIVATE include include/emu)
        target_compile_definitions(tool_vmclick PRIVATE XANTH_NATIVE_STAGE2_TESTING=1)
        target_link_libraries(tool_vmclick PRIVATE ${SDL2_TARGET_LIB})
        if(UNIX AND NOT APPLE)
            target_link_libraries(tool_vmclick PRIVATE m)
        endif()
    endif()

    # Sound Blaster DMA Pipeline and Virtual Cycle Timing test
    add_executable(test_dma_pipeline
        tests/test_dma_pipeline.c
        src/dos_mem.c
        src/hal_audio.c
        src/midi_player.c
        src/hal_fs.c
        $<TARGET_OBJECTS:xanth_emu>
    )
    target_include_directories(test_dma_pipeline PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/emu
    )
    if(SDL2_FOUND_ANY)
        target_link_libraries(test_dma_pipeline PRIVATE ${SDL2_TARGET_LIB})
    endif()
    if(UNIX AND NOT APPLE)
        target_link_libraries(test_dma_pipeline PRIVATE m)
    endif()
    set_target_properties(test_dma_pipeline PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

    add_executable(test_adversarial_dma
        tests/test_adversarial_dma.c
        src/dos_mem.c
        src/hal_audio.c
        src/midi_player.c
        src/hal_fs.c
        $<TARGET_OBJECTS:xanth_emu>
    )
    target_include_directories(test_adversarial_dma PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/emu
    )
    if(SDL2_FOUND_ANY)
        target_link_libraries(test_adversarial_dma PRIVATE ${SDL2_TARGET_LIB})
    endif()
    if(UNIX AND NOT APPLE)
        target_link_libraries(test_adversarial_dma PRIVATE m)
    endif()
    set_target_properties(test_adversarial_dma PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

    add_executable(xanth_native_guard_tests tests/test_native_guards.c src/dos_mem.c $<TARGET_OBJECTS:xanth_emu>)
    target_include_directories(xanth_native_guard_tests PRIVATE include include/emu)

    add_executable(xanth_controller_guest_ui_tests tests/test_controller_guest_ui.c src/controller_guest_ui.c)
    target_include_directories(xanth_controller_guest_ui_tests PRIVATE include)
    add_test(NAME ControllerGuestUiTests COMMAND xanth_controller_guest_ui_tests)

    # Owned assets may be kept outside the public checkout.
    set(XANTH_TEST_DATA_DIR "$ENV{XANTH_DATA}" CACHE PATH "Owned retail data directory for integration tests")
    if(EXISTS "${XANTH_TEST_DATA_DIR}/XANTH.EXE")
        find_package(Python3 COMPONENTS Interpreter QUIET)
        if(Python3_Interpreter_FOUND)
            if(TARGET tool_vmclick)
                add_test(NAME RetailMouseQuickTapTests
                    COMMAND ${CMAKE_COMMAND} -E env
                        "XANTH_DATA=${XANTH_TEST_DATA_DIR}"
                        "XANTH_VMCLICK=$<TARGET_FILE:tool_vmclick>"
                        ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_vm_mouse_quick_tap.py)
                set_tests_properties(RetailMouseQuickTapTests PROPERTIES TIMEOUT 300)
            endif()
            add_test(NAME GuestVerbSemanticsTests
                COMMAND ${CMAKE_COMMAND} -E env
                    "XANTH_DATA=${XANTH_TEST_DATA_DIR}"
                    "XANTH_VMBOOT=$<TARGET_FILE:tool_vmboot>"
                    ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_guest_verb_semantics.py)
            set_tests_properties(GuestVerbSemanticsTests PROPERTIES
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
                TIMEOUT 420 ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy")
            if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../game_cd/XANTH/XANTH.EXE")
                add_test(NAME RealTimeBootLogoTest
                    COMMAND ${CMAKE_COMMAND} -E env
                        "XANTH_DATA=${XANTH_TEST_DATA_DIR}"
                        "XANTH_PORT_BIN=$<TARGET_FILE:xanth_port>"
                        ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_realtime_boot.py)
                set_tests_properties(RealTimeBootLogoTest PROPERTIES TIMEOUT 300 SKIP_RETURN_CODE 77)
                foreach(suite IN ITEMS mzload vmboot vmplay contextverbs hotspots
                        overlay saveload navigate soundblaster soak realsound)
                    add_test(NAME Vm_${suite}
                        COMMAND ${CMAKE_COMMAND} -E env
                            "XANTH_DATA=${XANTH_TEST_DATA_DIR}"
                            "XANTH_VM_TOOL=$<TARGET_FILE:tool_vmboot>"
                            "XANTH_MZ_TOOL=$<TARGET_FILE:tool_mzdump>"
                            ${Python3_EXECUTABLE} -m unittest discover -s tests -p "test_${suite}.py")
                    set_tests_properties(Vm_${suite} PROPERTIES
                        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
                        TIMEOUT 1800 ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy")
                endforeach()
            endif()
        endif()
    endif()

    add_executable(xanth_controller_help_tests tests/test_controller_help.c src/controller_help.c src/dos_mem.c)
    target_include_directories(xanth_controller_help_tests PRIVATE include)
    add_test(NAME ControllerHelpTests COMMAND xanth_controller_help_tests)
    if(UNIX)
        add_executable(xanth_vm_mouse_tests tests/test_vm_mouse_events.c src/dos_mem.c $<TARGET_OBJECTS:xanth_emu>)
        target_include_directories(xanth_vm_mouse_tests PRIVATE include include/emu)
        add_test(NAME VmMouseEventsTests COMMAND xanth_vm_mouse_tests)
        add_executable(xanth_vm_irq_window_tests tests/test_vm_irq_window.c src/dos_mem.c $<TARGET_OBJECTS:xanth_emu>)
        target_include_directories(xanth_vm_irq_window_tests PRIVATE include include/emu)
        add_test(NAME VmIrqWindowTests COMMAND xanth_vm_irq_window_tests)
    endif()
    if(SDL2_FOUND_ANY)
        add_executable(xanth_mouse_video_tests tests/test_mouse_video.c src/dos_mem.c src/controller_help.c)
        target_include_directories(xanth_mouse_video_tests PRIVATE include)
        target_link_libraries(xanth_mouse_video_tests PRIVATE ${SDL2_TARGET_LIB})
        add_test(NAME MouseVideoTests COMMAND xanth_mouse_video_tests)
        set_tests_properties(MouseVideoTests PROPERTIES ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy")
    endif()

    # SDL virtual controllers require 2.0.14; preservation stub builds omit this.
    if(SDL2_FOUND_ANY)
        include(CheckSymbolExists)
        set(CMAKE_REQUIRED_LIBRARIES ${SDL2_TARGET_LIB})
        check_symbol_exists(SDL_JoystickAttachVirtual "SDL.h" XANTH_SDL_VIRTUAL_CONTROLLER)
        unset(CMAKE_REQUIRED_LIBRARIES)
        if(XANTH_SDL_VIRTUAL_CONTROLLER)
            add_executable(xanth_controller_tests tests/test_controller.c src/hal_input.c)
            target_include_directories(xanth_controller_tests PRIVATE include)
            target_link_libraries(xanth_controller_tests PRIVATE ${SDL2_TARGET_LIB})
            add_test(NAME ControllerInputTests COMMAND xanth_controller_tests)
            set_tests_properties(ControllerInputTests PROPERTIES
                ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy")
        endif()
    endif()

    add_test(NAME CpuConformanceTests COMMAND xanth_cpu_tests)
    set_tests_properties(CpuConformanceTests PROPERTIES TIMEOUT 60)

    add_test(NAME NativeUnitTests COMMAND xanth_tests)
    set_tests_properties(NativeUnitTests PROPERTIES
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
        ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy"
        TIMEOUT 30
    )

    add_test(NAME Native114942NegativeFixture
        COMMAND tool_vmboot --test-native-exe114942-negative)
    set_tests_properties(Native114942NegativeFixture PROPERTIES TIMEOUT 10)
    add_test(NAME Native103774NegativeFixture
        COMMAND tool_vmboot --test-native-exe103774-negative)
    set_tests_properties(Native103774NegativeFixture PROPERTIES TIMEOUT 10)
    add_test(NAME Native100203PrefixFixture
        COMMAND tool_vmboot --test-native-exe100203-prefix)
    set_tests_properties(Native100203PrefixFixture PROPERTIES TIMEOUT 10)
    add_test(NAME Native103744Fixture
        COMMAND tool_vmboot --test-native-exe103744)
    set_tests_properties(Native103744Fixture PROPERTIES TIMEOUT 10)
    add_test(NAME Native100016StoreFixture
        COMMAND tool_vmboot --test-native-exe100016-store)
    set_tests_properties(Native100016StoreFixture PROPERTIES TIMEOUT 10)

    add_test(NAME NativeHalStressTests COMMAND xanth_hal_stress)
    set_tests_properties(NativeHalStressTests PROPERTIES
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
        ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy"
        TIMEOUT 30
    )

    add_test(NAME NativeAudioStressTests COMMAND test_stress_audio_engine)
    set_tests_properties(NativeAudioStressTests PROPERTIES
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
        ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy"
        TIMEOUT 60
    )

    set_tests_properties(Native114942NegativeFixture Native103774NegativeFixture
        Native100203PrefixFixture Native103744Fixture Native100016StoreFixture
        PROPERTIES SKIP_RETURN_CODE 77)

    add_test(NAME NativeDmaPipelineTests COMMAND test_dma_pipeline)
    set_tests_properties(NativeDmaPipelineTests PROPERTIES
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy"
        TIMEOUT 60
    )

    # Boot smoke against the real retail image. Requires the disc, so it is
    # only registered when the assets are actually present -- an absent disc
    # must not look like a failure in asset-free CI.
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../game_cd/XANTH/XANTH.EXE")
        find_package(Python3 COMPONENTS Interpreter QUIET)
        if(Python3_Interpreter_FOUND)
            add_test(NAME Stage2NativeParityTest
                COMMAND ${CMAKE_COMMAND} -E env
                        "XANTH_VMBOOT=$<TARGET_FILE:tool_vmboot>"
                        ${Python3_EXECUTABLE}
                        ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_stage2_native.py
            )
            set_tests_properties(Stage2NativeParityTest PROPERTIES
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
                TIMEOUT 180
            )
            add_test(NAME Stage2OpeningNativeParityTest
                COMMAND ${CMAKE_COMMAND} -E env
                        "XANTH_VMBOOT=$<TARGET_FILE:tool_vmboot>"
                        ${Python3_EXECUTABLE}
                        ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_stage2_opening.py
            )
            set_tests_properties(Stage2OpeningNativeParityTest PROPERTIES
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
                TIMEOUT 360
            )
            add_test(NAME FontReplacementParityTest
                COMMAND ${CMAKE_COMMAND} -E env
                        "XANTH_VMBOOT=$<TARGET_FILE:tool_vmboot>"
                        ${Python3_EXECUTABLE}
                        ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_font_replacements.py
            )
            set_tests_properties(FontReplacementParityTest PROPERTIES
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
                TIMEOUT 720
            )
            # This continuation requires the guest-generated 275-point save.
            # Register it only for the measured anchor, never a synthetic save.
            set(FIRE_ANCHOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../build/agent_dungeon_test")
            if(EXISTS "${FIRE_ANCHOR_DIR}/XANTH000.SAV")
                file(SHA256 "${FIRE_ANCHOR_DIR}/XANTH000.SAV" FIRE_ANCHOR_SHA256)
                if(FIRE_ANCHOR_SHA256 STREQUAL
                   "901998237900d1665a78bfcc42cb0f067045c49806edc336efbed7bd062647df")
                    add_test(NAME Vm_walkthrough_fire
                        COMMAND ${CMAKE_COMMAND} -E env
                                "XANTH_VM_TOOL=$<TARGET_FILE:tool_vmboot>"
                                "XANTH_FIRE_ANCHOR=${FIRE_ANCHOR_DIR}"
                                ${Python3_EXECUTABLE} -m unittest tests.test_walkthrough_fire
                    )
                    set_tests_properties(Vm_walkthrough_fire PROPERTIES
                        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
                        ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy"
                        TIMEOUT 660
                    )
                endif()
            endif()
        endif()

        find_package(Python3 COMPONENTS Interpreter QUIET)
        if(Python3_Interpreter_FOUND)
            add_test(NAME RealTimeBootLogoTest
                COMMAND ${CMAKE_COMMAND} -E env
                        "XANTH_PORT_BIN=$<TARGET_FILE:xanth_port>"
                        ${Python3_EXECUTABLE}
                        ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_realtime_boot.py
            )
            set_tests_properties(RealTimeBootLogoTest PROPERTIES
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
                TIMEOUT 300
            )
        endif()

        add_test(NAME HeadlessBootSmokeTest
            COMMAND xanth_port --headless --frames 600
                    --data ${CMAKE_CURRENT_SOURCE_DIR}/../game_cd/XANTH
                    --saves ${CMAKE_BINARY_DIR}/saves
        )
        set_tests_properties(HeadlessBootSmokeTest PROPERTIES
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
            ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy"
            TIMEOUT 300
        )

        # Asset-gated suites. Each drives the real game; see tests/*.py.
        foreach(suite IN ITEMS vmplay contextverbs hotspots walkthrough overlay
                       saveload navigate soundblaster soak)
            add_test(NAME Vm_${suite}
                COMMAND ${CMAKE_COMMAND} -E env
                        python3 -m unittest discover -s tests
                                -p "test_${suite}.py"
            )
            set_tests_properties(Vm_${suite} PROPERTIES
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
                TIMEOUT 1800
            )
        endforeach()

        # The walkthrough is the long pole and grows as segments are added:
        # segments 1-5 each replay the route from a cold boot, and segment 6
        # first builds the save anchor the later segments resume from. It sat
        # at ~1100s of the shared 1800s budget when segment 6 landed, which is
        # too little headroom -- and a ctest timeout reads as a hard failure
        # with no useful output, which is the worst way to learn the suite
        # simply got longer.
        set_tests_properties(Vm_walkthrough PROPERTIES TIMEOUT 5400)
    endif()
endif()
