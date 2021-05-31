cmake_minimum_required(VERSION 3.0)
project("p5.experiments.cmake.framework_with_dedicated_components.application")

include("GNUInstallDirs")

find_package("p5.experiments.cmake.framework_with_dedicated_components" COMPONENTS "a" "b" REQUIRED)

add_executable("main" "src/main.cxx")
set_property(TARGET "main" PROPERTY OUTPUT_NAME "application")
target_compile_features("main" PRIVATE "cxx_std_20")

target_link_libraries("main" PRIVATE "p5.experiments.cmake.framework_with_dedicated_components::a")
target_link_libraries("main" PRIVATE "p5.experiments.cmake.framework_with_dedicated_components::b")

install(TARGETS "main" DESTINATION "${CMAKE_INSTALL_BINDIR}")
