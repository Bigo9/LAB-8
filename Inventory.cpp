#include "Inventory.h"
#include <iostream>

Inventory::Inventory(int capacity): items(new Item[capacity]), capacity(capacity), itemCount(0)
{

}

Inventory::~Inventory() {
    delete[] items;
    std::cout << "Inventory has been destroyed." << std::endl;
}

bool Inventory::addItem(const Item& item) {
   
    if (itemCount >= capacity) {
        std::cout << "Inventory is full!" << std::endl;
        return false;
    }

    items[itemCount] = item;
    itemCount++;

    Item::incrementTotalItems();

    std::cout << "An item was added: " << item.getName() << std::endl;
    return true;
}

void Inventory::display() const {
    std::cout << "Inventory (" << itemCount << "/" << capacity << "):" << std::endl;
    for (int i = 0; i < itemCount; i++) {
        items[i].display();
    }
}