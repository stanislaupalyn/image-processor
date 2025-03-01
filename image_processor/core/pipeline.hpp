#pragma once

#include "filters/filter.hpp"

/**
 * @class Pipeline
 * @brief Manages and applies a sequence of image filters.
 *
 * The Pipeline class stores a series of filters and applies them sequentially
 * to an image. Filters are applied in the order they are added.
 */
class Pipeline {
public:
    ~Pipeline();
    void AddFilter(Filter* filter) {
        filters_.push_back(filter);
    }
    void ApplyPipeline(Image& image) const;

private:
    std::vector<Filter*> filters_;
};