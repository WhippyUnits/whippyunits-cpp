cmake_minimum_required(VERSION 3.21)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build macOS universal libraries by default
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "")
set(CMAKE_OSX_DEPLOYMENT_TARGET "14.0" CACHE STRING "")

project(whippyunits LANGUAGES CXX)

include(BuildTypes)
include(CMakePackageConfigHelpers)
include(CTest)
include(CompilerFlags)
include(FetchContent)

# Control where the static and shared libraries are built so that on Windows,
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_EXAMPLES "Build examples" OFF)

add_library(whippyunits INTERFACE)
add_library(whippyunits::whippyunits ALIAS whippyunits)

interface_compiler_flags(whippyunits)
target_include_directories(
    whippyunits
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

if(BUILD_TESTING AND NOT CMAKE_CROSSCOMPILING)
    # Catch2 dependency
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.11.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
    )
    FetchContent_MakeAvailable(Catch2)
endif()

install(
    TARGETS whippyunits
    COMPONENT whippyunits
    EXPORT whippyunitsTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)
export(TARGETS whippyunits FILE whippyunits.cmake NAMESPACE whippyunits::)
install(DIRECTORY include/ COMPONENT whippyunits DESTINATION "include")
install(
    EXPORT whippyunitsTargets
    FILE whippyunits.cmake
    NAMESPACE whippyunits::
    DESTINATION lib/cmake/whippyunits
)

# Generate the config file that includes the exports
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/whippyunitsConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/whippyunitsConfig.cmake
    INSTALL_DESTINATION "lib/cmake/whippyunits"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# Install the config file
install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/whippyunitsConfig.cmake
    COMPONENT whippyunits
    DESTINATION lib/cmake/whippyunits
)

if(BUILD_TESTING AND NOT CMAKE_CROSSCOMPILING)
    enable_testing()
    list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
    include(Catch)

    # Build whippyunits tests
    file(GLOB_RECURSE whippyunits_test_src test/src/*.cpp)
    add_executable(whippyunits_test ${whippyunits_test_src})
    compiler_flags(whippyunits_test)
    target_include_directories(
        whippyunits_test
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test/include
    )
    target_link_libraries(whippyunits_test whippyunits Catch2::Catch2WithMain)
    if(NOT CMAKE_TOOLCHAIN_FILE)
        catch_discover_tests(whippyunits_test)
    endif()
endif()

# Build examples and example tests
if(BUILD_EXAMPLES)
    include(SubdirList)
    subdir_list(EXAMPLES ${CMAKE_CURRENT_SOURCE_DIR}/examples)
    foreach(example ${EXAMPLES})
        # Build example
        file(GLOB_RECURSE sources examples/${example}/src/*.cpp)
        add_executable(${example} ${sources})
        compiler_flags(${example})
        target_include_directories(
            ${example}
            PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/examples/${example}/include
        )
        target_link_libraries(${example} whippyunits)

        # Build example test if files exist for it
        if(
            BUILD_TESTING
            AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/examples/${example}/test
        )
            file(GLOB_RECURSE test_sources examples/${example}/test/*.cpp)
            add_executable(${example}_test ${sources} ${test_sources})
            compiler_flags(${example}_test)
            target_compile_definitions(${example}_test PUBLIC RUNNING_TESTS)
            target_include_directories(
                ${example}_test
                PRIVATE
                    ${CMAKE_CURRENT_SOURCE_DIR}/examples/${example}/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/examples/${example}/test/include
            )
            target_link_libraries(
                ${example}_test
                whippyunits
                Catch2::Catch2WithMain
            )
            if(NOT CMAKE_TOOLCHAIN_FILE)
                catch_discover_tests(${example}_test)
            endif()
        endif()
    endforeach()
endif()
