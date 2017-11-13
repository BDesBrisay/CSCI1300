/*
  Author: Bryce DesBrisay
  Recitation: Arcadia 210
  Assignment 8 - Pokemon
*/

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

    void setName();
    void setType();
    void setHealth();
    void setMove1();
    void setMove2();
    void setMove3();
    void setMove4();

    string getName();
    string getType();
    int getHealth();
    Move getMove1();
    Move getMove2();
    Move getMove3();
    Move getMove4();

    string name;
    string type;
    int health = 100;
    Move moves[4];
}
