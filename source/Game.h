#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <memory>
#include <iostream>

#include "GameFactory.h"

/**
 * examine		  | Examines the surroundings to try and find what exists here
 * inspect [item] | Inspects an items (this may trigger a change of place)
 * leave		  | Leaves the current Entity to go somewhere else
 * help			  | Returns this list of commands
 */

class Game
{
private:
	enum ExprToken {
		EXAMINE = 0,
		INSPECT = 1,
		LEAVE = 2,
		WORD = 3,
		HELP = 4,
		EXIT = 5,
	};

public:
	Game();
	~Game();

	void execute();

private:
	std::vector<std::string> parseExpressions(std::string expr);
	std::vector<ExprToken>   extractTokens(std::vector<std::string>);

	void parse(std::vector<std::string> expressions, std::vector<ExprToken> tokens);

protected:
	bool m_running;
	std::shared_ptr<Entity> m_currentEntity;
};

#endif // _GAME_H
