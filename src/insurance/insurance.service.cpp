#include "insurance.service.hpp"

InsuranceService::InsuranceService(std::shared_ptr<InsuranceRepository> repository)
        : repository(repository) {
    //

std::string InsuranceService::chooseInsurance(std::string patient_id, std::string insurance_type) {

    return "Insurance chosen successfully for patient: " + patient_id;
}

std::string InsuranceService::submitClaim(std::string patient_id) {

    return "Claim submitted successfully for patient: " + patient_id;
}

std::string InsuranceService::reviewClaim(std::string patient_id) {

    return "Claim reviewed successfully for patient: " + patient_id;
}

std::string InsuranceService::approveClaim(std::string patient_id) {

    return "Claim approved successfully for patient: " + patient_id;
}