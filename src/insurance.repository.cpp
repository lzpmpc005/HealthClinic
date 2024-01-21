#include "insurance.repository.hpp"

InsuranceRepository::InsuranceRepository(SqliteORM *orm) : orm(orm) {
    this->insurance = std::unique_ptr<SqliteEntity>(new SqliteEntity(
            this->orm->getDB(), // 使用 SqliteORM 的 getDB 函数获取数据库指针
            "insurance",
            {
                    {"id", columnTypes::INT, true},
                    {"type", columnTypes::TEXT, false},
                    {"claim_status", columnTypes::TEXT, false},
                    {"processing_status", columnTypes::TEXT, false}
            }
    ));
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

