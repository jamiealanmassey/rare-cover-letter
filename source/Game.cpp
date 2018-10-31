#include "Game.h"

Game::Game()
{
	m_running = true;
}

Game::~Game()
{
}

void Game::execute()
{
	while (m_running)
	{
		std::string nextLine = "";
		std::cin >> nextLine;

		std::vector<std::string> expressions = parseExpressions(nextLine);
		if (expressions.empty())
			return;

		std::vector<Game::ExprToken> tokens = extractTokens(expressions);
		if (tokens[0] == Game::ExprToken::EXIT)
			return;

		parse(expressions, tokens);
	}
}

std::vector<std::string> Game::parseExpressions(std::string expr)
{
}

std::vector<Game::ExprToken> Game::extractTokens(std::vector<std::string>)
{
}

void Game::parse(std::vector<std::string> expressions, std::vector<Game::ExprToken> tokens)
{
	if (tokens[0] == Game::ExprToken::EXAMINE)
		std::cout << m_currentEntity->getExamined() << std::endl;
	else if (tokens[0] == Game::ExprToken::INSPECT)
	{
		std::string result = "";
		for (int i = 1; i < tokens.size(); i++)
		{
			if (tokens[i] == Game::ExprToken::WORD)
				result += expressions[i];
		}

		std::cout << m_currentEntity->
	}
	else if (tokens[0] == Game::ExprToken::LEAVE)
	{

	}
	else if (tokens[0] == Game::ExprToken::EXIT)
	{

	}
	else if (tokens[0] == Game::ExprToken::HELP)
	{
		// TODO: Help text
	}
}
