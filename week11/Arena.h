/*
  Author: Bryce DesBrisay
  Recitation: Arcadia 210
  Assignment 8 - Arena
*/

#include <iostream>
#include <fstream>
#include "Player.h"

using namespace std;

class Arena {
  public:
    Arena();
    Arena(string, int, int);
    Arena(string, int, int, Player, Player);
    ~Arena();

    void setPlayer1(string);
    void setPlayer2(string);
    void setScore1(int);
    void setScore2(int);

    Player getPlayer1();
    Player getPlayer2();
    int getScore1();
    int getScore2();

    string name;
    Player player1;
    Player player2;
    int score[2];
}
