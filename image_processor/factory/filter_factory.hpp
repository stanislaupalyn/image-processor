#pragma once

#include <functional>
#include <map>

#include "filters/filter.hpp"
#include "filters/filter_settings.hpp"
#include "main/error_code.hpp"

using FilterProducer = std::function<Filter*(const FilterSettings&, ErrorCode&)>;

class FilterFactory {
public:
    void AddProducer(std::string name, FilterProducer filter_producer);
    FilterProducer GetProducer(const std::string& name);

private:
    std::map<std::string, FilterProducer> producer_by_name_;
};
