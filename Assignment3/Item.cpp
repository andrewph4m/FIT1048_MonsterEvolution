
#include "Item.h"

Item::Item() {
}

Item::Item(std::string s, itemType t, int p) {
	itemName = s;
	iType = t;
	pointsModifier = p;
}

Item::~Item() {
}

std::string Item::getName() {
	return itemName;
}