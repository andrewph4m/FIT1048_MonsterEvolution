#include "Monster.h"
#include <string>
#include <time.h>
#include <sstream>

int Monster::numOfMonsters = 0;

Monster::Monster(monsterType t){
	mType = new monsterType(t);
	skillLevel = rand() % 3 + 1;
	maxHealth = rand() % 6 + 3;
	currentHealth = maxHealth;
	numOfMonsters++;
}

Monster::~Monster(){
	numOfMonsters--;
}


std::string Monster::displayMonster(){
	std::stringstream ss;
	switch (*mType) {
	case Bugbear: ss << "Type: Bugbear" << std::endl; break;
	case Platypie: ss << "Type: Platypie" << std::endl; break;
	case Emoo: ss << "Type: Emoo" << std::endl; break;
	case Octopod: ss << "Type:Octopod" << std::endl; break;
	case Skeletor: ss << "Type:Skeletor" << std::endl; break;
	}
	ss << "Skill level: " << skillLevel << std::endl;
	ss << "Health: " << currentHealth << " / " << maxHealth << std::endl;
	ss << "Position: " << XPos() << " " << YPos() << std::endl;
	return ss.str();
}

std::string Monster::getType(){
	std::string output;
	switch (*mType) {
	case Bugbear: return "Bugbear"; break;
	case Platypie: return "Platypie"; break;
	case Emoo: return "Emoo"; break;
	case Octopod: return "Octopod"; break;
	case Skeletor: return "Skeletor"; break;
	}

}
