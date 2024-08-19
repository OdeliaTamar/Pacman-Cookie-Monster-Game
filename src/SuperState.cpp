#include "SuperState.h"
#include"RegularState.h"
#include "Pacman.h"
#include "Reasources.h"
#include "Level.h"
#include"Door.h"
#include "Key.h"
#include"Demon.h"
#include "EatDemonPacState.h"
std::unique_ptr<PacmanState> SuperState::pacmanType(Input input)
{
	if (input == REGULAR)
		return std::make_unique<RegularState>();
	else if (input == EAT_DEMON)
		return  std::make_unique<EatDemonPacState>();
	return NULL;
}
//-------------------------------------
void SuperState::collideDoor(Pacman& pacman, Door& door)
{ 
	door.updateDead();//break the door
	door.getKey()->updateDead();//delete the key
}
//-------------------------------------
void SuperState::setImage(Pacman& pacman)
{
	pacman.getSprite().setTexture(Reasources::getInstance().getTexture(Pictures::superPacman));
}
