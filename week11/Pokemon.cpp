
#include "Pokemon.h"

Pokemon::Pokemon() {
  health = 100;
}
Pokemon::Pokemon(string newName){
  name = newName;
  health = 100;
}
Pokemon::Pokemon(string newName, Move one, Move two, Move three, Move four){
  name = newName;
  moves[0] = one;
  moves[1] = two;
  moves[2] = three;
  moves[3] = four;
  health = 100;
}
Pokemon::~Pokemon() {
}

void Pokemon::setName(string newName) {
  name = newName;
}
void Pokemon::setType(string newType){
  type = newType;
}
void Pokemon::setHealth(int newHealth) {
  health = newHealth;
}
void Pokemon::setMove1(Move move) {
  moves[0] = move;
}
void Pokemon::setMove2(Move move) {
  moves[1] = move;
}
void Pokemon::setMove3(Move move) {
  moves[2] = move;
}
void Pokemon::setMove4(Move move) {
  moves[3] = move;
}

string Pokemon::getName() {
  return name;
}
string Pokemon::getType() {
  return type;
}
int Pokemon::getHealth() {
  return health;
}
Move& Pokemon::getMove(int index) {
  return moves[index];
}
