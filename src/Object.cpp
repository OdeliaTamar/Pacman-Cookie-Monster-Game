#include "Object.h"
#include"Cookie.h"
#include "Wall.h"
#include "Door.h"
#include"Key.h"
#include "DemonFreezeGift.h"
#include "TimeGift.h"
#include"LifeGift.h"
#include "Pacman.h"
#include"SmartDemon.h"
#include "StupidDemon.h"
#include "Level.h"


Object::Object(const enum Pictures& p, sf::Vector2f position)
{
	//set the sprite of the object
	m_sprite.setTexture(Reasources::getInstance().getTexture(p));
	m_sprite.setPosition(position);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);// Set the origin of the sprite to its center

}
//-------------------------------------------
void Object::draw()
{
	Reasources::getInstance().getWindow().draw(m_sprite);
}
//-------------------------------------------
bool Object::colideWith(Object* obj)
{
	return m_sprite.getGlobalBounds().intersects(obj->m_sprite.getGlobalBounds());//check collision

}