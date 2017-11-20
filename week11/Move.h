/*
  Author: Bryce DesBrisay
  Recitation: Arcadia 210
  Assignment 8 - Move
*/

#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <fstream>

using namespace std;

class Move {
  public:
    Move();
    Move(string, string, int, int);
    ~Move();

    void setName(string);
    void setType(string);
    void setSpeed(int);
    void setDamage(int);

    string getName();
    string getType();
    int getSpeed();
    int getDamage();

    string name;
    string type;
    int speed = 1;
    int damage = 20;
};
#endif // MOVE_H
