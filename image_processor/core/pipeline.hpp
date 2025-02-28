#pragma once

#include "filters/filter.hpp"

class Pipeline {
public:
    ~Pipeline();
    void AddFilter(Filter* filter) {
        filters_.push_back(filter);
    }
    void ApplyPipeline(Image& image);

private:
    std::vector<Filter*> filters_;
};