#pragma once

#include "filter_producer.hpp"

class GaussianBlurFilterProducer : public FilterProducer {
public:
    Filter* Produce(const FilterSettings& filter_settings) override;
};
