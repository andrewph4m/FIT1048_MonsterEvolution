#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <time.h>


#include "Monster.h"
#include "EvolvedMonster.h"
#include "Character.h"
#include "Item.h"

class Player : public Character{
private:
	std::string playerName;
	std::vector<Monster*> monsterList;
public:
	bool confirmPlayerPos(int x, int y);


	Player(std::string newName);
	Player(std::string newName, int startXPos, int startYPos);
	~Player();


	std::string display();
	void addMonster(Monster* m);

	
	
	void setPlayerName(std::string newName);

	int setInitPos();

	int getMonsterNumber();

	int getNumOfMonsterTypes(std::string monstType);

	int getTotalTypeHealth(std::string monstType);

	int getTotalTypeSkill(std::string monstType);

	int removeMonster(std::string monstType);

	void movement(int xPos, int yPos, int destX, int destY);

};



#endif // PLAYER_H