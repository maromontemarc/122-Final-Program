#ifndef GAME_H
#define GAME_

int menu();
void start();
int continueMenu();
int startMenu();
void playerCreator();
void enemyCreator();
int playerCreatorMenu();
int weaponMenu();
int armorMenu();
void fight();
int fightMenu();
void savePlayer();
void loadPlayer();
void saveHS();
void loadHS();
void checkHS();
void run();
int runMenu();
void gameOver();
void fightCalculation(int);
void getEnemy();
void enemyLoot();
#endif