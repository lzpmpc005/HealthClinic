// StockChecker.cpp
#include "StockChecker.hpp"
#include <iostream>
#include <chrono>
#include <thread>

StockChecker::StockChecker(InventoryManager& manager, const std::string& itemName, int alertThreshold)
        : manager(manager), itemName(itemName), alertThreshold(alertThreshold) {}

void StockChecker::startChecking() {
    while (true) {
        int stockLevel = manager.getStockLevel(itemName);
        if (stockLevel < alertThreshold) {
            std::cout << "Alert: Stock level for " << itemName << " is low! Current level: " << stockLevel << std::endl;
        }

        // 暂停一段时间后再次检查
        std::this_thread::sleep_for(std::chrono::minutes(1));
    }
}
