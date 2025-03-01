#include "negative_filter_producer.hpp"
#include "negative_filter.hpp"
#include <cassert>

Filter* NegativeFilterProducer::Produce(const FilterSettings& filter_settings) {
    assert(filter_settings.name_ == "neg");

    if (!filter_settings.arguments_.empty()) {
        throw std::invalid_argument("Wrong number of arguments for negative filter.\n");
    }
    Filter* filter_ptr = new NegativeFilter();
    return filter_ptr;
}