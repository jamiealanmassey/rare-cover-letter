#ifndef _GAME_FACTORY_H
#define _GAME_FACTORY_H

#include "Entity.h"

class GameFactory
{
public:
	static GameFactory& instance();
	
	std::shared_ptr<Entity> populate();

public:
	GameFactory(GameFactory const&)    = delete;
	void operator=(GameFactory const&) = delete;
};

#endif //_GAME_FACTORY_H
