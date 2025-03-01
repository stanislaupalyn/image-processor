#pragma once

#include "filter_producer.hpp"

class NegativeFilterProducer : public FilterProducer {
public:
    Filter* Produce(const FilterSettings& filter_settings) override;
};
