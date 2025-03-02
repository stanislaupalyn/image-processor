#include "fisheye_filter_producer.hpp"

#include <cassert>

#include "fisheye_filter.hpp"

std::unique_ptr<Filter> FisheyeFilterProducer::Produce(const FilterSettings& filter_settings) const {
    assert(filter_settings.name_ == "fisheye");

    if (filter_settings.arguments_.size() != 3) {
        throw std::invalid_argument("Wrong number of arguments for fisheye filter.\n");
    }

    double alpha = std::stod(filter_settings.arguments_[0]);
    double center_x = std::stod(filter_settings.arguments_[1]);
    double center_y = std::stod(filter_settings.arguments_[2]);

    if (alpha <= 0) {
        throw std::invalid_argument("Alpha in the fisheye filter should be positive.\n");
    }
    if (center_x < 0 || center_y < 0) {
        throw std::invalid_argument("Coordinates (center_x, center_y) in the fisheye filter should be non-negative.\n");
    }
    if (alpha >= std::min(center_x, center_y)) {
        throw std::invalid_argument(
            "Alpha in the fisheye filter should be strictly less than minimal of (center_x, center_y)\n");
    }

    return std::make_unique<FisheyeFilter>(alpha, center_x, center_y);
}
