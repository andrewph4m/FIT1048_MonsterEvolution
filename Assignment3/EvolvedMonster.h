#ifndef EVOLVEDMONSTER_H
#define EVOLVEDMONSTER_H

#include "Character.h"
#include "Monster.h"

class EvolvedMonster : public Monster{
private:
	int powerMod;
public:
	EvolvedMonster(monsterType newType);
	virtual ~EvolvedMonster();

	void setPowerModifier(int newPowerMod);
	int getPowerModifier();

};

#endif