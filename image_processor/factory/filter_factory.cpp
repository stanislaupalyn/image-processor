#include "filter_factory.hpp"

void FilterFactory::AddProducer(std::string name, FilterProducer filter_producer) {
    producer_by_name_.insert({name, filter_producer});
}
FilterProducer FilterFactory::GetProducer(const std::string& name) {
    if (!producer_by_name_.contains(name)) {
        return nullptr;
    }
    return producer_by_name_[name];
}