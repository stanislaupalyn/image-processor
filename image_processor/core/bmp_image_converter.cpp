#include "bmp_image_converter.hpp"

Image BMPImageConverter::GetImageFromBMP(const BMP& bmp) {
    Image image;

    image.SetWidth(bmp.GetDIBHeader().width);
    image.SetHeight(bmp.GetDIBHeader().height);
    image.GetData().resize(image.GetHeight() * image.GetWidth());

    for (size_t i = 0; i < image.GetData().size(); ++i) {
        image.GetData()[i] = static_cast<RGBReal>(bmp.GetData()[i]);
    }
    return image;
}

BMP BMPImageConverter::GetBMPFromImage(const Image& image, const BMP::BMPHeader& reference_bmp_header,
                                       const BMP::DIBHeader& reference_dib_header) {
    BMP bmp;

    bmp.GetBMPHeader() = reference_bmp_header;
    bmp.GetDIBHeader() = reference_dib_header;

    bmp.GetDIBHeader().height = static_cast<int32_t>(image.GetHeight());
    bmp.GetDIBHeader().width = static_cast<int32_t>(image.GetWidth());

    bmp.GetData().resize(image.GetHeight() * image.GetWidth());

    for (size_t i = 0; i < image.GetData().size(); ++i) {
        bmp.GetData()[i] = static_cast<RGB24>(image.GetData()[i]);
    }
    return bmp;
}