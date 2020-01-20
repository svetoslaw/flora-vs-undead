#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

#include "GameObject.h"
#include <string>

class Projectile : public GameObject
{
public:
	Projectile(SDL_Rect position);
	void setType(std::string t);
	std::string getType();
private:
	std::string type;
};

#endif // !__PROJECTILE_H__