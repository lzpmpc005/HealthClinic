#pragma once
#include <vector>
#include "Item.hpp"

class InventoryManager {
public:
    void addItem(const Item& item);
    void checkInventory();

private:
    std::vector<Item> items;
};
