#ifndef EVOLVEDMONSTER_H
#define EVOLVEDMONSTER_H

#include "Character.h"
#include "Monster.h"

class EvolvedMonster : public Monster{
private:
	int powerMod;
public:
	EvolvedMonster();
	~EvolvedMonster();
	virtual void setSkillLevel();
	virtual void setHealth();
	virtual void setPowerModifier();
	virtual int getPowerModifier();
};

#endif