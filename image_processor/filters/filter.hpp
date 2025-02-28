#pragma once

#include "core/image.hpp"

class Filter {
public:
    virtual ~Filter() = default;
    virtual void Apply(Image& bmp) = 0;
};