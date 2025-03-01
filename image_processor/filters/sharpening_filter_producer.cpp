#include "sharpening_filter_producer.hpp"
#include "sharpening_filter.hpp"
#include <cassert>

Filter* SharpeningFilterProducer::Produce(const FilterSettings& filter_settings) {
    assert(filter_settings.name_ == "sharp");

    if (!filter_settings.arguments_.empty()) {
        throw std::invalid_argument("Wrong number of arguments for sharpening filter.\n");
    }
    Filter* filter_ptr = new SharpeningFilter();
    return filter_ptr;
}