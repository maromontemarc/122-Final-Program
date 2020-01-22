#include "Rogue.h"

// Sets rogue's attributes
//
Rogue::Rogue() {
	attack = rAtk + baseAtk;
	defense = rDef + baseDef;
	health = rHealth;
}

const int Rogue::getrAtk() {
	return rAtk;
}

const int Rogue::getrDef() {
	return rDef;
}

const int Rogue::getrHealth(){
	return rHealth;
}

Rogue::~Rogue() {

}