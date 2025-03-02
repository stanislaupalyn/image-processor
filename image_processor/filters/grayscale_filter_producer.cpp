#include "grayscale_filter_producer.hpp"

#include <cassert>

#include "grayscale_filter.hpp"

std::unique_ptr<Filter> GrayscaleFilterProducer::Produce(const FilterSettings& filter_settings) const {
    assert(filter_settings.name_ == "gs");

    if (!filter_settings.arguments_.empty()) {
        throw std::invalid_argument("Wrong number of arguments for grayscale filter.\n");
    }
    return std::make_unique<GrayscaleFilter>();
}