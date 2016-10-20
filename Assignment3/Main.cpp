#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include "Player.h"
#include "Monster.h"
#include "Boss.h"


bool checkForMonsters(Player& p1, int xPos, int yPos, std::vector<Monster*> monsterList);

int detectMonster(Player& p1, int xPos, int yPos, std::vector<Monster*> monsterList);

void battle(Player& p1, Monster* m1);
void capture(Player& p1, Monster* m1);
void displayDungeon(char dungeonArray[][20]);
void generateDungeon(Player& p1, char dungeonArray[][20], char testMode);
void spawnMonsters(char dungeonArray[][20], Monster* m1);
int setExit(char dungeonArray[][20]);


bool checkExited(char dungeonArray[][20], int playerX, int PlayerY);

int main(){
	srand(time(NULL));

	char testMode;
	int playerXStart;

	std::cout << "Test mode? " << std::endl;
	std::cin >> testMode;

	Player p1("Andrew");
	playerXStart = p1.setInitPos();
	
	//======================
	
	char dungeon[10][20];
	char playerMovement;

	int xExit;
	int yExit = 19;
	int monsterPosition;

	

	std::cout << "Stuff" << std::endl;

	generateDungeon(p1, dungeon, testMode);
	xExit = setExit(dungeon);

	std::vector<Monster*> monsterType;

	for (int i = 0; i < 10; i++){
		monsterType.push_back(new Monster(Bugbear));
		monsterType.push_back(new Monster(Platypie));
		monsterType.push_back(new Monster(Emoo));
		monsterType.push_back(new Monster(Octopod));
	}


	for (int i = 0; i < monsterType.size(); i++){			
		bool isValid = false;
		do{
			int randX = rand() % 9;
			int randY = rand() % 19;
			char monsterChar;
			monsterType[i]->setXandYPosition(randX, randY);
			if (dungeon[monsterType[i]->XPos()][monsterType[i]->YPos()] == '-'){
				if (monsterType[i]->getType() == "Bugbear"){ dungeon[monsterType[i]->XPos()][monsterType[i]->YPos()] = 'B'; }
				else if (monsterType[i]->getType() == "Platypie") { dungeon[monsterType[i]->XPos()][monsterType[i]->YPos()] = 'P'; }
				else if (monsterType[i]->getType() == "Emoo") { dungeon[monsterType[i]->XPos()][monsterType[i]->YPos()] = 'E'; }
				else if (monsterType[i]->getType() == "Octopod") { dungeon[monsterType[i]->XPos()][monsterType[i]->YPos()] = 'O'; }
				isValid = true;
			}
		} while (!isValid);	
	}

	

	
	
	
	

	std::cout << std::endl;

	
	
	do{
		generateDungeon(p1, dungeon, testMode);
		displayDungeon(dungeon);

		std::cout << "Which direction? " << std::endl;
		std::cin >> playerMovement;

		
		if (playerMovement == 'w') {
			if (checkForMonsters(p1, p1.XPos() - 1, p1.YPos(),  monsterType)){
				monsterPosition = detectMonster(p1, p1.XPos() - 1, p1.YPos(), monsterType);
				if (monsterType[monsterPosition]->getType() == "Octopod"){
					battle(p1, monsterType[monsterPosition]);
				}
				else {
					capture(p1, monsterType[monsterPosition]);
				}
				

				monsterType[monsterPosition]->setXandYPosition(-10, -10);


				system("Pause");
			}
			p1.movement(p1.XPos(), p1.YPos(), p1.XPos() - 1, p1.YPos() );
		}
		else if (playerMovement == 'a') {
			if (checkForMonsters(p1, p1.XPos(), p1.YPos() - 1, monsterType)){
				monsterPosition = detectMonster(p1, p1.XPos(), p1.YPos() - 1, monsterType);
				if (monsterType[monsterPosition]->getType() == "Octopod"){
					battle(p1, monsterType[monsterPosition]);
				}
				else {
					capture(p1, monsterType[monsterPosition]);
				}

				monsterType[monsterPosition]->setXandYPosition(-10, -10);

				system("Pause");
			}
			p1.movement(p1.XPos(), p1.YPos(), p1.XPos(), p1.YPos() - 1);
		}
		else if (playerMovement == 's') {
			if (checkForMonsters(p1, p1.XPos() + 1, p1.YPos(), monsterType)){
				monsterPosition = detectMonster(p1, p1.XPos() +1, p1.YPos(), monsterType);
				if (monsterType[monsterPosition]->getType() == "Octopod"){
					battle(p1, monsterType[monsterPosition]);
				}
				else {
					capture(p1, monsterType[monsterPosition]);
				}

				monsterType[monsterPosition]->setXandYPosition(-10, -10);

				system("Pause");
			}
			p1.movement(p1.XPos(), p1.YPos(), p1.XPos() + 1, p1.YPos());
		}
		else if (playerMovement == 'd') {
			if (checkForMonsters(p1, p1.XPos(), p1.YPos() + 1, monsterType)){
				monsterPosition = detectMonster(p1, p1.XPos(), p1.YPos() + 1, monsterType);
				if (monsterType[monsterPosition]->getType() == "Octopod"){
					battle(p1, monsterType[monsterPosition]);
				}
				else {
					capture(p1, monsterType[monsterPosition]);
				}

				monsterType[monsterPosition]->setXandYPosition(-10, -10);

				system("Pause");
			}
			p1.movement(p1.XPos(), p1.YPos(), p1.XPos(), p1.YPos() + 1);
		}

		system("CLS");


		generateDungeon(p1, dungeon, testMode);
		
	} while (!(p1.XPos() == xExit && p1.YPos() == yExit));


	

	system("pause");

	for (int i = 0; i < monsterType.size(); i++){
		delete monsterType[i];
	}

	return 0;
}


