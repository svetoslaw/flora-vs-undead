#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include "GameObject.h"
#include <string>

class Zombie : public GameObject
{
public:
	Zombie(SDL_Rect position);
	void setType(std::string t);
	std::string getType();
	void updateHealth(int h);
	int getHealth();
private:
	std::string type;
	int health = 200;
};

#endif // !__ZOMBIE_H__