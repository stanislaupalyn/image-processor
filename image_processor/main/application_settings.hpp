#pragma once

#include <string>

#include "filters/filter.hpp"
#include "filters/filter_settings.hpp"

/**
 * @struct ApplicationSettings
 * @brief Stores configuration settings for the application.
 *
 * This struct holds file paths and filter settings used during image processing.
 */
struct ApplicationSettings {
    std::string input_file_path_;
    std::string output_file_path_;
    std::vector<FilterSettings> filters_settings_;
};