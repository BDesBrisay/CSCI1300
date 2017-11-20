#include "Arena.h"
#include "Player.h"
#include "Pokemon.h"
#include "Move.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void split(string str, string del, string array[]) {
  size_t pos = 0;
  int index = 0;

  while ((pos = str.find(del)) != string::npos) {
    array[index] = str.substr(0, pos);
    str.erase(0, pos + del.length());
    index++;
  }

  array[index] = str;
}

int main() {
  ifstream file("moves.txt");
  string line;
  Move move1;
  Move move2;
  Move move3;
  Move move4;
  string player1Name;
  string player2Name;

  if(file.is_open()) {
    int index = 0;
    while(getline(file, line)) {
      string tempArray[4];
      split(line, ",", tempArray);
      if(index % 4 == 0) {
        move1.setName(tempArray[0]);
        move1.setType(tempArray[1]);
        move1.setSpeed(stoi(tempArray[2]));
        move1.setDamage(stoi(tempArray[3]));
      } else if(index % 4 == 1) {
        move2.setName(tempArray[0]);
        move2.setType(tempArray[1]);
        move2.setSpeed(stoi(tempArray[2]));
        move2.setDamage(stoi(tempArray[3]));
      } else if(index % 4 == 2) {
        move3.setName(tempArray[0]);
        move3.setType(tempArray[1]);
        move3.setSpeed(stoi(tempArray[2]));
        move3.setDamage(stoi(tempArray[3]));
      } else if(index % 4 == 3) {
        move4.setName(tempArray[0]);
        move4.setType(tempArray[1]);
        move4.setSpeed(stoi(tempArray[2]));
        move4.setDamage(stoi(tempArray[3]));
      }
      index++;
    }
  }

  cout << "What is player1's name?" << endl;
  cin >> player1Name;

  cout << "What is player2's name?" << endl;
  cin >> player2Name;

  Pokemon pokemon1("Pikachu", move1, move2, move3, move4);
  Pokemon pokemon2("Charmander", move2, move3, move4, move1);
  Pokemon pokemon3("Squirtle", move3, move4, move1, move2);
  Pokemon pokemon4("Bulbasaur", move4, move1, move2, move3);
  Pokemon pokemon5("Twig", move1, move2, move3, move4);
  Pokemon pokemon6("Arceus", move2, move3, move4, move1);
  Player player1(player1Name, 20, 123, pokemon1, pokemon2, pokemon3);
  Player player2(player2Name, 10, 143, pokemon4, pokemon5, pokemon6);
  Arena arena1("Name", 0, 0, player1, player2);

  arena1.battle();

  return 0;
}
