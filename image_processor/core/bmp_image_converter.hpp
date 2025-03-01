#pragma once

#include "core/image.hpp"
#include "io/bmp.hpp"

/**
 * @class BMPImageConverter
 * @brief Provides functionality to convert between BMP images and Image objects.
 *
 * This class contains static methods to convert between the custom `Image` class
 * and the BMP format, enabling the transformation of BMP data into `Image` objects
 * and vice versa.
 */
class BMPImageConverter {
public:
    static Image GetImageFromBMP(const BMP& bmp);
    static BMP GetBMPFromImage(const Image& image, const BMP::BMPHeader& reference_bmp_header,
                               const BMP::DIBHeader& reference_dib_header);

protected:
};