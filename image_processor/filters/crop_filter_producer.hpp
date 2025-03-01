#pragma once

#include "filter_producer.hpp"

class CropFilterProducer : public FilterProducer {
public:
    Filter* Produce(const FilterSettings& filter_settings) override;
};
