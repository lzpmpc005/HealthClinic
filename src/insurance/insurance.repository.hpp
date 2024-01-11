#pragma once

#include "SqliteEntity.hpp"

class InsuranceRepository {
private:
    SqliteORM *orm;
    std::unique_ptr<SqliteEntity> insurance;

public:
    InsuranceRepository(SqliteORM *orm);
    ~InsuranceRepository();

    std::vector<std::map<std::string, std::string>> select(std::vector<std::string> conditions);
    bool insert(std::vector<std::pair<int, std::string>> values);
    bool update(int id, std::vector<std::pair<std::string, std::string>> values);
    bool delete_(int id);
};
