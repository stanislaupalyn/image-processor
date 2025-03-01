#include "crop_filter.hpp"

#include <iostream>

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