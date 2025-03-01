#pragma once

#include <cmath>
#include <cstdint>

class RGBReal;
class RGB24;

/**
 * @class RGBReal
 * @brief Represents a color with real-number precision for RGB channels.
 *
 * This class represents a color using floating-point precision for the red, green, and blue channels.
 */
class RGBReal {
public:
    static constexpr double MaxColorValue = 255.0;

    double b_;
    double g_;
    double r_;

    explicit operator RGB24() const;

private:
};

/**
 * @class RGB24
 * @brief Represents a color with 8-bit precision for RGB channels.
 *
 * This class represents a color using 8-bit integer values (0-255) for each of the red, green, and blue channels.
 */
class RGB24 {
public:
    uint8_t b_;
    uint8_t g_;
    uint8_t r_;

    explicit operator RGBReal() const;
} __attribute__((packed));