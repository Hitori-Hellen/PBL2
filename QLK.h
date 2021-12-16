#include "Game.h"
#include <iostream>
#pragma once

using namespace std;

class QLK {
private:
    Game *arr;
    int len;

public:
    // QLK();
    QLK(string);
    ~QLK();
    void Length(int);
    int Length();
    void addGameDB(Game, string);
    int search(string);
    void deleteGameDB(Game, int, string);
    void Sort(string);
    void Update_data(Game, int);
    void Update_numberS(bool, int, int);
    Game Return_object(int);
    void Show_QLK();
};
