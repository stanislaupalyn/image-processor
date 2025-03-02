#pragma once

#include "filter.hpp"

/**
 * @class CropFilter
 * @brief A filter that crops an image to the specified width and height.
 *
 * This filter modifies the image by cropping it to the dimensions specified
 * during its initialization. The crop is applied from the top-left corner of the image.
 */
class CropFilter : public Filter {
public:
    CropFilter(size_t width, size_t height) : width_(width), height_(height) {
    }
    void Apply(Image& image) override;

protected:
    size_t width_;
    size_t height_;
};