#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <time.h>


#include "Monster.h"
#include "Character.h"

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
	void setInitPos();

	void movement(int xPos, int yPos, int destX, int destY);

};



#endif // PLAYER_H