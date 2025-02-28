#include "edge_detection_filter.hpp"

#include <cassert>
#include <iostream>

#include "filters/grayscale_filter.hpp"
#include "main/error_code.hpp"

void EdgeDetectionFilter::Apply(Image& image) {
    GrayscaleFilter gs;
    gs.Apply(image);

    std::vector<RGBReal> new_data(image.GetData().size());

    for (size_t row = 0; row < image.GetHeight(); ++row) {
        for (size_t col = 0; col < image.GetWidth(); ++col) {
            RGBReal sum_color{0, 0, 0};

            for (int32_t i = static_cast<int32_t>(row) - 1; i <= static_cast<int32_t>(row) + 1; ++i) {
                for (int32_t j = static_cast<int32_t>(col) - 1; j <= static_cast<int32_t>(col) + 1; ++j) {
                    int32_t x = i;
                    int32_t y = j;
                    if (x < 0) {
                        ++x;
                    }
                    if (y < 0) {
                        ++y;
                    }
                    if (x >= image.GetHeight()) {
                        --x;
                    }
                    if (y >= image.GetWidth()) {
                        --y;
                    }

                    sum_color.b_ += image(x, y).b_ * FILTER_MATRIX[i - row + 1][j - col + 1];
                    sum_color.g_ += image(x, y).g_ * FILTER_MATRIX[i - row + 1][j - col + 1];
                    sum_color.r_ += image(x, y).r_ * FILTER_MATRIX[i - row + 1][j - col + 1];
                }
            }
            sum_color.b_ = std::max(sum_color.b_, 0.0);
            sum_color.b_ = std::min(sum_color.b_, 1.0);
            sum_color.g_ = std::max(sum_color.g_, 0.0);
            sum_color.g_ = std::min(sum_color.g_, 1.0);
            sum_color.r_ = std::max(sum_color.r_, 0.0);
            sum_color.r_ = std::min(sum_color.r_, 1.0);

            if (sum_color.b_ >= threshold_) {
                sum_color.b_ = 1.0;
            } else {
                sum_color.b_ = 0.0;
            }
            if (sum_color.g_ >= threshold_) {
                sum_color.g_ = 1.0;
            } else {
                sum_color.g_ = 0.0;
            }
            if (sum_color.r_ >= threshold_) {
                sum_color.r_ = 1.0;
            } else {
                sum_color.r_ = 0.0;
            }

            new_data[row * image.GetWidth() + col] = sum_color;
        }
    }

    image.GetData() = new_data;
}

Filter* ProduceEdgeDetectionFilter(const FilterSettings& filter_settings, ErrorCode& error) {
    assert(filter_settings.name_ == "edge");

    if (filter_settings.arguments_.size() != 1) {
        std::cerr << "Wrong number of arguments for edge detection filter.\n";
        error = ErrorCode::INVALID_ARGUMENTS;
        return nullptr;
    }

    double threshold = std::stod(filter_settings.arguments_[0]);
    if (threshold < 0 || threshold > 1) {
        std::cerr << "Threshold in the edge detection filter should be in segment [0, 1].\n";
        error = ErrorCode::INVALID_ARGUMENTS;
        return nullptr;
    }

    Filter* filter_ptr = new EdgeDetectionFilter(threshold);
    error = ErrorCode::SUCCESS;
    return filter_ptr;
}