#include "Map.h"
#include <iostream>

Map::Map(int width, int height, Player* player)
    : width(width), height(height), playerPtr(player) {

    
    playerPtr->setX(1);
    playerPtr->setY(1);

    grid = new char*[height];

    for (int r = 0; r < height; r++) {
        grid[r] = new char[width];
    }
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (r == 0 || r == height - 1 || c == 0 || c == width - 1) {
                grid[r][c] = '#';
            } else {
                grid[r][c] = '.';
            }
        }
    }
}

Map::~Map() {

    for (int r = 0; r < height; r++) {
        delete[] grid[r];
    }
    delete[] grid;
}

void Map::draw() const {
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {

            if (c == playerPtr->getX() && r == playerPtr->getY()) {
                std::cout << '@';
            } else {
                std::cout << grid[r][c];
            }
        }
        std::cout << std::endl; 
    }
}

bool Map::isWall(int x, int y) const {

    if (x < 0 || x >= width || y < 0 || y >= height) {
        return true;
    }
    
    return grid[y][x] == '#';
}

int Map::getWidth() const { return width; }
int Map::getHeight() const { return height; }