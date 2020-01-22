#ifndef ENEMY_H
#define ENEMY_H

#include <string>

using namespace std;

class Enemy {
private:
	string enemyType;
	int health;
	const int baseAtk = 100;
	int attack;
	const int baseDef = 50;
	int defense;

public: 
	Enemy();
	void setHealth();
	void setEnemyType();
	void setAttack();
	void setDef();

	int getHealth();
	string getEnemyType();
	int getAttack();
	int getDefense();
	int getDecision();
	void subHealth(int);

	void displayEnemy();
	~Enemy();
};
#endif