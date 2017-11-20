/*
  Author: Bryce DesBrisay
  Recitation: Arcadia 210
  Assignment 8 - Arena
*/

#include "Arena.h"

Arena::Arena() {
}

Arena::Arena(string newName) {
  name = newName;
}

Arena::Arena(string newName, Player one, Player two) {
  name = newName;
  player1 = one;
  player2 = two;
}

Arena::Arena(string newName, int score1, int score2, Player one, Player two) {
  name = newName;
  score[0] = score1;
  score[1] = score2;
  player1 = one;
  player2 = two;
}

Arena::~Arena() {
}



void Arena::setName(string newName) {
  name = newName;
}

void Arena::setPlayer1(Player player) {
  player1 = player;
}

void Arena::setPlayer2(Player player) {
  player2 = player;
}

void Arena::setScore1(int newScore) {
  score[0] = newScore;
}
void Arena::setScore2(int newScore) {
  score[1] = newScore;
}

string Arena::getName() {
  return name;
}
Player& Arena::getPlayer1() {
  return player1;
}
Player& Arena::getPlayer2() {
  return player2;
}
int Arena::getScore1() {
  return score[0];
}
int Arena::getScore2() {
  return score[1];
}
int Arena::getTurnCount() {
  return turnCount;
}

void Arena::setup() {
  ifstream file("pokemon.txt");
  string line;

  if(file.is_open()) {
    while(getline(file, line)) {

    }
  }
}

int Arena::battle() {
  string playerName;

  while(playing) {
    bool invalidResponse = true;
    while(invalidResponse) {
      string input;
      cout << "Would you like to play Pokemon? (1 for yes, 0 for no)" << endl;
      cin >> input;
      if(stoi(input) == 1) {
        playing = true;
        invalidResponse = false;
      } else if(stoi(input) == 0) {
        playing = false;
        invalidResponse = false;
      } else {
        cout << "That is not a valid response." << endl;
      }
    }

    if(playing) {
      play();
    }
  }
}

void Arena::play() {
  cout << player1.getName() << " vs. " << player2.getName() << endl;

  ofstream battleLog("battleLog.txt");

  while(checkWin() == 0) {
    turn(player1, player2, 0);
    if(checkWin() == 1 || checkWin() == 2) {break;};
    turn(player2, player1, 1);
    checkWin();
  }

  if(checkWin() == 1) {
    cout << "Player 1 has won. Congratulations!" << endl;
    cout << endl;
  } else if(checkWin() == 2) {
    cout << "Player 2 has won. Congratulations!" << endl;
    cout << endl;
  }

  playing = false;
}

void Arena::turn(Player& one, Player& two, int player) {
  int activePokemon1 = one.getActivePokemon();
  int activePokemon2 = two.getActivePokemon();
  cout << one.getName() << "'s turn, your Pokemon is " << one.getPokemon(activePokemon1).getName() << ", here are your moves:" << endl;
  for(int i = 0; i < 4; i++) {
    cout << i << " Name: " << one.getPokemon(activePokemon1).getMove(i).getName() << ", Damage: " << one.getPokemon(activePokemon1).getMove(i).getDamage() << endl;
  }

  ofstream battleLog;
  battleLog.open("battleLog.txt", ios::app);

  bool invalidMove = true;
  string move;
  string input;
  while(invalidMove) {
    cout << "What's your move? (1,2,3, or 4)" << endl;
    cin >> input;
    int move = stoi(input);
    if(move < 5 && move > 0) {
      int damage = one.getPokemon(activePokemon1).getMove(move - 1).getDamage();
      int health = two.getPokemon(activePokemon2).getHealth();
      two.getPokemon(activePokemon2).setHealth(health - damage);

      cout << two.getPokemon(activePokemon2).getName() << " has " << two.getPokemon(activePokemon2).getHealth() << " health left" << endl;
      battleLog << "Move " << one.getPokemon(activePokemon1).getMove(move - 1).getName() << " did " << one.getPokemon(activePokemon1).getMove(move - 1).getDamage() << " damage."<<endl;
      battleLog << two.getPokemon(activePokemon2).getName() << " has " << two.getPokemon(activePokemon2).getHealth() << " health left" << endl;

      if(two.getPokemon(activePokemon2).getHealth() <= 0) {
        cout << two.getPokemon(activePokemon2).getName() << " has died" << endl;
        if(player == 0) {
          setScore1(getScore1() + 1);
        } else if(player == 1) {
          setScore2(getScore2() + 1);
        }
        if(checkWin() == 0) {
          two.setActivePokemon(activePokemon2 + 1);
        }
      }

      invalidMove = false;
    } else {
      cout << "Enter a valid move." << endl;
    }
  }

}

int Arena::checkWin(){
  if(score[0] < 3 && score[1] < 3) {
    return 0;
  } else if(score[0] >= 3) {
    return 1;
  } else if(score[1] >= 3) {
    return 2;
  }
}
