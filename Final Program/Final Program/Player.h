#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
private:
	string name;
	string weapon;
	string armor;
	string className;
	int score;
	int kills;

protected:
	int health;
	int attack;
	int defense;
	const int baseAtk = 100;
	const int baseDef = 50;

public:
	Player();
	void setKills(int);
	void setName(string);
	void setWeapon(string);
	void setArmor(string);
	void setClassName(string);
	void setHealth(int);
	void setAttack(int);
	void setDefense(int);
	void setScore(int);
	void addHealth(int);
	void addScore(int);
	void subHealth(int);
	void addKill();

	string getName();
	string getWeapon();
	string getArmor();
	string getClassName();
	int getHealth();
	int getAttack();
	int getDefense();
	int getScore();
	void displayPlayer();
	int getKills();
	~Player();

	friend ostream& operator<<(ostream&, const Player&);
	friend istream& operator>>(istream&, Player&);
};
#endif
