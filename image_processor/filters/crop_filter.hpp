#pragma once

#include <stdexcept>

#include "filter.hpp"
#include "filter_settings.hpp"
#include "main/error_code.hpp"

class CropFilter : public Filter {
public:
    CropFilter(size_t width, size_t height) : width_(width), height_(height) {
    }
    void Apply(Image& image) override;

protected:
    size_t width_;
    size_t height_;
};

Filter* ProduceCropFilter(const FilterSettings& filter_settings, ErrorCode& error);