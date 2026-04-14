#ifndef MAP_H
#define MAP_H
#include "Player.h"

class Map {
private:
    char** grid;     
    int width;        
    int height;       
    Player* playerPtr; 
public:
      Map(int width, int height, Player* player);
        ~Map();
     void draw() const;
    bool isWall(int x, int y) const;

    int getWidth() const;
    int getHeight() const;
};

#endif