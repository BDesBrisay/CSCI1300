/*
  Author: Bryce DesBrisay
  Recitation: Arcadia 210
  Assignment 8 - Player
*/

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

    void setName(string);
    void setHeight(int);
    void setWeight(int);
    void setPokemon1(Pokemon);
    void setPokemon2(Pokemon);
    void setPokemon3(Pokemon);

    string getName(string);
    int getHeight(int);
    int getWeight(int);
    Pokemon getPokemon1(Pokemon);
    Pokemon getPokemon2(Pokemon);
    Pokemon getPokemon3(Pokemon);

    string name;
    string height;
    string weight;
    Pokemon team[3];
}
