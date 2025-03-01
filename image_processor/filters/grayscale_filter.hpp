#pragma once

#include "filter.hpp"
#include "filter_settings.hpp"
#include "main/error_code.hpp"

/**
 * @class GrayscaleFilter
 * @brief A filter that converts an image to grayscale.
 *
 * This filter converts an image to grayscale by computing a weighted sum of the
 * red, green, and blue channels.
 */
class GrayscaleFilter : public Filter {
public:
    GrayscaleFilter() {
    }
    void Apply(Image& image) override;

protected:
    static constexpr double RED_COEF = 0.299;    // NOLINT
    static constexpr double GREEN_COEF = 0.587;  // NOLINT
    static constexpr double BLUE_COEF = 0.114;   // NOLINT
};