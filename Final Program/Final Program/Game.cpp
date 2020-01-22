#include "Player.h"
#include "Rogue.h"
#include "Warrior.h"
#include "Hunter.h"
#include "Enemy.h"
#include "LinkedList.h"
#include "Game.h"

#include <random>
#include <fstream> 
#include <iostream>

using namespace std;
/*
	This program is a fighting simulator where you have the option of three separate classes:
	Rogue, Hunter, or Warrior. Each class has different attributes. ie. Attack and Defense.
	A unique weapon and set of armor can also be chosen: Battle Axe, Long Sword, Dagger,
	Knight's Armor, Leather Armor, or Robes. Each have their own effect on the player's stats.
	When the fighting begins, ten random enemies are generated with their own type (skeleton, imp, or ogre),
	and stats. Every enemy you kill has a chance of dropping a potion (health, attack, or defense)
	The goal of this game is to kill all the enemies earning the highest score, but if you die you lose
	your character along with your score. In order to achieve the high score, you must kill as many enemies as you
	can without dying.

	-Marc Maromonte
*/

// Input cheat code at armor menu.
// Cheat code to enable god mode: 1547


// Declares global variables
//
Player* playerPtr = new Player;
LinkedList<Enemy*> enemyList;
Enemy* curEnemy = new Enemy;
int enemyCount;
int highScore;

int main() {

	int menuChoice;

	// Displays the Play or Quit menu
	//
	menuChoice = menu();

	switch (menuChoice)
	{
	case 1:
		cout << endl;
		start();
		break;
	case 2:
		cout << endl;
		break;
	}

	system("pause");
	return 0;
}

void start() {
	int menuChoice;
	
	// Displays the Create New Player, Load Player, or Quit menu
	//
	menuChoice = startMenu();
	
	switch (menuChoice)
	{
		case 1:
			cout << endl;
			playerCreator();
			break;
		case 2:
			cout << endl;
			loadPlayer();
			break;
		case 3:
			cout << endl;
			exit;
			break;
	}
}

// Creates a new player
//
void playerCreator() {
	int menuChoice;
	string name;

	cout << "Enter Character's Name: " << endl;
	cin.ignore();
	getline(cin, name);

	menuChoice = playerCreatorMenu();

	// Choose player's class
	//
	switch (menuChoice)
	{
	case 1:
		cout << endl;
		playerPtr = new Rogue;
		playerPtr->setClassName("Rogue");
		break;
	case 2:
		cout << endl;
		playerPtr = new Warrior;
		playerPtr->setClassName("Warrior");
		break;
	case 3:
		cout << endl;
		playerPtr = new Hunter;
		playerPtr->setClassName("Hunter");
		break;
	}

	playerPtr->setName(name);

	menuChoice = weaponMenu();

	// Choose player's weapon
	//
	switch (menuChoice)
	{
	case 1:
		cout << endl;
		playerPtr->setWeapon("Battle Axe");
		break;
	case 2:
		cout << endl;
		playerPtr->setWeapon("Dagger");
		break;
	case 3:
		cout << endl;
		playerPtr->setWeapon("Long Sword");
		break;
	}

	menuChoice = armorMenu();

	// Choose player's armor
	//
	switch (menuChoice)
	{
	case 1:
		cout << endl;
		playerPtr->setArmor("Knight's Armor");
		break;
	case 2:
		cout << endl;
		playerPtr->setArmor("Robes");
		break;
	case 3:
		cout << endl;
		playerPtr->setArmor("Leather Armor");
		break;
	case 1547:
		cout << "God mode enabled." << endl;
		playerPtr->setHealth(1000000000);
		playerPtr->setArmor("God Plates");
	}

	// Displays new player's attributes
	//
	cout << "Here are your character's attributes: " << endl;
	
	playerPtr->displayPlayer();
	cout << "-----------------------------" << endl;

	savePlayer();

	enemyCreator();
	fight();
}

