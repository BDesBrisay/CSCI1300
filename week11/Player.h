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
    Player(string);
    Player(string, Pokemon, Pokemon, Pokemon);
    ~Player();

    void setName(string);
    void setPokemon1(Pokemon);
    void setPokemon2(Pokemon);
    void setPokemon3(Pokemon);

    void setName(string);
    void setPokemon1(Pokemon);
    void setPokemon2(Pokemon);
    void setPokemon3(Pokemon);

    string name;
    Pokemon team[3];
}
