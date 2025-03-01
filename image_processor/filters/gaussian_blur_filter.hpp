#pragma once

#include "filter.hpp"

/**
 * @class GaussianBlurFilter
 * @brief A filter that applies Gaussian blur to an image.
 *
 * This filter applies a Gaussian blur to an image, which is a common image
 * processing technique used to reduce noise and detail. The blur strength is
 * controlled by the sigma value, which defines the width of the Gaussian distribution.
 */
class GaussianBlurFilter : public Filter {
public:
    explicit GaussianBlurFilter(double sigma);
    void Apply(Image& image) override;
    static constexpr double MAX_SIGMA_VALUE = 100.0;  // NOLINT

protected:
    static constexpr double SIGMA_SIZE_CONST = 6.0;  // NOLINT
    std::vector<double> filter_vector;
};