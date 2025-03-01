#pragma once

#include <functional>
#include <map>

#include "filters/filter_producer.hpp"
/**
 * @class FilterFactory
 * @brief Factory class responsible for creating image filters.
 *
 * This class manages filter producers and creates filters based on provided settings.
 * It stores filter producers and allows them to be accessed by filter name.
 */
class FilterFactory {
public:
    void AddProducer(std::string name, FilterProducer* filter_producer);
    FilterProducer* GetProducer(const std::string& name);
    ~FilterFactory();

private:
    std::map<std::string, FilterProducer*> producer_by_name_;
};
