#pragma once

/**
 * @struct FilterSettings
 * @brief Structure to hold filter settings.
 *
 * This structure holds the name and arguments associated with a filter. It is used
 * to pass configuration information for filters, including the filter's name
 * and any necessary parameters.
 */
struct FilterSettings {
    std::string name_;
    std::vector<std::string> arguments_;
};
