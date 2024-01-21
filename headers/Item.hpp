#pragma once
#include <string>

class Item {
public:
    Item(std::string name, int stock);
    std::string getName() const;
    int getStock() const;
    void decreaseStock(int amount);

private:
    std::string name;
    int stock;
};
