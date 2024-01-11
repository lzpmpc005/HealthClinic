#pragma once

#include "crow.h"
#include "insurance.service.hpp"

class InsuranceController {
private:
    crow::SimpleApp &app;
    std::shared_ptr<InsuranceService> insuranceService;

public:
    InsuranceController(crow::SimpleApp &app, std::shared_ptr<InsuranceService> insuranceService);
    void setupRoutes();


    // other controller methods
};
