#pragma once

#include <iostream>

#include "application_settings.hpp"
#include "error_code.hpp"

/**
 * @class CommandLineParser
 * @brief Parses command-line arguments and extracts application settings.
 *
 * This class processes command-line inputs to configure application settings,
 * including file paths and filter options.
 */
class CommandLineParser {

public:
    /**
     * @brief Parses command-line arguments and updates application settings.
     *
     * This method extracts the input and output file paths, as well as filter configurations,
     * from the provided command-line arguments.
     *
     * @param argc The number of command-line arguments.
     * @param argv The array of command-line arguments.
     * @param app_settings Reference to an ApplicationSettings object to store parsed values.
     * @return An ErrorCode indicating success or failure of the parsing operation.
     */
    static ErrorCode Parse(int argc, char* argv[], ApplicationSettings& app_settings);

protected:
    static bool IsFilterName(const std::string& s);
};