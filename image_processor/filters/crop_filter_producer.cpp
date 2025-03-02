#include "crop_filter_producer.hpp"

#include <cassert>

#include "crop_filter.hpp"

std::unique_ptr<Filter> CropFilterProducer::Produce(const FilterSettings& filter_settings) const {
    assert(filter_settings.name_ == "crop");

    if (filter_settings.arguments_.size() != 2) {
        throw std::invalid_argument("Wrong number of arguments for crop filter.\n");
    }
    int32_t width = std::stoi(filter_settings.arguments_[0]);
    int32_t height = std::stoi(filter_settings.arguments_[1]);

    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Width and height should be positive in crop filter.\n");
    }

    return std::make_unique<CropFilter>(static_cast<size_t>(width), static_cast<size_t>(height));
}