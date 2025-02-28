#include "io/bmp.h"
#include "core/image.h"

class BMPImageConverter {
public:
    Image GetImageFromBMP(const BMP& bmp);
    BMP GetBMPFromImage(const Image& image, BMP::BMPHeader reference_bmp_header, BMP::DIBHeader reference_dib_header);

protected:
};