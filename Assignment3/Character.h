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

	virtual void setXPosition(int newXPos);
	virtual void setYPosition(int newYPos);
	virtual void setXandYPosition(int newXPos, int newYPos);

	virtual void increaseHealth(int increaseHealth);
	virtual void increaseSkillLevel(int skillLevel);

	virtual void setHealth(int newHealth);
	virtual void setMaxHealth(int newHealth);	
	virtual void setSkillLevel(int newSkillLevel);

	virtual std::string display();
};


#endif