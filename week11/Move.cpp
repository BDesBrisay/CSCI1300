

#include "Move.h"

Move::Move() {
}
Move::Move(string newName, string newType, int newSpeed, int newDamage) {
  name = newName;
  type = newType;
  speed = newSpeed;
  damage = newDamage;
}
Move::~Move() {
}

void Move::setName(string newName) {
  name = newName;
}
void Move::setType(string newType) {
  type = newType;
}
void Move::setSpeed(int newSpeed) {
  speed = newSpeed;
}
void Move::setDamage(int newDamage) {
  damage = newDamage;
}

string Move::getName() {
  return name;
}
string Move::getType() {
  return type;
}
int Move::getSpeed() {
  return speed;
}
int Move::getDamage() {
  return damage;
}
