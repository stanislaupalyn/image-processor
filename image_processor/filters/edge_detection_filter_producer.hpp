#pragma once

#include "filter_producer.hpp"

/**
 * @class EdgeDetectionFilterProducer
 * @brief A producer class for creating edge detection filters.
 *
 * This class implements the FilterProducer interface and is responsible for
 * creating instances of edge detection filters based on the provided settings.
 */
class EdgeDetectionFilterProducer : public FilterProducer {
public:
    std::unique_ptr<Filter> Produce(const FilterSettings& filter_settings) override;
};
