#include "Warrior.h"

// Sets warrior's attributes
//
Warrior::Warrior() {
	attack = wAtk + baseAtk;
	defense = wDef + baseDef;
	health = wHealth;
}

const int Warrior::getwAtk() {
	return wAtk;
}

const int Warrior::getwDef() {
	return wDef;
}

const int Warrior::getwHealth() {
	return wHealth;
}

Warrior::~Warrior() {

}