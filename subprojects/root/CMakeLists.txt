cmake_minimum_required(VERSION 3.0)
project("p5.experiments.cmake.framework_with_dedicated_components")

include("GNUInstallDirs")
include("CMakePackageConfigHelpers")

configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/package-config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/.generated/package-config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/.generated/package-config.cmake" RENAME "${CMAKE_PROJECT_NAME}-config.cmake" DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}")
