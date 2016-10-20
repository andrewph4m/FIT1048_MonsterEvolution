#ifndef SKELETOR_H
#define SKELETOR_H

#include "Monster.h"
#include <string>

class Boss : public Monster{
private:
	int powerMod = 2;
public:
	Boss(monsterType m);
	virtual ~Boss();
	virtual std::string displayMonster();
	virtual void resetSkillLevel();
	virtual void resetHealth();
	virtual int getPowerModifier();
};

#endif