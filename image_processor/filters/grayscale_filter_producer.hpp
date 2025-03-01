#pragma once

#include "filter_producer.hpp"

/**
 * @class GrayscaleFilterProducer
 * @brief A producer class for creating grayscale filters.
 *
 * This class implements the FilterProducer interface and is responsible for
 * creating instances of grayscale filters based on the provided settings.
 */
class GrayscaleFilterProducer : public FilterProducer {
public:
    std::unique_ptr<Filter> Produce(const FilterSettings& filter_settings) override;
};
