#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

class Character{
protected:
	int skillLevel;
	int currentHealth;
	int maxHealth;
	int xPosition;
	int yPosition;
public:
	Character();
	virtual ~Character();


	virtual int XPos();
	virtual int YPos();
	virtual int getCurrentHealth();
	virtual int getSkillLevel();

	virtual int attack();
	void beHit(int amount);

	void setXPosition(int newXPos);
	void setYPosition(int newYPos);
	void setXandYPosition(int newXPos, int newYPos);

	void increaseHealth(int increaseHealth);

	virtual std::string display();
};


#endif