#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

#include "GameObject.h"
#include <string>

class Projectile : public GameObject
{
public:
	Projectile(SDL_Rect position);
private:
};

#endif // !__PROJECTILE_H__