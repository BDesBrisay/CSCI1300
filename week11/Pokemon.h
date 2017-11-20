/*
  Author: Bryce DesBrisay
  Recitation: Arcadia 210
  Assignment 8 - Pokemon
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <fstream>
#include "Move.h"

using namespace std;

class Pokemon {
  public:
    Pokemon();
    Pokemon(string);
    Pokemon(string, Move, Move, Move, Move);
    ~Pokemon();

    void setName(string);
    void setType(string);
    void setHealth(int);
    void setMove1(Move);
    void setMove2(Move);
    void setMove3(Move);
    void setMove4(Move);

    string getName();
    string getType();
    int getHealth();
    Move& getMove(int);

    string name;
    string type;
    int health;
    Move moves[4];
};
#endif // POKEMON_H
