#pragma once

#include "filter_producer.hpp"

/**
 * @class CropFilterProducer
 * @brief A producer class for creating crop filters.
 *
 * This class implements the FilterProducer interface and is responsible for
 * creating instances of crop filters based on the provided settings.
 */
class CropFilterProducer : public FilterProducer {
public:
    std::unique_ptr<Filter> Produce(const FilterSettings& filter_settings) override;
};
