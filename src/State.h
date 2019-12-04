#ifndef __STATE_H__
#define __STATE_H__
#include <iostream>

class State 
{
public:
	void setState(std::string s);
	std::string getState();
private:
	std::string state;
};

#endif
