#include "State.h"

void State::setState(std::string s) 
{
	state = s;
}

std::string State::getState()
{
	return state;
}