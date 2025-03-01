#include "grayscale_filter_producer.hpp"
#include "grayscale_filter.hpp"
#include <cassert>

Filter* GrayscaleFilterProducer::Produce(const FilterSettings& filter_settings) {
    assert(filter_settings.name_ == "gs");

    if (!filter_settings.arguments_.empty()) {
        throw std::invalid_argument("Wrong number of arguments for grayscale filter.\n");
    }
    Filter* filter_ptr = new GrayscaleFilter();
    return filter_ptr;
}