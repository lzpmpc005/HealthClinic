#pragma once

#include <memory>
#include "insurance.repository.hpp"

class InsuranceService {
private:
    std::shared_ptr<InsuranceRepository> repository;

public:
    InsuranceService(std::shared_ptr<InsuranceRepository> repository);
    std::string chooseInsurance(std::string patient_id, std::string insurance_type);
    std::string submitClaim(std::string patient_id);
    std::string reviewClaim(std::string patient_id);
    std::string approveClaim(std::string patient_id);
};
