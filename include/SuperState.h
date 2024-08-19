#pragma once
#include "PacmanState.h"
class Level;
class Door;
class Key;
class Demon;

class SuperState :public PacmanState
{
public:
	SuperState() = default;
	virtual ~SuperState() {}

	virtual std::unique_ptr<PacmanState> pacmanType(Input input)override;
	virtual void collideDemon(Pacman& pacman, Demon& demon)override{}
	virtual void collideDoor(Pacman& pacman, Door& door)override;
	virtual void setImage(Pacman& pacman) override;
private:

};
