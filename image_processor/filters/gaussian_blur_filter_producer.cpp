#include "gaussian_blur_filter_producer.hpp"

#include <cassert>

#include "gaussian_blur_filter.hpp"

Filter* GaussianBlurFilterProducer::Produce(const FilterSettings& filter_settings) {
    assert(filter_settings.name_ == "blur");

    if (filter_settings.arguments_.size() != 1) {
        throw std::invalid_argument("Wrong number of arguments for Gaussian blur filter.\n");
    }
    double sigma = std::stod(filter_settings.arguments_[0]);

    if (sigma <= 0) {
        throw std::invalid_argument("Sigma in the gaussian blur filter should be positive.\n");
    }
    if (sigma > GaussianBlurFilter::MAX_SIGMA_VALUE) {
        throw std::invalid_argument("Sigma exceeds the maximum specified value (equals " +
                                    std::to_string(GaussianBlurFilter::MAX_SIGMA_VALUE) +
                                    ") for the Gaussian blur filter.\n");
    }
    Filter* filter_ptr = new GaussianBlurFilter(sigma);
    return filter_ptr;
}