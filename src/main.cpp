/**
 * @file main.cpp
 * @brief File Archiever - Main entry point
 *
 * A modern C++ file archiever with compression capabilities.
 * This is the starting point of our application.
 */

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Prints the program banner
 */

void print_banner()
{
    std::cout << "=========================================\n";
    std::cout << "        File Archiver v1.0.0\n";
    std::cout << "     Modern C++ Compression Tool\n";
    std::cout << "=========================================\n";
}

/**
 * @brief Prints usage instructions
 */

void print_help()
{
    std::cout << "\nUsage:\n";
    std::cout << "  file_archiver [command] [options] [files...]\n\n";
    std::cout << "Commands:\n";
    std::cout << "  create    Create a new archive\n";
    std::cout << "  extract   Extract files from archive\n";
    std::cout << "  list      List contents of archive\n";
    std::cout << "  help      Show this help message\n\n";
    std::cout << "Examples:\n";
    std::cout << "  file_archiver create archive.far file1.txt file2.txt\n";
    std::cout << "  file_archiver extract archive.far\n";
    std::cout << "  file_archiver list archive.far\n";
    std::cout << "  file_archiver help\n\n";
    std::cout << "Options:\n";
    std::cout << "  --version   Show version information\n";
    std::cout << "  -h, --help  Show this help message\n";
}

/**
 * @brief Prints version information
 */
void print_version()
{
    std::cout << "File Archiver v1.0.0\n";
    std::cout << "Built with C++17 and CMake\n";
}

/**
 * @brief Main program entry point
 * @param argc Argument count
 * @param argv Argument values
 * @return Exit code (0 for success, non-zero for error)
 */

int main(int argc, char *argv[])
{
    // Print banner on every run
    print_banner();

    // Handle no arguments
    if (argc < 2)
    {
        std::cerr << "Error: No command provided.\n";
        print_help();
        return 1;
    }

    // Get the command
    std::string command = argv[1];

    // Handle help commands
    if (command == "help" || command == "--help" || command == "-h")
    {
        print_help();
        return 0;
    }

    // Handle version command
    if (command == "--version")
    {
        print_version();
        return 0;
    }

    // Handle known commands
    if (command == "create" || command == "extract" || command == "list")
    {
        std::cout << "Command received: " << command << "\n";
        std::cout << "Note: This is a project skeleton. ";
        std::cout << "Full implementation coming in future weeks!\n";

        // Show what files would be processed
        if (argc > 2)
        {
            std::cout << "Files specified: ";
            for (int i = 2; i < argc; ++i)
            {
                std::cout << argv[i] << " ";
            }
            std::cout << "\n";
        }

        return 0;
    }

    // Handle unknown command
        std::cerr << "Error: Unknown command '" << command << "'\n\n";
        print_help();
        return 1;
}