// Creates 10 random enemies and stores in linked list
//
void enemyCreator() {
	Enemy* enemy[10];

	for (int i = 0; i < 10; i++) {
		enemy[i] = new Enemy;
		enemyList.appendNode(enemy[i]);
	}
}

// Handles player vs. enemy fighting
//
void fight() {
	int menuChoice;

	cout << "Let the fighting begin!\n" << endl;
	getEnemy();

	// Fighting continues until all enemies are dead or player dies
	//
	do{

	playerPtr->displayPlayer();

	cout << "Enemy " << (playerPtr->getKills() + 1) << ": " << endl;
	curEnemy->displayEnemy();

	menuChoice = fightMenu();
	
	switch (menuChoice)
	{
	case 1: {
		// attack
		cout << endl;
		fightCalculation(menuChoice);
		break;
		}	
	case 2: {
		// defend
		cout << endl;
		fightCalculation(menuChoice);
		break;
		}
	case 3: {
		// run
		cout << endl;
		run();
		}
	}
	
	// Checks if game is won or if enemy has died
	//
	if ((curEnemy->getHealth() < 0 || curEnemy->getHealth() == 0) && playerPtr->getHealth() > 0) {

		playerPtr->addScore((curEnemy->getAttack() * 5));
		playerPtr->addKill();
		enemyList.deleteAt(enemyCount);
		getEnemy();
		
		if ((playerPtr->getKills() % 10) != 0) {
			cout << "Enemy has been killed.\n" << endl;
			cout << "-----------------------------" << endl;
			enemyLoot();
			cout << "New enemy incoming!\n" << endl;
			cout << "-----------------------------" << endl;
		}
		else {
			cout << "You've killed all the enemies!" << endl;
			cout << "-----------------------------" << endl;
			int contChoice;
			contChoice = continueMenu();

			switch (contChoice)
			{
			case 1: {
				// Continue fighting
				cout << endl;
				enemyCreator();
				fight();
				break;
			}
			case 2: {
				// Save and quit
				cout << endl;
				gameOver();
				break;
			}
			}
		}
	}
	} while (playerPtr->getHealth() > 0);

	cout << "-----------------------------" << endl;
	cout << playerPtr->getName() << " has died in battle! Better luck next time." << endl;
	cout << "-----------------------------" << endl;
	gameOver();
}

// Run option for fighting
//
void run() {
	int menuChoice;

	// Fight new enemy or save and quit
	//
	menuChoice = runMenu();

	switch (menuChoice)
	{
	case 1:
		cout << endl;
		fight();
		break;
	case 2:
		cout << endl;
		gameOver();
		break;
	}
}

// Ends the game
//
void gameOver() {
	playerPtr->displayPlayer();
	cout << "-----------------------------" << endl;
	checkHS();
	savePlayer();
	system("pause");
	exit(0);
}

// Play or Quit menu
//
int menu()
{
	int choice;
	cout << "-----------------------------" << endl;
	cout << "Menu" << endl
		<< "1. Play" << endl
		<< "2. Quit" << endl;

	cout << "Enter a number (1-2): ";
	cin >> choice;
	cout << "-----------------------------" << endl;

	while (choice < 1 || choice > 2)
	{
		cout << "-----------------------------" << endl;
		cout << "Invalid choice. Reenter (1 - 2): ";
		cin >> choice;
		cout << "-----------------------------" << endl;
	}

	return choice;
}

// Continue fighting or quit menu
//
int continueMenu()
{
	int choice;
	cout << "-----------------------------" << endl;
	cout << "Menu" << endl
		<< "1. Continue fighting?" << endl
		<< "2. Save and Quit" << endl;

	cout << "Enter a number (1-2): ";
	cin >> choice;
	cout << "-----------------------------" << endl;

	while (choice < 1 || choice > 2)
	{
		cout << "-----------------------------" << endl;
		cout << "Invalid choice. Reenter (1 - 2): ";
		cin >> choice;
		cout << "-----------------------------" << endl;
	}

	return choice;
}

