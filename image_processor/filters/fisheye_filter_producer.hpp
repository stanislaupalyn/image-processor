#pragma once

#include "filter_producer.hpp"

/**
 * @class FisheyeFilterProducer
 * @brief A producer class for creating fisheye filters.
 *
 * This class implements the FilterProducer interface and is responsible for
 * creating instances of fisheye filters based on the provided settings.
 */
class FisheyeFilterProducer : public FilterProducer {
public:
    std::unique_ptr<Filter> Produce(const FilterSettings& filter_settings) const override;
};
