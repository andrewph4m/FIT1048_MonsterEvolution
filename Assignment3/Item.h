#ifndef ITEM_H
#define ITEM_H

#include "Include.h"
#include <iostream>
#include <string>

class Item {

public:
	Item();
	Item(std::string i, itemType t, int p);
	~Item();
	std::string getName();

private:
	std::string itemName;
	itemType iType;
	int pointsModifier;

};

#endif