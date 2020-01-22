#include "Enemy.h"

#include <random>
#include <string>
#include <iostream>

using namespace std;

Enemy::Enemy() {
	setHealth();
	setEnemyType();
	setAttack();
	setDef();
}

// Randomly sets health (75-100)
//
void Enemy::setHealth() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> disInt(75, 100);
	health = disInt(mt);
}

// Randomly chooses enemy type
//
void Enemy::setEnemyType() {
	int temp;
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> disInt(1, 3);
	temp = disInt(mt);

	if (temp == 1) {
		enemyType = "Skeleton";
	}
	else if (temp == 2) {
		enemyType = "Ogre";
	}
	else if (temp == 3) {
		enemyType = "Imp";
	}
}

// Randomly sets attack (1-50)
//
void Enemy::setAttack() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> disInt(1, 50);
	attack = baseAtk + disInt(mt);
}

// Randomly sets defense (1-50)
//
void Enemy::setDef() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> disInt(1, 50);
	defense = baseDef + disInt(mt);
}

int Enemy::getHealth() {
	return health;
}

string Enemy::getEnemyType() {
	return enemyType;
}

int Enemy::getAttack() {
	return attack;
}

int Enemy::getDefense() {
	return defense;
}

// Displays enemy
//
void Enemy::displayEnemy() {
	cout << "Enemy Stats" << endl
		<< "Type: " << getEnemyType() << endl
		<< "Health: " << getHealth() << endl
		<< "Attack: " << getAttack() << endl
		<< "Defense: " << getDefense() << endl << endl;
}

// Randomly chooses attack or defend
//
int Enemy::getDecision() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> disInt(1, 2);

	return disInt(mt);
}

void Enemy::subHealth(int h) {
	health -= h;
}

Enemy::~Enemy() {

}