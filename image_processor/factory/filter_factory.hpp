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
    void AddProducer(std::string name, std::unique_ptr<FilterProducer> filter_producer);
    FilterProducer* GetProducer(const std::string& name);

private:
    std::map<std::string, std::unique_ptr<FilterProducer>> producer_by_name_;
};
