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
    void Config();

    ErrorCode Start(int argc, char* argv[]);
};