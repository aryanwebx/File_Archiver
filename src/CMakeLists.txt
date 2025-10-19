# =============================================
# Source Code Build Configuration
# =============================================

# Create the main executable from our source files
add_executable(file_archiver
    main.cpp
)

# Set target properties
set_target_properties(file_archiver PROPERTIES
    OUTPUT_NAME "file_archiver"           # Name of output file
    CXX_STANDARD 17                       # Use C++17
    CXX_STANDARD_REQUIRED ON              # Require C++17 support
)

# Set include directories
# PUBLIC: for header files that others would need if using our library
# PRIVATE: for header files only used internally
target_include_directories(file_archiver
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include      # For future public headers
    PRIVATE  
        ${CMAKE_CURRENT_SOURCE_DIR}      # For private headers in src/
)

# Print executable information
message(STATUS "Created executable: file_archiver")
message(STATUS "  - Output: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/file_archiver")
message(STATUS "  - C++ standard: C++${CMAKE_CXX_STANDARD}")

# Installation instructions (for later use)
install(TARGETS file_archiver
    RUNTIME DESTINATION bin
    COMPONENT applications
)