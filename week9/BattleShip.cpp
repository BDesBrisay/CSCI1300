#include <iostream>
#include <string>
#include "BattleShip.h"

using namespace std;

BattleShip::BattleShip(string shipName) {
  name = shipName;
}

BattleShip::~BattleShip() {

}

void BattleShip::setShipName(string newName) {
  name = newName;
}

string BattleShip::getShipName() {
  return name;
}

void BattleShip::setSize(int newSize) {
  size = newSize;
}

int BattleShip::getSize() {
  return size;
}

void BattleShip::recordHit() {
  hits++;
}

bool BattleShip::isSunk() {
  if (hits >= size) {
    return true;
  } else {
    return false;
  }
}
