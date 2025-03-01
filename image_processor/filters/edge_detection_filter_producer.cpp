#include "edge_detection_filter_producer.hpp"

#include <cassert>

#include "edge_detection_filter.hpp"

std::unique_ptr<Filter> EdgeDetectionFilterProducer::Produce(const FilterSettings& filter_settings) {
    assert(filter_settings.name_ == "edge");

    if (filter_settings.arguments_.size() != 1) {
        throw std::invalid_argument("Wrong number of arguments for edge detection filter.\n");
    }

    double threshold = std::stod(filter_settings.arguments_[0]);
    if (threshold < 0 || threshold > 1) {
        throw std::invalid_argument("Threshold in the edge detection filter should be in segment [0, 1].\n");
    }

    return std::make_unique<EdgeDetectionFilter>(threshold);
}