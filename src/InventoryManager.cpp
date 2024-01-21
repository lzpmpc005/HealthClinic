#include "InventoryManager.hpp"
#include <iostream>

void InventoryManager::addItem(const Item& item) {
    items.push_back(item);
}

void InventoryManager::checkInventory() {
    for (const auto& item : items) {
        if (item.getStock() < 10) {
            std::cout << "Low stock alert for item: " << item.getName() << std::endl;
            // 在实际应用中，你可以在这里添加发送警报的逻辑
        }
    }
}
