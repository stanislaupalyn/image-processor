#include "negative_filter.hpp"

#include <cassert>
#include <iostream>

#include "main/error_code.hpp"

void NegativeFilter::Apply(Image& image) {
    for (size_t row = 0; row < image.GetHeight(); ++row) {
        for (size_t col = 0; col < image.GetWidth(); ++col) {
            image(row, col) = {1.0 - image(row, col).b_, 1.0 - image(row, col).g_, 1.0 - image(row, col).r_};
        }
    }
}

Filter* ProduceNegativeFilter(const FilterSettings& filter_settings, ErrorCode& error) {
    assert(filter_settings.name_ == "neg");

    if (!filter_settings.arguments_.empty()) {
        std::cerr << "Wrong number of arguments for negative filter.\n";
        error = ErrorCode::INVALID_ARGUMENTS;
        return nullptr;
    }
    Filter* filter_ptr = new NegativeFilter();
    error = ErrorCode::SUCCESS;
    return filter_ptr;
}