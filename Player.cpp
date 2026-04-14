#include "Player.h"
#include <iostream>

Player::Player(std::string name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower), x(0), y(0) , inventory(10) {
    std::cout << "Player " << name << " created." << std::endl;
}

Player:: ~Player() {
    std::cout << "Player " << name << " destroyed." << std::endl;
}

std::string Player::getName() const { return name; }
int Player::getHealth() const { return health; }
int Player::getAttackPower() const { return attackPower; }


int Player::getX() const { return x; }
int Player::getY() const { return y; }

void Player::setX(int x) { this->x = x; }
void Player::setY(int y) { this->y = y; }

void Player::showInventory() const { inventory.display(); }
void Player::addItem(const Item& item) { inventory.addItem(item); }