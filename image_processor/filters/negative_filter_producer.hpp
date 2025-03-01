#pragma once

#include "filter_producer.hpp"

/**
 * @class NegativeFilterProducer
 * @brief A producer class for creating negative filters.
 *
 * This class implements the FilterProducer interface and is responsible for
 * creating instances of negative filters based on the provided settings.
 */
class NegativeFilterProducer : public FilterProducer {
public:
    std::unique_ptr<Filter> Produce(const FilterSettings& filter_settings) override;
};
