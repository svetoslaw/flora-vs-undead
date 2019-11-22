#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>

class Player {
public:
	Player() {}
	void createPlayer(std::string name, int sunlight, int health);
	void setName(std::string n);
	std::string getName();
	void setSunlight(int s);
	//increasing over time or manual decrease after purchase.
	void updateSunlight(int us);
	int getSunlight();
	void setHealth(int h);
	int getHealth();
	void killPlayer();
	bool getStatus(); //check live or dead status of player.
private:
	std::string name;
	int sunlight, health;
	bool isAlive = true;
};

#endif // !__PLAYER_H__