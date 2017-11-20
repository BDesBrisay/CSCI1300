/*
  Author: Bryce DesBrisay
  Recitation: Arcadia 210
  Assignment 8 - Player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include "Pokemon.h"

using namespace std;

class Player {
  public:
    Player();
    Player(string, int, int);
    Player(Pokemon, Pokemon, Pokemon);
    Player(string, int, int, Pokemon, Pokemon, Pokemon);
    ~Player();

    void setActivePokemon(int);
    void setName(string);
    void setHeight(int);
    void setWeight(int);
    void setPokemon1(Pokemon);
    void setPokemon2(Pokemon);
    void setPokemon3(Pokemon);

    string getName();
    int getHeight();
    int getWeight();
    Pokemon& getPokemon(int);
    int getActivePokemon();

    string name;
    int height = 12;
    int weight = 120;
    int activePokemon;
    Pokemon team[3];
};
#endif // PLAYER_H
