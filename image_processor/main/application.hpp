#pragma once

/// Utils and components
#include "application_settings.hpp"
#include "command_line_parser.hpp"
#include "core/bmp_image_converter.hpp"
#include "core/pipeline.hpp"
#include "factory/filter_factory.hpp"

/**
 * @class Application
 * @brief Manages the configuration and execution of the Image Processor application.
 *
 * This class handles command-line argument parsing, pipeline execution,
 * and image processing using various filters.
 */
class Application {
private:
    ApplicationSettings app_settings_;
    CommandLineParser cl_parser_;
    FilterFactory f_factory_;
    Pipeline pipeline_;
    BMPImageConverter bmp_image_converter_;

public:
    /**
     * @brief Configures the application settings.
     *
     * This method initializes necessary components before execution.
     * In particular maps filter names to corresponding producers.
     */
    void Config();

    ErrorCode Start(int argc, char* argv[]);
};