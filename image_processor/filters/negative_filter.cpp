#include "negative_filter.hpp"

void NegativeFilter::Apply(Image& image) {
    for (size_t row = 0; row < image.GetHeight(); ++row) {
        for (size_t col = 0; col < image.GetWidth(); ++col) {
            image(row, col) = {1.0 - image(row, col).b_, 1.0 - image(row, col).g_, 1.0 - image(row, col).r_};
        }
    }
}