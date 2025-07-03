cmake_minimum_required(VERSION 4.0.3)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
project(Cpp2Modules VERSION 0.1.0 LANGUAGES CXX)


find_package(cppfront REQUIRED)
set(CPPFRONT_FLAGS "-import-std -verbose")

# Just a plain old C++2 hello world example, no modules
add_executable(hello_world hello_world.cpp2)

# A cpp2 example that uses a module from a .cppm file.
add_executable(mod_cppm)
target_sources(mod_cppm PRIVATE
    module_test_main.cpp2
    PRIVATE FILE_SET CXX_MODULES FILES module_cppm.cppm
)
add_executable(mod_cppm2)
target_sources(mod_cppm2 PRIVATE
    module_test_main.cpp2
    PRIVATE FILE_SET CXX_MODULES FILES module_test.cpp2
)

# Flag to cmake that we want to use import std for these targets.
#todo: don't use this or the cppfront import-std flag if we don't need it on the target.
set_target_properties(hello_world mod_cppm mod_cppm2 PROPERTIES
    CXX_MODULE_STD ON
)

