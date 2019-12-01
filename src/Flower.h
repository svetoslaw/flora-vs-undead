#ifndef __FLOWER_H__
#define __FLOWER_H__
#include <string>

class Flower
{
public:
	Flower();
	void setName(std::string n);
	std::string getName();
	void setHealth(int h);
	int getHealth();
	void setShootingDamage(int sd);
	int getShootingDamage();
	void setShootingRange(int sr);
	int getShootingRange();
	void setPrice(int p);
	int getPrice();
protected:
	std::string name;
	int health, shootingDamage, shootingRange, price;
};

#endif // !__FLOWER_H__