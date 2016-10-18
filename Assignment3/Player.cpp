#include "Player.h"
#include <sstream>
#include <time.h>
#include <vector>

Player::Player(std::string newName){
	playerName = newName;
	skillLevel = 6;
	maxHealth = 10;
	currentHealth = maxHealth;
}


Player::~Player(){
}

bool Player::confirmPlayerPos(int x, int y){
	return(x == XPos() && y == YPos());
}

std::string Player::display(){
	std::stringstream ss;
	ss << "Name : " << playerName << std::endl;
	ss << "Skill level: " << skillLevel << std::endl;
	ss << "Current Health: " << currentHealth << std::endl;
	ss << "Monster: " << std::endl; 
	for (int i = 0; i < monsterList.size(); i++){
		ss << monsterList[i]->displayMonster() << std::endl;
	}
	ss << "Current position: " << xPosition << " " << yPosition << std::endl;

	return ss.str();
}

void Player::addMonster(Monster* m){
	monsterList.push_back(m);
}

void Player::setPlayerName(std::string newName){
	playerName = newName;
}

void Player::setInitPos(){
	srand(time(NULL));
	xPosition = rand() % 9;
	yPosition = 0;
}


void Player::movement(int xPos, int yPos, int destX, int destY){
	if (destX < 0 || destX > 9 || destY < 0 || destY > 19){
		std::cout << "You bump into a wall, you donut" << std::endl;
		system("Pause");
	}
	else {
		xPosition = destX;
		yPosition = destY;
	}

};