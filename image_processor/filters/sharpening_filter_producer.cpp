#include "sharpening_filter_producer.hpp"

#include <cassert>

#include "sharpening_filter.hpp"

std::unique_ptr<Filter> SharpeningFilterProducer::Produce(const FilterSettings& filter_settings) {
    assert(filter_settings.name_ == "sharp");

    if (!filter_settings.arguments_.empty()) {
        throw std::invalid_argument("Wrong number of arguments for sharpening filter.\n");
    }

    return std::make_unique<SharpeningFilter>();
}