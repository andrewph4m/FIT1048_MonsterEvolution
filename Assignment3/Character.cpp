#include "Character.h"

#include<iostream>
#include <sstream>

Character::Character(){
	skillLevel = 0;
	maxHealth = 0;
	currentHealth = maxHealth;
}

Character::~Character(){
}

int Character::attack(){
	return (skillLevel);
}

int Character::getCurrentHealth(){
	return currentHealth;
}

int Character::getSkillLevel(){
	return skillLevel;
}

int Character::XPos(){
	return xPosition;
}

int Character::YPos(){
	return yPosition;
}


void Character::beHit(int amount){
	currentHealth -= amount;
	if (currentHealth > maxHealth){
		currentHealth = maxHealth;
	}
	else if (currentHealth < 0){
		currentHealth = 0;
	}
}

void Character::setXPosition(int newXPos){
	xPosition = newXPos;
};
void Character::setYPosition(int newYPos){
	yPosition = newYPos;
};


void Character::increaseHealth(int healthIncrease){
	currentHealth += healthIncrease;
}

void Character::increaseSkillLevel(int skillIncrease){
	skillLevel += skillIncrease;
}


std::string Character::display(){
	std::stringstream ss;
	ss << "Skill level: " << skillLevel << std::endl;
	ss << "Health: " << currentHealth << " / " << maxHealth << std::endl;
	return ss.str();
}

void Character::setXandYPosition(int newXPos, int newYPos){
	xPosition = newXPos;
	yPosition = newYPos;
}

void Character::setSkillLevel(int newSkill){
	skillLevel = newSkill;
}

void Character::setHealth(int newHealth){
	currentHealth = newHealth;
}

void Character::setMaxHealth(int newMaxHealth){
	maxHealth = newMaxHealth;
}