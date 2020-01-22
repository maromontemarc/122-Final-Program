#ifndef ROGUE_H
#define ROGUE_H

#include "Player.h"

#include <string>

using namespace std;

class Rogue : public Player {
private:
	int rAtk = 50;
	int rDef = 47;
	int rHealth = 100;

public:
	Rogue();
	const int getrAtk();
	const int getrDef();
	const int getrHealth();

	~Rogue();
};

#endif