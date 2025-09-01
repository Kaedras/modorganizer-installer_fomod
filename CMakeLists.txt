cmake_minimum_required(VERSION 3.16)

project(installer_fomod)

if(UNIX)
    find_package(OpenGL REQUIRED)
endif()

add_subdirectory(src)
