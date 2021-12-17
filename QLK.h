#include "Game.h"
#include <iostream>
#pragma once

using namespace std;

class QLK {
private:
    Game *arr;
    int len;

public:
    QLK(string);
    ~QLK();
    void addGameDB(Game, string);
    int search(string);
    void deleteGameDB(Game, int, string);
    void sort(string);
    void updateStock(bool, int, int);
    Game returnGameObj(int);
    void showGameDB();
};
