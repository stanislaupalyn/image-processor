#pragma once

#include <chrono>
#include <stdexcept>

/// Utils and components
#include "application_settings.h"
#include "io/bmp.h"
#include "core/bmp_image_converter.h"
#include "command_line_parser.h"
#include "filters/filter.h"
#include "factory/filter_factory.h"
#include "core/image.h"
#include "core/pipeline.h"
#include "core/rgb_color.h"

/// Filters
#include "filters/crop_filter.h"
#include "filters/edge_detection_filter.h"
#include "filters/gaussian_blur_filter.h"
#include "filters/grayscale_filter.h"
#include "filters/negative_filter.h"
#include "filters/sharpening_filter.h"
#include "filters/fisheye_filter.h"

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
    void Start(int argc, char* argv[]);
};