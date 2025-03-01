#pragma once

#include "filter_producer.hpp"

class EdgeDetectionFilterProducer : public FilterProducer {
public:
    Filter* Produce(const FilterSettings& filter_settings) override;
};
