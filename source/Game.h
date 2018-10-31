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

/**
 * \brief Game class (Game Manager)
 * \details Controls the overall flow of the game waiting for input and reacting to it
 * \version 1.0
 * \author Jamie Massey
 * \date October 2018
 * \copyright GNU General Public License
 */
class Game
{
public:
	/** Game Constructor **/
	Game();

	/** Game Destructor **/
	~Game();

	/** initialise all Area and Entity objects and associate them **/
	void initialise();

	/**
	 * Core execution loop of the game; the method waits for input from the user and once
	 * caught will pass that input and parse it in many different ways to form an output.
	 */
	void execute();

private:
	/**
	 * Takes the initial input string that is given by the user (via std::cin) to be parsed
	 * into a vector of strings (deliminated by spaces) storing the result in m_expressions
	 *
	 * \param expr initial user input from the last line
	 * \return vector of strings split by spaces
	 */
	std::vector<std::string> parseExpressions(std::string expr);

	/**
	 * Given the parsed expressions this function will compile a list of tokens that mirror
	 * that of the m_expressions in size and relating to the string at the same index
	 *
	 * \param expressions vector of previously parsed expressions
	 * \returns vector of tokens extracted from the expressions
	 */
	std::vector<ExprToken> extractTokens(std::vector<std::string> expressions);

	/** 
	 * Collates all expressions that are of type ExprToken::WORD into a vector
	 * so that multiple words can be used to identify Entity objects in the current Area
	 *
	 * \returns vector of strings to be used as identifiers
	 **/
	std::vector<std::string> collate();

	/** Core parse method acting as a control method for calling helper methods **/
	void parse();

	/** Helper method to process moving between rooms **/
	void processMove();

	/** Helper method to examine objects that exist in m_area[m_currentArea] **/
	void processExamine();

	/** Helper method to output help for a specified command **/
	void processHelp();

protected:
	int32_t                            m_currentArea; ///< index to identify the currently active Area
	std::vector<std::unique_ptr<Area>> m_areas;       ///< vector storing unique_ptr of Areas that exist in the game
	std::vector<std::string>           m_expressions; ///< vector of strings representing the expressions for this step
	std::vector<ExprToken>             m_tokens;      ///< vector of strings representing the tokens for this step
};

#endif // _GAME_H
