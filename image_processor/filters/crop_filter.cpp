#include "crop_filter.hpp"

#include <cassert>
#include <iostream>

#include "main/error_code.hpp"

void CropFilter::Apply(Image& image) {
    if (image.GetHeight() > height_) {
        size_t extra = image.GetHeight() - height_;
        image.SetHeight(height_);
        image.GetData().erase(
            image.GetData().begin(),
            image.GetData().begin() + static_cast<int32_t>(extra) * static_cast<int32_t>(image.GetWidth()));
    }

    if (image.GetWidth() > width_) {
        std::vector<RGBReal> new_data;

        for (size_t row = 0; row < image.GetHeight(); ++row) {
            for (size_t col = 0; col < width_; ++col) {
                new_data.push_back(image(row, col));
            }
        }
        image.SetWidth(width_);
        image.GetData() = new_data;
    }
}

Filter* ProduceCropFilter(const FilterSettings& filter_settings, ErrorCode& error) {
    assert(filter_settings.name_ == "crop");

    if (filter_settings.arguments_.size() != 2) {
        std::cerr << "Wrong number of arguments for crop filter.\n";
        error = ErrorCode::INVALID_ARGUMENTS;
        return nullptr;
    }
    int32_t width = std::stoi(filter_settings.arguments_[0]);
    int32_t height = std::stoi(filter_settings.arguments_[1]);

    if (width <= 0 || height <= 0) {
        std::cerr << "Width and height should be positive in crop filter.\n";
        error = ErrorCode::INVALID_ARGUMENTS;
        return nullptr;
    }

    Filter* filter_ptr = new CropFilter(static_cast<size_t>(width), static_cast<size_t>(height));
    error = ErrorCode::SUCCESS;
    return filter_ptr;
}