#pragma once

#include "filter.hpp"
#include "filter_settings.hpp"
#include "main/error_code.hpp"

class NegativeFilter : public Filter {
public:
    NegativeFilter() {
    }
    void Apply(Image& image) override;

protected:
};

Filter* ProduceNegativeFilter(const FilterSettings& filter_settings, ErrorCode& error);