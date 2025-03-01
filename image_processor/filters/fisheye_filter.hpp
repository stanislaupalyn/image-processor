#pragma once

#include "filter.hpp"
#include "filter_settings.hpp"
#include "main/error_code.hpp"

/**
 * @class FisheyeFilter
 * @brief A filter that applies a fisheye lens effect to an image.
 *
 * This filter distorts the image using a fisheye lens transformation, creating
 * a bulging, spherical effect. The transformation is controlled by parameters
 * such as alpha (strength of the effect) and the center of the distortion.
 */
class FisheyeFilter : public Filter {
public:
    explicit FisheyeFilter(double alpha, double center_x, double center_y)
        : alpha_{alpha}, center_x_{center_x}, center_y_{center_y}, x_scale_(0), x_shift_(0), y_scale_(0), y_shift_(0) {
    }
    void Apply(Image& image) override;

protected:
    double alpha_;
    double center_x_, center_y_;

    double x_scale_, x_shift_;
    double y_scale_, y_shift_;

    static RGBReal GetPixel(double x, double y, const Image& image);
    double CalcShift(double x1, double x2, double cx) const;
    double GetRadialX(double x, double y) const;
    double GetRadialY(double x, double y) const;
};

Filter* ProduceFisheyeFilter(const FilterSettings& filter_settings, ErrorCode& error);