// Create Character, Load Character, or Quit menu
//
int startMenu() {
	int choice;

	cout << "-----------------------------" << endl;
	cout << "Start Menu" << endl
		<< "1. Create Character" << endl
		<< "2. Load Character" << endl
		<< "3. Quit" << endl;

	cout << "Enter a number (1-3): ";
	cin >> choice;
	cout << "-----------------------------" << endl;

	while (choice < 1 || choice > 3)
	{
		cout << "-----------------------------" << endl;
		cout << "Invalid choice. Reenter (1 - 3): ";
		cin >> choice;
		cout << "-----------------------------" << endl;
	}

	return choice;
}

// Attack, Defend, or Run menu
//
int fightMenu() {
	int choice;
	cout << "-----------------------------" << endl;
	cout << "Menu" << endl
		<< "1. Attack" << endl
		<< "2. Defend" << endl
		<< "3. Run" << endl;

	cout << "Enter a number (1-3): ";
	cin >> choice;
	cout << "-----------------------------" << endl;
	while (choice < 1 || choice > 3)
	{
		cout << "-----------------------------" << endl;
		cout << "Invalid choice. Reenter (1 - 3): ";
		cin >> choice;
		cout << "-----------------------------" << endl;
	}

	return choice;
}

// Fight Next Enemy or Save and Quit menu
//
int runMenu() {
	int choice;
	cout << "-----------------------------" << endl;
	cout << "Menu" << endl
		<< "1. Fight Next Enemy" << endl
		<< "2. Save and Quit" << endl;

	cout << "Enter a number (1-2): ";
	cin >> choice;
	cout << "-----------------------------" << endl;
	while (choice < 1 || choice > 2)
	{
		cout << "-----------------------------" << endl;
		cout << "Invalid choice. Reenter (1 - 2): ";
		cin >> choice;
		cout << "-----------------------------" << endl;
	}

	return choice;
}

// Class menu
//
int playerCreatorMenu() {
	int choice;
	cout << "-----------------------------" << endl;
	cout << endl << "Choose a class: " << endl
		<< "1. Rogue" << endl
		<< "2. Warrior" << endl
		<< "3. Hunter" << endl;

	cout << "Enter a number (1-3): ";
	cin >> choice;
	cout << "-----------------------------" << endl;
	while (choice < 1 || choice > 3)
	{
		cout << "-----------------------------" << endl;
		cout << "Invalid choice. Reenter (1 - 3): ";
		cin >> choice;
		cout << "-----------------------------" << endl;
	}

	return choice;
}

// Weapon menu
//
int weaponMenu() {
	int choice;
	cout << "-----------------------------" << endl;
	cout << "Choose a weapon: " << endl
		<< "1. Battle Axe" << endl
		<< "2. Dagger" << endl
		<< "3. Long Sword" << endl;

	cout << "Enter a number (1-3): ";
	cin >> choice;
	cout << "-----------------------------" << endl;
	while (choice < 1 || choice > 3)
	{
		cout << "-----------------------------" << endl;
		cout << "Invalid choice. Reenter (1 - 3): ";
		cin >> choice;
		cout << "-----------------------------" << endl;
	}

	return choice;
}

// Armor menu
//
int armorMenu() {
	int choice;
	cout << "-----------------------------" << endl;
	cout << "Choose a set of armor: " << endl
		<< "1. Knight Armor" << endl
		<< "2. Robes" << endl
		<< "3. Leather Armor" << endl;

	cout << "Enter a number (1-3): ";
	cin >> choice;
	cout << "-----------------------------" << endl;
	while ((choice < 1 || choice > 3) && choice != 1547)
	{
		cout << "-----------------------------" << endl;
		cout << "Invalid choice. Reenter (1 - 3): ";
		cin >> choice;
		cout << "-----------------------------" << endl;
	}

	return choice;
}

// Saves player to a file
//
void savePlayer() {

	ofstream ofs("CharacterSave");

	ofs << *playerPtr;
		
	ofs.close();
}

