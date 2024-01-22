// StockChecker.hpp
#ifndef STOCK_CHECKER_HPP
#define STOCK_CHECKER_HPP

#include "InventoryManager.hpp"

class StockChecker {
public:
    StockChecker(InventoryManager& manager, const std::string& itemName, int alertThreshold);
    void startChecking();
private:
    InventoryManager& manager;
    std::string itemName;
    int alertThreshold;
};

#endif // STOCK_CHECKER_HPP
