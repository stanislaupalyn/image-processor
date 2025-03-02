#pragma once

#include "filter.hpp"

/**
 * @class EdgeDetectionFilter
 * @brief A filter that applies edge detection to an image.
 *
 * This filter applies an edge detection algorithm (using a 3x3 kernel matrix) to
 * an image. The filter detects edges in the image and applies a threshold to
 * determine which edges are visible.
 */
class EdgeDetectionFilter : public Filter {
public:
    explicit EdgeDetectionFilter(double threshold) : threshold_{threshold} {
    }
    void Apply(Image& image) override;

protected:
    static constexpr double FILTER_MATRIX[3][3] = {// NOLINT
                                                   {0.0, -1.0, 0.0},
                                                   {-1.0, 4.0, -1.0},
                                                   {0.0, -1.0, 0.0}};
    double threshold_;
};