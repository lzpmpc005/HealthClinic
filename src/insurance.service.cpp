#include "insurance.service.hpp"

InsuranceService::InsuranceService(std::shared_ptr<InsuranceRepository> repository)
        : repository(repository) {}

std::string InsuranceService::chooseInsurance(std::string patient_id, std::string insurance_type) {
    // 实现 chooseInsurance 函数
    return "";  // 临时返回空字符串，确保函数有返回值
}

std::string InsuranceService::submitClaim(std::string patient_id) {
    // 实现 submitClaim 函数
    return "";  // 临时返回空字符串，确保函数有返回值
}

std::string InsuranceService::reviewClaim(std::string patient_id) {
    // 实现 reviewClaim 函数
    return "";  // 临时返回空字符串，确保函数有返回值
}

std::string InsuranceService::approveClaim(std::string patient_id) {
    // 实现 approveClaim 函数
    return "";  // 临时返回空字符串，确保函数有返回值
}
