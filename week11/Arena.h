/*
  Author: Bryce DesBrisay
  Recitation: Arcadia 210
  Assignment 8 - Arena
*/

#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "Pokemon.h"
#include "Move.h"

using namespace std;

class Arena {
  public:
    Arena();
    Arena(string);
    Arena(string, Player, Player);
    Arena(string, int, int, Player, Player);
    ~Arena();

    void setName(string);
    void setPlayer1(Player);
    void setPlayer2(Player);
    void setScore1(int);
    void setScore2(int);

    string getName();
    Player& getPlayer1();
    Player& getPlayer2();
    int getScore1();
    int getScore2();
    int getTurnCount();

    void setup();
    int battle();
    void play();
    void turn(Player&, Player&, int);
    int checkWin();

    bool playing = true;
    string name;
    Player player1;
    Player player2;
    int score[2];
    int turnCount = 0;
};
#endif // ARENA
