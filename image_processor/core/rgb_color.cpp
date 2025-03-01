#include "rgb_color.hpp"

#include <cmath>

RGBReal::operator RGB24() const {
    return RGB24{static_cast<uint8_t>(std::round(MaxColorValue * b_)),
                 static_cast<uint8_t>(std::round(MaxColorValue * g_)),
                 static_cast<uint8_t>(std::round(MaxColorValue * r_))};
}

RGB24::operator RGBReal() const {
    return RGBReal{static_cast<double>(b_) / RGBReal::MaxColorValue, static_cast<double>(g_) / RGBReal::MaxColorValue,
                   static_cast<double>(r_) / RGBReal::MaxColorValue};
}