int detectMonster(Player& p1, int xPos, int yPos, std::vector<Monster*> monsterList){
	bool found = false;
	int output = 0;
	int i = 0;
	do{
		if (monsterList[i]->XPos() == xPos && monsterList[i]->YPos() == yPos){
			found = true;
			output = i;
		}
		else {
			i++;
		}
	} while (!found && i < monsterList.size());
	return output;
}

void battle(Player& p1, Monster* m1){
	std::cout << "A wild Octopod appeared!" << std::endl;
	std::cout << m1->display() << std::endl;
	while ((p1.getCurrentHealth() > 0) && (m1->getCurrentHealth() >0)){
		int p1Atk = p1.attack() + (rand() % 6 + 1);
		int monstAtk = m1->attack() + (rand() % 6 + 1);
		std::cout << p1Atk << std::endl;
		std::cout << monstAtk << std::endl;
		if (p1Atk > monstAtk){
			m1->beHit(1);
			std::cout << "You hit the monster! " << std::endl;
			std::cout << "The monster has " << m1->getCurrentHealth() << " health left" << std::endl;
		}
		else if (p1Atk < monstAtk){
			p1.beHit(1);
			std::cout << "The monster hit you! " << std::endl;
			std::cout << "You have " << p1.getCurrentHealth() << " health left" << std::endl;
		}
		else {
			std::cout << "You too both miss! How can you both miss...... " << std::endl;
		}
	}
}


void capture(Player& p1, Monster* m1){
		std::cout << "A wild " << m1->getType() << " appeared!" << std::endl;
		std::cout << m1->display() << std::endl;
		int p1Skill = p1.attack() + (rand() % 6 + 1);
		int monstSkill = m1->attack() + (rand() % 6 + 1);
		std::cout << p1Skill << std::endl;
		std::cout << monstSkill << std::endl;
		if (p1Skill >= monstSkill){
			std::cout << "Gotcha! " << m1->getType() << " was caught!!! " << std::endl;
			p1.addMonster(m1);
		}
		else if (monstSkill > p1Skill){
			std::cout << "You failed! " << m1->getType() << " ran away... " << std::endl;
		}
}

int setExit(char dungeonArray[][20]){
	int output = rand() % 9;
	dungeonArray[output][19] = 'X';
	return output;
}

void displayDungeon(char dungeonArray[][20]){
	for (int x = 0; x < 10; x++){
		for (int y = 0; y < 20; y++){
			std::cout << dungeonArray[x][y] << " ";
		}
		std::cout << '\n';
	}
}

void spawnMonsters(char dungeonArray[][20], Monster* m1){

}

bool checkForMonsters(Player& p1, int xPos, int yPos, std::vector<Monster*> monsterList){
	bool found = false;
	int i = 0;
	do{
		if (monsterList[i]->XPos() == xPos && monsterList[i]->YPos() == yPos){
			found = true;
		}
		else {
			i++;
		}
	} while (!found && i < monsterList.size());
	return found;
}

void generateDungeon(Player& p1, char dungeonArray[][20], char testMode){
	if (testMode == 'Y'){
		for (int x = 0; x < 10; x++){
			for (int x = 0; x < 10; x++){
				for (int y = 0; y < 20; y++){
					if (p1.confirmPlayerPos(x, y)){
						dungeonArray[x][y] = '@';
					}
					else if (dungeonArray[x][y] == 'X') {
						dungeonArray[x][y] = 'X';
					}
					else if (dungeonArray[x][y] == 'B'){
						dungeonArray[x][y] = 'B';
					}
					else if (dungeonArray[x][y] == 'P'){
						dungeonArray[x][y] = 'P';
					}
					else if (dungeonArray[x][y] == 'E'){
						dungeonArray[x][y] = 'E';
					}
					else if (dungeonArray[x][y] == 'O'){
						dungeonArray[x][y] = 'O';
					}
					else {
						dungeonArray[x][y] = '-';
					}
				}
			}
		}
	}
	else {
		for (int x = 0; x < 10; x++){
			for (int y = 0; y < 20; y++){
				if (p1.confirmPlayerPos(x, y)){
					dungeonArray[x][y] = '@';
				}
				else {
					dungeonArray[x][y] = '-';
				}
			}
		}
	}

	
}