#include "EatDemonPacState.h"
#include"SuperState.h"
#include "Pacman.h"
#include "Reasources.h"
#include "Level.h"
#include "Demon.h"
#include"Door.h"
#include"RegularState.h"
std::unique_ptr<PacmanState> EatDemonPacState::pacmanType(Input input)
{
	if (input == REGULAR)
		return std::make_unique<RegularState>();
	else if (input == SUPER)
		return  std::make_unique<SuperState>();
	return NULL;
}
//---------------------------------------
void EatDemonPacState::collideDemon(Pacman& pacman,Demon& demon)
{
	demon.updateDead();//eat the demon
}
//---------------------------------------
void EatDemonPacState::collideDoor(Pacman& pacman, Door& door)
{
	pacman.setPosition();
}
//---------------------------------------
void EatDemonPacState::setImage(Pacman& pacman)
{
	pacman.getSprite().setTexture(Reasources::getInstance().getTexture(Pictures::EatDemon));
}
