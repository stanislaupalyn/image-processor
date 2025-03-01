#pragma once

#include "filter.hpp"
#include "filter_settings.hpp"

class FilterProducer {
public:
    virtual ~FilterProducer() = default;
    virtual Filter* Produce(const FilterSettings&) = 0;
};
