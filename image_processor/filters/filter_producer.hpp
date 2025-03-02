#pragma once

#include <memory>

#include "filter.hpp"
#include "filter_settings.hpp"

/**
 * @class FilterProducer
 * @brief Abstract base class for filter producers.
 *
 * This class defines an interface for producing filters based on given settings.
 * Derived classes must implement the Produce method to create specific types of filters.
 */
class FilterProducer {
public:
    virtual ~FilterProducer() = default;
    virtual std::unique_ptr<Filter> Produce(const FilterSettings&) = 0;
};
