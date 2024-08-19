#pragma once
#include "PacmanState.h"
class Level;
class RegularState:public PacmanState
{
public:
	RegularState()= default;
	virtual ~RegularState(){}

	virtual std::unique_ptr<PacmanState> pacmanType(Input input) override;
	virtual void collideDemon(Pacman& pacman, Demon& demon) override;
	virtual void collideDoor(Pacman& pacman, Door& door) override;
	virtual void setImage(Pacman& pacman) override;
private:

};
