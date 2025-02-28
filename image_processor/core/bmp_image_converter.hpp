#pragma once

#include "core/image.hpp"
#include "io/bmp.hpp"

class BMPImageConverter {
public:
    static Image GetImageFromBMP(const BMP& bmp);
    static BMP GetBMPFromImage(const Image& image, const BMP::BMPHeader& reference_bmp_header,
                               const BMP::DIBHeader& reference_dib_header);

protected:
};