#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>

#include "Area.h"
#include "ExprToken.h"

/**
 * examine  [item]    | Examines objects that are specified by the user
 * move     [area]    | Moves the user to a different area of the room
 * describe           | Describes the users current location and what they see
 * exit			      | Leaves the game
 * help	    [command] | Displays a list of all commands available
 *
 * Area -> Section of the room in which the player currently exists and can 'move' to
 * Entity -> An object in the world that the player can interact with using 'examine'
 *
 */

class Game
{
public:
	Game();
	~Game();

	int32_t execute();

private:
	std::vector<std::string> parseExpressions(std::string expr);
	std::vector<ExprToken>   extractTokens(std::vector<std::string>);
	std::vector<std::string> collate();

	void parse();
	void processMove();
	void processExamine();
	void processHelp();

protected:
	int32_t currentArea;
	std::vector<std::unique_ptr<Area>> m_areas;
	std::vector<std::string> m_expressions;
	std::vector<ExprToken> m_tokens;
};

#endif // _GAME_H
