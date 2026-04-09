#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Inventory.h"
#include "Item.h"

class Player {
private:
    std::string name;
    int health;
    int attackPower;
    int x;
    int y;
    Inventory inventory; 

public:
    Player(std::string name, int health, int attackPower);
    ~Player();

    std::string getName() const;
    int getHealth() const;
     int getAttackPower() const;

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    void showInventory() const;
    void addItem(const Item& item);
};

#endif