#include "Gift.h"
#include "MovingObject.h"
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

Gift::Gift(const enum Pictures& p, sf::Vector2f position):StaticObject(p,position)
{
}

