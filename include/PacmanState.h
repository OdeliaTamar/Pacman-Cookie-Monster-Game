#pragma once
#include <memory>
enum Input
{
	REGULAR,SUPER,EAT_DEMON
};
class Pacman;
class Level;
class Door;
class Demon;

class PacmanState
{
public:
	PacmanState()=default;
	virtual ~PacmanState(){}
	
	virtual std::unique_ptr<PacmanState> pacmanType(Input input) = 0;
	virtual void collideDemon(Pacman& pacman,Demon& demon) = 0;
	virtual void collideDoor(Pacman& pacman, Door& door)= 0;
	virtual void setImage(Pacman& pacman) = 0;
private:

};
