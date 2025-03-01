#include "negative_filter_producer.hpp"

#include <cassert>

#include "negative_filter.hpp"

std::unique_ptr<Filter> NegativeFilterProducer::Produce(const FilterSettings& filter_settings) {
    assert(filter_settings.name_ == "neg");

    if (!filter_settings.arguments_.empty()) {
        throw std::invalid_argument("Wrong number of arguments for negative filter.\n");
    }
    return std::make_unique<NegativeFilter>();
}