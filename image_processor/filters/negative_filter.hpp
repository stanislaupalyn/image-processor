#pragma once

#include "filter.hpp"

/**
 * @class NegativeFilter
 * @brief A filter that applies a negative effect to an image.
 *
 * This filter inverts the colors of the image, producing a "negative" effect.
 * Each pixel's color values (red, green, blue) are replaced by their respective
 * complements (255 - color_value).
 */
class NegativeFilter : public Filter {
public:
    NegativeFilter() {
    }
    void Apply(Image& image) override;

protected:
};