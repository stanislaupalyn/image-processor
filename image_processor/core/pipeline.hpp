#pragma once

#include "filters/filter.hpp"
#include <memory>

/**
 * @class Pipeline
 * @brief Manages and applies a sequence of image filters.
 *
 * The Pipeline class stores a series of filters and applies them sequentially
 * to an image. Filters are applied in the order they are added.
 */
class Pipeline {
public:
    void AddFilter(std::unique_ptr<Filter> filter) {
        filters_.push_back(std::move(filter));
    }
    void ApplyPipeline(Image& image) const;

private:
    std::vector<std::unique_ptr<Filter>> filters_;
};