#include "insurance.controller.hpp"

InsuranceController::InsuranceController(crow::SimpleApp &app, std::shared_ptr<InsuranceService> insuranceService)
        : app(app), insuranceService(insuranceService) {
    setupRoutes();
}

void InsuranceController::setupRoutes() {

    CROW_ROUTE(this->app, "/insurance/choose").methods(crow::HTTPMethod::POST)([&](const crow::request &req, crow::response &res) {

        // this->insuranceService
    });

    // other route way (related)
}
