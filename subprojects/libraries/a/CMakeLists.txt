cmake_minimum_required(VERSION 3.0)
project("p5.experiments.cmake.framework_with_dedicated_components.a")

include("GNUInstallDirs")
include("CMakePackageConfigHelpers")

add_library("main"
    "include/p5/experiments/cmake/framework_with_dedicated_components/a.hpp"
    "src/main.cxx"
)

add_library("p5.experiments.cmake.framework_with_dedicated_components::a" ALIAS "main")

set_property(TARGET "main" PROPERTY EXPORT_NAME "a")
set_property(TARGET "main" PROPERTY OUTPUT_NAME "${CMAKE_PROJECT_NAME}")

target_compile_features("main" PRIVATE "cxx_std_20")

target_include_directories("main" PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/package-config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/.generated/package-config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

install(TARGETS "main" EXPORT "targets" DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install(DIRECTORY "include/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(EXPORT "targets" NAMESPACE "p5.experiments.cmake.framework_with_dedicated_components::" FILE "targets.cmake" DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/.generated/package-config.cmake" RENAME "${CMAKE_PROJECT_NAME}-config.cmake" DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}")
