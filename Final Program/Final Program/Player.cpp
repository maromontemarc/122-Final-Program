#include "Player.h"
#include "Game.h"
#include "Rogue.h"
#include "Hunter.h"
#include "Warrior.h"

#include <iostream>
#include <sstream>

using namespace std;

Player::Player() {
	health = 0;
	attack = baseAtk;
	defense = baseDef;
	score = 0;
	kills = 0;
}

// Class: Rogue, Hunter, Warrior
//
void Player::setClassName(string c) {
	className = c;
}

void Player::setKills(int k) {
	kills = k;
}

void Player::setName(string n) {
	name = n;
}

void Player::setHealth(int h) {
	health = h;
}

void Player::addHealth(int h) {
	health += h;
}

void Player::addKill() {
	kills ++;
}

void Player::setAttack(int a) {
	attack += a;
}

void Player::setDefense(int d) {
	defense += d;
}

// Weapon: Battle Axe, Dagger, Long Sword
//
void Player::setWeapon(string w) {
	weapon = w;
	
	if (weapon == "Battle Axe") {
		setAttack(20);
		setDefense(15);
	}
	else if (weapon == "Dagger") {
		setAttack(10);
		setDefense(10);
	}
	else if (weapon == "Long Sword") {
		setAttack(15);
		setDefense(15);
	}
}

// Armor: Knight's Armor, Robes, Leather Armor
//
void Player::setArmor(string a) {
	armor = a;

	if (armor == "Knight's Armor") {
		setDefense(17);
	}
	else if (armor == "Robes") {
		setDefense(10);
		setAttack(15);
	}
	else if (armor == "Leather Armor") {
		setDefense(15);
		setAttack(5);
	}
}

void Player::setScore(int s) {
	score = s;
}

void Player::addScore(int s) {
	score += s;
}

int Player::getKills() {
	return kills;
}

string Player::getName() {
	return name;
}

string Player::getWeapon() {
	return weapon;
}

string Player::getArmor() {
	return armor;
}

string Player::getClassName() {
	return className;
}

int Player::getHealth() {
	return health;
}

int Player::getAttack() {
	return attack;
}

int Player::getDefense() {
	return defense;
}

int Player::getScore() {
	return score;
}

void Player::subHealth(int h) {
	health -= h;
}

// Displays Player
//
void Player::displayPlayer() {
	cout << "Name: " << getName() << endl
		<< "Class: " << getClassName() << endl
		<< "Weapon: " << getWeapon() << endl
		<< "Armor: " << getArmor() << endl
		<< "Health: " << getHealth() << endl
		<< "Attack: " << getAttack() << endl
		<< "Defense: " << getDefense() << endl 
		<< "Score: " << getScore() << endl
		<< "Kills: " << getKills() << endl << endl;
}

// Insertion operator
//
ostream& operator<<(std::ostream& os, const Player& p)
{
	// write out individual members of s with an end of line between each one
	//
	os << p.name << '\n';
	os << p.weapon << '\n';
	os << p.armor << '\n';
	os << p.className << '\n';
	os << p.score << '\n';
	os << p.attack << '\n';
	os << p.defense << '\n';
	os << p.health << '\n';
	return os;
}

// Extraction operator
//
istream& operator>>(istream& is, Player& p)
{
	string s;
	stringstream temp;

	getline(is, p.name);
	getline(is, p.weapon);
	getline(is, p.armor);
	getline(is, p.className);
	// score
	getline(is, s);
	temp.str(s);
	temp >> p.score;
	temp.clear();
	//attack
	getline(is, s);
	temp.str(s);
	temp >> p.attack;
	temp.clear();
	// defense
	getline(is, s);
	temp.str(s);
	temp >> p.defense;
	temp.clear();
	// health
	getline(is, s);
	temp.str(s);
	temp >> p.health;
	temp.clear();

	return is;
}

Player::~Player() {

}