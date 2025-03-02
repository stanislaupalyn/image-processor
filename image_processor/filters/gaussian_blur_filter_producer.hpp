#pragma once

#include "filter_producer.hpp"

/**
 * @class GaussianBlurFilterProducer
 * @brief A producer class for creating gaussian blur filters.
 *
 * This class implements the FilterProducer interface and is responsible for
 * creating instances of gaussian blur filters based on the provided settings.
 */
class GaussianBlurFilterProducer : public FilterProducer {
public:
    std::unique_ptr<Filter> Produce(const FilterSettings& filter_settings) const override;
};
