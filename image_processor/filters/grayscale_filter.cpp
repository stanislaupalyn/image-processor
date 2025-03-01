#include "grayscale_filter.hpp"

void GrayscaleFilter::Apply(Image& image) {
    for (size_t row = 0; row < image.GetHeight(); ++row) {
        for (size_t col = 0; col < image.GetWidth(); ++col) {
            double value =
                BLUE_COEF * image(row, col).b_ + GREEN_COEF * image(row, col).g_ + RED_COEF * image(row, col).r_;
            image(row, col) = {value, value, value};
        }
    }
}