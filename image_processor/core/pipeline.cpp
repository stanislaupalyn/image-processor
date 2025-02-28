#include "pipeline.hpp"

Pipeline::~Pipeline() {
    for (Filter* filter : filters_) {
        delete filter;
    }
}

void Pipeline::ApplyPipeline(Image& image) const {
    for (Filter* filter : filters_) {
        filter->Apply(image);
    }
}