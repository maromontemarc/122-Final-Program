#ifndef HUNTER_H
#define HUNTER_H

#include "Player.h"

#include <string>

using namespace std;

class Hunter : public Player {
private:
	int hAtk = 45;
	int hDef = 45;
	int hHealth = 100;

public:
	Hunter();
	const int gethAtk();
	const int gethDef();
	const int gethHealth();

	~Hunter();
};

#endif