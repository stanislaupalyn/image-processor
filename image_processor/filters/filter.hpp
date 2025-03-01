#pragma once

#include "core/image.hpp"

/**
 * @class Filter
 * @brief Abstract base class for image filters.
 *
 * This class defines the interface for all image filters.
 * Derived classes must implement the `Apply` method to modify an image.
 */
class Filter {
public:
    virtual ~Filter() = default;
    virtual void Apply(Image& bmp) = 0;
};