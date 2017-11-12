/*
  Author: Bryce DesBrisay
  Recitation: Arcadia 210
  Assignment 8 - Move
*/

#include <iostream>
#include <fstream>

using namespace std;

class Move {
  public:
    Move();
    Move(string, int);
    ~Move();

    void setName(string);
    void setDamage(int);

    string getName();
    int getDamage();

    string name;
    int damage;
}
