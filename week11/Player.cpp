

#include "Player.h"

Player::Player() {
  activePokemon = 0;
}

Player::Player(string newName, int newWeight, int newHeight) {
  name = newName;
  weight = newWeight;
  height = newHeight;
  activePokemon = 0;
}

Player::Player(Pokemon one, Pokemon two, Pokemon three) {
  team[0] = one;
  team[1] = two;
  team[2] = three;
  activePokemon = 0;
}

Player::Player(string newName, int newHeight, int newWeight, Pokemon one, Pokemon two, Pokemon three) {
  name = newName;
  weight = newWeight;
  height = newHeight;
  team[0] = one;
  team[1] = two;
  team[2] = three;
  activePokemon = 0;
}

Player::~Player() {
}

void Player::setActivePokemon(int index) {
  activePokemon = index;
}

void Player::setName(string newName) {
  name = newName;
}

void Player::setHeight(int newHeight){
  height = newHeight;
}

void Player::setWeight(int newWeight) {
  weight = newWeight;
}

void Player::setPokemon1(Pokemon pokemon) {
  team[0] = pokemon;
}

void Player::setPokemon2(Pokemon pokemon) {
  team[1] = pokemon;
}

void Player::setPokemon3(Pokemon pokemon) {
  team[2] = pokemon;
}

int Player::getActivePokemon() {
  return activePokemon;
}
string Player::getName() {
  return name;
}

int Player::getHeight() {
  return height;
}

int Player::getWeight() {
  return weight;
}

Pokemon& Player::getPokemon(int index) {
  return team[index];
}
