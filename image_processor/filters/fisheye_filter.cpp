#include "fisheye_filter.hpp"

#include <cmath>

RGBReal FisheyeFilter::GetPixel(double x, double y, const Image& image) {
    if (x < 0 || y < 0 || std::floor(x) >= static_cast<double>(image.GetHeight()) ||
        std::floor(y) >= static_cast<double>(image.GetWidth())) {
        return {0, 0, 0};
    }
    return image(static_cast<size_t>(std::floor(x)), static_cast<size_t>(std::floor(y)));
}

double FisheyeFilter::CalcShift(double x_left, double x_right, double cx) const {
    double x_mid = (x_left + x_right) / 2.0;  // NOLINT

    double res1 = x_left + ((x_left - cx) * alpha_ * ((x_left - cx) * (x_left - cx)));
    double res_mid = x_mid + ((x_mid - cx) * alpha_ * ((x_mid - cx) * (x_mid - cx)));

    if (res1 > -1.0 && res1 < 1.0) {  // NOLINT
        return x_left;
    }

    if (res_mid < 0) {
        return CalcShift(x_mid, x_right, cx);
    }
    return CalcShift(x_left, x_mid, cx);
}

double FisheyeFilter::GetRadialX(double x, double y) const {
    x = (x * x_scale_ + x_shift_);
    y = (y * y_scale_ + y_shift_);
    double res =
        x + ((x - center_x_) * alpha_ * ((x - center_x_) * (x - center_x_) + (y - center_y_) * (y - center_y_)));
    return res;
}

double FisheyeFilter::GetRadialY(double x, double y) const {
    x = (x * x_scale_ + x_shift_);
    y = (y * y_scale_ + y_shift_);
    double res =
        y + ((y - center_y_) * alpha_ * ((x - center_x_) * (x - center_x_) + (y - center_y_) * (y - center_y_)));
    return res;
}

void FisheyeFilter::Apply(Image& image) {
    double width = static_cast<double>(image.GetWidth());
    double height = static_cast<double>(image.GetHeight());

    x_shift_ = CalcShift(0, center_x_ - 1.0, center_x_);
    double new_center_x = height - center_x_;
    double x_shift2 = CalcShift(0, new_center_x - 1.0, new_center_x);

    y_shift_ = CalcShift(0, center_y_ - 1.0, center_y_);
    double new_center_y = width - center_y_;
    double y_shift2 = CalcShift(0, new_center_y - 1.0, new_center_y);

    x_scale_ = (height - x_shift_ - x_shift2) / height;
    y_scale_ = (width - y_shift_ - y_shift2) / width;

    std::vector<RGBReal> new_data(image.GetData().size());

    for (size_t row = 0; row < image.GetHeight(); ++row) {
        for (size_t col = 0; col < image.GetWidth(); ++col) {
            double i = static_cast<double>(row);
            double j = static_cast<double>(col);
            double x = GetRadialX(i, j);
            double y = GetRadialY(i, j);
            RGBReal color = GetPixel(x, y, image);

            new_data[row * image.GetWidth() + col] = color;
        }
    }
    image.GetData() = new_data;
}