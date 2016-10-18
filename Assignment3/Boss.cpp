#include "Boss.h"
#include <sstream>

Boss::Boss(monsterType t) : Monster(t){
	mType = new monsterType(t);
	skillLevel = 10;
	maxHealth = 20;
	currentHealth = maxHealth;
}

Boss::~Boss(){
	
}

std::string Boss::displayMonster(){
	std::stringstream ss;
	ss << "Type: Skeletor " << std::endl;
	ss << "Skill level: " << skillLevel << std::endl;
	ss << "Current health: " << currentHealth << std::endl;
	return ss.str();
}

void Boss::resetHealth(){
	currentHealth = 20;
}

void Boss::resetSkillLevel(){
	skillLevel = 10;
}