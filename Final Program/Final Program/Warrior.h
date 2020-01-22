#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"

#include <string>

using namespace std;

class Warrior : public Player {
private:
	int wAtk = 50;
	int wDef = 50;
	int wHealth = 100;

public:
	Warrior();
	const int getwAtk();
	const int getwDef();
	const int getwHealth();
	~Warrior();
};

#endif