// Loads player from a file
//
void loadPlayer() {
	Player tempPlayer;

	ifstream ifs("CharacterSave");

	ifs >> tempPlayer;

	playerPtr = &tempPlayer;

	if (playerPtr->getHealth() < 0 || playerPtr->getHealth() == 0) {
		cout << "Your saved character had died. Please create a new one.\n" << endl;
		playerCreator();
	}
	else {

		enemyCreator();

		fight();
	}
}

// Calculates health loss in battle
//
void fightCalculation(int dec) {
	int playerDec = dec;
	int enemyDec = curEnemy->getDecision();
	int playerLoss = 0;
	int enemyLoss = 0;

	// 1 = attack
	// 2 = defend
	//
	cout << "-----------------------------" << endl;
	if (playerDec == 1 && enemyDec == 1) {
		cout << "You both attack.\n" << endl;
		playerLoss = int(curEnemy->getAttack() - (playerPtr->getDefense()));
		enemyLoss = int((.5 * playerPtr->getAttack()) - (curEnemy->getDefense()));
	}
	else if (playerDec == 1 && enemyDec == 2) {
		cout << "You attack, but the enemy defended\n" << endl;
		enemyLoss = int((playerPtr->getAttack()) - curEnemy->getDefense());
	}
	else if (playerDec == 2 && enemyDec == 1) {
		cout << "You defend against the enemy's attack\n" << endl;
		playerLoss = int(curEnemy->getAttack() - (playerPtr->getDefense()));
	}
	else if (playerDec == 2 && enemyDec == 2) {
		cout << "You both defend." << endl;
	}
	cout << "-----------------------------" << endl;

	if (playerLoss > 0) {
		playerPtr->subHealth(playerLoss);
	}
	if (enemyLoss > 0) {
		curEnemy->subHealth(enemyLoss);
	}
}

// Gets a new enemy to fight
//
void getEnemy() {
	
	if (enemyList.getNodeNum() == 1) {
		curEnemy = enemyList.getNodeAt(0);
	}else if(enemyList.getNodeNum() > 1){
		random_device rd;
		mt19937 mt(rd());
		uniform_int_distribution<int> disInt(0, (enemyList.getNodeNum() - 1));
		enemyCount = disInt(mt);
		curEnemy = enemyList.getNodeAt(enemyCount);
	}
}

// Saves player's high score
//
void saveHS() {
	ofstream ofs("HighScore");

	ofs << highScore;

	ofs.close();
}

// Load's player's high score
//
void loadHS() {
	ifstream ifs("HighScore");

	ifs >> highScore;
}

// Check's if high score has been beaten
//
void checkHS() {
	loadHS();

	if (playerPtr->getScore() > highScore) {
		cout << playerPtr->getName() << " has beaten the high score of " << highScore << endl;
		cout << "The new high score is: " << playerPtr->getScore() << endl;
		cout << "-----------------------------" << endl;
		highScore = playerPtr->getScore();
		saveHS();
	}
	else {
		cout << playerPtr->getName() << " did not beat the high score of " << highScore << endl;
		cout << "Better luck next time!" << endl;
		cout << "-----------------------------" << endl;
	}
}

// Calculates if killed enemy drops loot
//
void enemyLoot() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> disInt(1, 10);

	if (disInt(mt) == 5) {
		cout << "Enemy has dropped a Health Potion!" << endl
			<< "Your health has been increased by 15." << endl;
		cout << "-----------------------------" << endl;

		playerPtr->addHealth(15);
	}
	else if(disInt(mt) == 10) {
		cout << "Enemy has dropped an Attack Potion!" << endl
			<< "Your health has been increased by 5." << endl;
		cout << "-----------------------------" << endl;

		playerPtr->setAttack(5);
	}
	else if (disInt(mt) == 1) {
		cout << "Enemy has dropped a Defense Potion!" << endl
			<< "Your health has been increased by 5." << endl;
		cout << "-----------------------------" << endl;

		playerPtr->setDefense(5);
	}
}