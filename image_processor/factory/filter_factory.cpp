#include "filter_factory.hpp"

void FilterFactory::AddProducer(std::string name, FilterProducer* filter_producer) {
    producer_by_name_.insert({name, filter_producer});
}
FilterProducer* FilterFactory::GetProducer(const std::string& name) {
    if (!producer_by_name_.contains(name)) {
        throw std::invalid_argument("Filter with the given name does not exist.\n");
    }
    return producer_by_name_[name];
}

FilterFactory::~FilterFactory() {
    for (const auto& [name, producer] : producer_by_name_) {
        delete producer;
    }
}