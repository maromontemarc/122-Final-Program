#include "Hunter.h"

// Sets hunter's attributes
//
Hunter::Hunter() {
	attack = hAtk + baseAtk;
	defense = hDef + baseDef;
	health = hHealth;
}

const int Hunter::gethAtk() {
	return hAtk;
}

const int Hunter::gethDef() {
	return hDef;
}

const int Hunter::gethHealth() {
	return hHealth;
}

Hunter::~Hunter() {

}