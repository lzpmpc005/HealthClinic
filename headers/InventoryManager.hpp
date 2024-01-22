// InventoryManager.hpp
#ifndef INVENTORY_MANAGER_HPP
#define INVENTORY_MANAGER_HPP

#include <string>
#include <unordered_map>

class InventoryManager {
public:
    void addItem(const std::string& itemName, int initialQuantity);
    int getStockLevel(const std::string& itemName) const;
    void decreaseStock(const std::string& itemName, int quantity);
private:
    std::unordered_map<std::string, int> stockLevels;
};

#endif // INVENTORY_MANAGER_HPP
