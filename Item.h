#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
    private:
      static int totalItems;
      std::string name;
      int value;
    public:
    Item(std::string name = "scrap", int value = 0);
    static int getTotalItems();
    static void incrementTotalItems();
 
    std::string getName() const;
    int getValue() const;
 
    void display() const;
};
 
#endif