#pragma once

/// Utils and components
#include "application_settings.hpp"
#include "command_line_parser.hpp"
#include "core/bmp_image_converter.hpp"
#include "core/pipeline.hpp"
#include "factory/filter_factory.hpp"

class Application {
private:
    ApplicationSettings app_settings_;
    CommandLineParser cl_parser_;
    FilterFactory f_factory_;
    Pipeline pipeline_;
    BMPImageConverter bmp_image_converter_;

public:
    /// Initial app setup. Adds a mapping in the FilterFactory between
    /// each filter's command line argument name and corresponding filter producer
    void Config();

    /// Called only once. Starts the application from command line arguments
    ErrorCode Start(int argc, char* argv[]);
};