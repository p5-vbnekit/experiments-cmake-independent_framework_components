cmake_minimum_required(VERSION 3.0)
project("p5.experiments.cmake.framework_with_dedicated_components")

include("ExternalProject")

set("_sandbox_prefix_path" "${CMAKE_CURRENT_BINARY_DIR}/.sandbox" CACHE INTERNAL "_sandbox_prefix_path" FORCE)
set("_sandbox_prefix_list" "${CMAKE_PREFIX_PATH}" CACHE INTERNAL "_sandbox_prefix_list" FORCE)
list(PREPEND "_sandbox_prefix_list" "${_sandbox_prefix_path}")

ExternalProject_Add("sandbox.libraries.a"
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/subprojects/libraries/a"
    CMAKE_CACHE_ARGS
        "-DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}"
        "-DCMAKE_PREFIX_PATH:PATH=${_sandbox_prefix_list}"
        "-DCMAKE_INSTALL_PREFIX:PATH=${_sandbox_prefix_path}"
)

ExternalProject_Add("sandbox.libraries.b"
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/subprojects/libraries/b"
    CMAKE_CACHE_ARGS
        "-DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}"
        "-DCMAKE_PREFIX_PATH:PATH=${_sandbox_prefix_list}"
        "-DCMAKE_INSTALL_PREFIX:PATH=${_sandbox_prefix_path}"
)

ExternalProject_Add("sandbox.root"
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/subprojects/root"
    CMAKE_CACHE_ARGS
    "-DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}"
    "-DCMAKE_PREFIX_PATH:PATH=${_sandbox_prefix_list}"
    "-DCMAKE_INSTALL_PREFIX:PATH=${_sandbox_prefix_path}"
)

ExternalProject_Add("sandbox.application"
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/subprojects/application"
    CMAKE_CACHE_ARGS
        "-DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}"
        "-DCMAKE_PREFIX_PATH:PATH=${_sandbox_prefix_list}"
        "-DCMAKE_INSTALL_PREFIX:PATH=${_sandbox_prefix_path}"
    DEPENDS
        "sandbox.libraries.a"
        "sandbox.libraries.b"
        "sandbox.root"
)
