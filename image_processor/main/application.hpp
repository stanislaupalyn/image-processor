#pragma once

#include <chrono>
#include <stdexcept>

/// Utils and components
#include "application_settings.hpp"
#include "io/bmp.hpp"
#include "core/bmp_image_converter.hpp"
#include "command_line_parser.hpp"
#include "filters/filter.hpp"
#include "factory/filter_factory.hpp"
#include "core/image.hpp"
#include "core/pipeline.hpp"
#include "core/rgb_color.hpp"

/// Filters
#include "filters/crop_filter.hpp"
#include "filters/edge_detection_filter.hpp"
#include "filters/gaussian_blur_filter.hpp"
#include "filters/grayscale_filter.hpp"
#include "filters/negative_filter.hpp"
#include "filters/sharpening_filter.hpp"
#include "filters/fisheye_filter.hpp"

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