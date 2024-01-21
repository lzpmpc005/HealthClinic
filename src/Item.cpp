#include "Item.hpp"

Item::Item(std::string name, int stock) : name(name), stock(stock) {}

std::string Item::getName() const {
    return name;
}

int Item::getStock() const {
    return stock;
}

void Item::decreaseStock(int amount) {
    stock -= amount;
}
