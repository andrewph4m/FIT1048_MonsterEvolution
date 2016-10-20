#ifndef MONSTER_H
#define MONSTER_H

#include <time.h>
#include <string>
#include <iostream>

#include "Include.h"
#include "Character.h"


class Monster : public Character{
protected:
	static int numOfMonsters;
	monsterType* mType;

public:
	Monster(monsterType t);
	virtual ~Monster();
	virtual std::string displayMonster();
	virtual std::string getType();

};

#endif