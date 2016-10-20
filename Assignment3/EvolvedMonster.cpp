#include "EvolvedMonster.h"

//constructor
EvolvedMonster::EvolvedMonster(monsterType newType) : Monster (newType){
	mType = new monsterType(newType);
	maxHealth = 0;
	currentHealth = maxHealth;
	skillLevel = 0;
	if (newType == Bugbear){
		powerMod = 1;
	}
	else if (newType == Platypie){
		powerMod = 2;
	}
	else if (newType == Emoo){
		powerMod = 3;
	}
}

EvolvedMonster::~EvolvedMonster(){
}

int EvolvedMonster::getPowerModifier(){
	return powerMod;
}

void EvolvedMonster::setPowerModifier(int newPowerMod){
	powerMod = newPowerMod;
}