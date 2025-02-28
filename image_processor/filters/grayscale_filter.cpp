#include "grayscale_filter.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>

#include "main/error_code.hpp"

void GrayscaleFilter::Apply(Image& image) {
    for (size_t row = 0; row < image.GetHeight(); ++row) {
        for (size_t col = 0; col < image.GetWidth(); ++col) {
            double value =
                BLUE_COEF * image(row, col).b_ + GREEN_COEF * image(row, col).g_ + RED_COEF * image(row, col).r_;
            image(row, col) = {value, value, value};
        }
    }
}

Filter* ProduceGrayscaleFilter(const FilterSettings& filter_settings, ErrorCode& error) {
    assert(filter_settings.name_ == "gs");

    if (!filter_settings.arguments_.empty()) {
        std::cerr << "Wrong number of arguments for grayscale filter.\n";
        error = ErrorCode::INVALID_ARGUMENTS;
        return nullptr;
    }
    Filter* filter_ptr = new GrayscaleFilter();
    error = ErrorCode::SUCCESS;
    return filter_ptr;
}