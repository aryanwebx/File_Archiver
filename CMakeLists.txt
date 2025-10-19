# =============================================
# File Archiver - Root CMakeLists.txt
# =============================================

# 1. Minimum CMake version required
cmake_minimum_required(VERSION 3.15)

# 2. Project definition
project(FileArchiver 
    VERSION 1.0.0 
    DESCRIPTION "A modern C++ file archiver with compression"
    LANGUAGES CXX
)

# 3. C++ standard settings
set(CMAKE_CXX_STANDARD 17)           # Use C++17 features
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # REQUIRE C++17 support
set(CMAKE_CXX_EXTENSIONS OFF)        # Use standard C++, not compiler extensions

# 4. Default build type (Debug vs Release)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
    message(STATUS "Build type not specified, defaulting to Release")
endif()

# 5. Organize output files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # Executables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # Libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # Shared libraries

# 6. Include our custom CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(CompilerWarnings)
set_project_warnings()

# 7. Print configuration summary
message(STATUS "=========================================")
message(STATUS "File Archiver Configuration Summary")
message(STATUS "=========================================")
message(STATUS "Project: ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "C++ standard: C++${CMAKE_CXX_STANDARD}")
message(STATUS "Source directory: ${CMAKE_SOURCE_DIR}")
message(STATUS "Build directory: ${CMAKE_BINARY_DIR}")
message(STATUS "=========================================")

# 8. Add subdirectories
add_subdirectory(src)

# Only add tests if this is the main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_subdirectory(tests)
endif()