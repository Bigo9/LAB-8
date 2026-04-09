#include "Game.h"
#include "Item.h"
#include <iostream>



Game::Game()
    : player("Hero", 100, 10),   
      gameMap(30, 15, &player),  
      running(true) {

    player.addItem(Item("Sword", 10));
    player.addItem(Item("Shield", 5));

    std::cout << "Welcome to the RPG! Use WASD to move, Q to quit." << std::endl;
}

Game::~Game() {
    std::cout << "Game over." << std::endl;
}
void Game::run() {
    while (running) {
    
        for (int i = 0; i < 20; i++) {
            std::cout << std::endl;
        }

        
        std::cout << "--- Console RPG ---" << std::endl;


        gameMap.draw();
        std::cout << "Name: " << player.getName() << std::endl;
        std::cout << "HP:   " << player.getHealth() << std::endl;
        std::cout << "Pos:  (" << player.getX() << ", " << player.getY() << ")" << std::endl;
        std::cout << "Move: WASD | Quit: Q" << std::endl;
        
        processInput();
    }
}

void Game::processInput() {
    char input;
    std::cin >> input;
    input = toupper(input); 

    // Calculate where the player wants to move
    int newX = player.getX();
    int newY = player.getY();

    if (input == 'W') newY -= 1;     
    else if (input == 'S') newY += 1;  
    else if (input == 'A') newX -= 1;  
    else if (input == 'D') newX += 1; 
    else if (input == 'Q') {
        running = false;
        return;
    }

    if (!gameMap.isWall(newX, newY)) {
        player.setX(newX);
        player.setY(newY);
    }
}