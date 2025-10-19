/**
 * @file cli_parser.h
 * @brief Command-line interface parser for File Archiver
 */

#ifndef CLI_PARSER_H
#define CLI_PARSER_H

#include <string>
#include <vector>
#include <unordered_map>

/**
 * @brief Supported commands for the file archiver
 */
enum class Command
{
    CREATE,  // Create new archive
    EXTRACT, // Extract from archive
    LIST,    // List archive contents
    HELP,    // Show help
    VERSION, // Show version
    UNKNOWN  // Invalid command
};

/**
 * @brief Command-line parsing results
 */
struct ParseResult
{
    Command command;
    std::vector<std::string> files;
    std::string archive_name;
    bool success;
    std::string error_message;

    // Constructor for easy initialization
    ParseResult() : command(Command::UNKNOWN), success(false)
    {
    }
};

/**
 * @brief Command-line interface parser
 *
 * Handles parsing of command-line arguments and validation.
 * This follows the Single Responsibility Principle - focused only on parsing.
 */

class CLIParser
{
public:
    CLIParser();

    /**
     * @brief Parse command-line arguments
     * @param argc Argument count from main()
     * @param argv Argument values from main()
     * @return ParseResult with parsing results and validation
     */
    ParseResult parse(int argc, char *argv[]);

    /**
     * @brief Get detailed help text
     * @return Formatted help string with usage examples
     */
    static std::string get_help();

    /**
     * @brief Get version information
     * @return Version string
     */
    static std::string get_version();

private:
    /**
     * @brief Convert command string to Command enum
     */
    Command parse_command(const std::string &cmd_str) const;

    /**
     * @brief Validate archive filename
     */
    bool validate_archive_name(const std::string &name) const;

    /**
     * @brief Validate create command arguments
     */
    bool validate_create_args(const ParseResult &result) const;

    /**
     * @brief Validate extract/list command arguments
     */
    bool validate_extract_list_args(const ParseResult &result) const;
};

#endif