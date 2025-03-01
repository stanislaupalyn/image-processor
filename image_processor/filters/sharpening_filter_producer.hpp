#pragma once

#include "filter_producer.hpp"

/**
 * @class SharpeningFilterProducer
 * @brief A producer class for creating sharpening filters.
 *
 * This class implements the FilterProducer interface and is responsible for
 * creating instances of sharpening filters based on the provided settings.
 */
class SharpeningFilterProducer : public FilterProducer {
public:
    std::unique_ptr<Filter> Produce(const FilterSettings& filter_settings) override;
};
