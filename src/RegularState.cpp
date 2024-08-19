#include "RegularState.h"
#include"SuperState.h"
#include "Pacman.h"
#include "Reasources.h"
#include "Level.h"
#include "EatDemonPacState.h"
std::unique_ptr<PacmanState> RegularState::pacmanType(Input input)
{
	if (input == SUPER)
		return  std::make_unique<SuperState>();
	else if (input == EAT_DEMON)
		return  std::make_unique<EatDemonPacState>();

	return NULL;
}
//-------------------------------------
void RegularState::collideDemon(Pacman& pacman, Demon& demon)
{
	pacman.updateLive(-1);
	pacman.getSprite().setPosition(pacman.getFirstPosition());
}
//-------------------------------------
void RegularState::collideDoor(Pacman& pacman, Door& door)
{
	pacman.setPosition();
}
//-------------------------------------
void RegularState::setImage(Pacman& pacman)
{
	pacman.getSprite().setTexture(Reasources::getInstance().getTexture(Pictures::pacman));
}
