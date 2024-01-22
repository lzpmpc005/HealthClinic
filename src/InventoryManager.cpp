// InventoryManager.cpp
#include "InventoryManager.hpp"

void InventoryManager::addItem(const std::string& itemName, int initialQuantity) {
    stockLevels[itemName] = initialQuantity;
}

int InventoryManager::getStockLevel(const std::string& itemName) const {
    auto it = stockLevels.find(itemName);
    return (it != stockLevels.end()) ? it->second : 0;
}

void InventoryManager::decreaseStock(const std::string& itemName, int quantity) {
    auto it = stockLevels.find(itemName);
    if (it != stockLevels.end()) {
        it->second = std::max(0, it->second - quantity);
    }
}
