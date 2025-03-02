#include "filter_factory.hpp"

void FilterFactory::AddProducer(std::string name, std::unique_ptr<FilterProducer> filter_producer) {
    producer_by_name_.insert({name, std::move(filter_producer)});
}

const FilterProducer& FilterFactory::GetProducer(const std::string& name) {
    if (!producer_by_name_.contains(name)) {
        throw std::invalid_argument("Filter with the given name does not exist.\n");
    }
    return *producer_by_name_[name];
}