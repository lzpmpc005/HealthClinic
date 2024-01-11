#include "insurance.repository.hpp"

InsuranceRepository::InsuranceRepository(SqliteORM *orm) : orm(orm) {
    this->insurance = this->orm->createEntity("insurance", {{"id", columnTypes::INT, true},
                                                            {"type", columnTypes::TEXT},
                                                            {"claim_status", columnTypes::TEXT},
                                                            {"processing_status", columnTypes::TEXT}});
}

InsuranceRepository::~InsuranceRepository() {}

std::vector<std::map<std::string, std::string>> InsuranceRepository::select(std::vector<std::string> conditions) {
    return this->insurance->select(conditions);
}

bool InsuranceRepository::insert(std::vector<std::pair<int, std::string>> values) {
    return this->insurance->insert(values);
}

bool InsuranceRepository::update(int id, std::vector<std::pair<std::string, std::string>> values) {
    return this->insurance->update(id, values);
}

bool InsuranceRepository::delete_(int id) {
    return this->insurance->delete_(id);
}
