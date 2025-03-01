#pragma once

#include "filter.hpp"
#include "filter_settings.hpp"
#include "main/error_code.hpp"

/**
 * @class SharpeningFilter
 * @brief A filter that sharpens an image by enhancing its edges.
 *
 * This filter enhances the edges in an image, making the image appear sharper.
 * It does so by applying a convolution operation using a sharpening kernel.
 */
class SharpeningFilter : public Filter {
public:
    SharpeningFilter() {
    }
    void Apply(Image& image) override;

protected:
    static constexpr double FILTER_MATRIX[3][3] = {// NOLINT
                                                   {0.0, -1.0, 0.0},
                                                   {-1.0, 5.0, -1.0},
                                                   {0.0, -1.0, 0.0}};
};

Filter* ProduceSharpeningFilter(const FilterSettings& filter_settings, ErrorCode& error);