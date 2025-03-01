#include "pipeline.hpp"

void Pipeline::ApplyPipeline(Image& image) const {
    for (const std::unique_ptr<Filter>& filter : filters_) {
        filter->Apply(image);
    }
}