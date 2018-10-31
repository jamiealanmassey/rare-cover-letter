#include "Game.h"

Game::Game()
{
	std::string doorDescription = "";
	doorDescription += ": There doesn't seem to be anything of value here";

	std::string bedDescription = "";
	bedDescription += ": Various items are scattered over your bed.";

	std::string deskDescription = "";
	deskDescription += ": You are sat in front of your desk. There are lots of objects on the desk\n";
	deskDescription += ": and various applications open and running on your computer's desktop.";

	std::string radiatorDescription = "";
	radiatorDescription += ": This side of the room seems quite empty.";

	Entity* creeper = new Entity({ "creeper", "plushie" }, ": You cuddle the plushie but it starts hissing at you, you are unsure of its intentions,\n: and ultimately decide to put it back neatly");
	Entity* visual = new Entity({ "visual", "studio" }, ": You flick open the IDE and find some C# code written for Unity from the previous day.\n: A little time passes as you debug those pesky lines of code.\n: Finally, you solve the problem! Take that, bug!");
	Entity* atom = new Entity({ "atom" }, ": As you glance over the folder-structure you see some code in mostly HTML, CSS and JavaScript\n: for various website in the making; among them are exercises for University modules, personal projects\n: and a website for your Group Project.");
	Entity* git = new Entity({ "git", "bash" }, ": Git bash sits there idly waiting for code to be committed to lots of repositories!");
	Entity* league = new Entity({ "league", "of", "legends" }, ": As you enter champ select you encounter a hostile 'friendly' player, surely\n: this game is going to be good? 30 minutes pass and victory is yours!");
	Entity* emulator = new Entity({ "n64", "emulator" }, ": The emulator boots up and you see large letters covering the screen\n: reading 'Banjo-Kazooie'. Many hours pass as you are absolutely immersed in the experience!");
	Entity* rollercoaster = new Entity({ "rollercoaster", "tycoon" }, ": Fond memories come flooding back from childhood as you glance over an icon\n: reading 'Rollercoaster Tycoon', the game that started your\n: games development journey.");
	Entity* webmail = new Entity({ "webmail" }, ": You check over your emails, but the inbox seems somewhat empty due to\n: the fact it is a Saturday. Instead you spend your time clearing up and organising any\n: recently opened emails from the day before.");

	Entity* mobile = new Entity({ "mobile", "phone" }, ": You hear beeps come from your mobile phone. Events have just been posted for\n: the following week in Tabletop Gaming and Computer Science Society.\n: You respond with 'going', it's super effective!");
	Entity* laptop = new Entity({ "laptop" }, ": You pull open your laptop and see a half-finished cover letter to a game development company called Rare.\n: It mentions many characteristics about yourself, but you do not feel satisfied; surely, there must\n: be something else you can do to grab their attention and showcase your skills!");

	Entity* vinyl = new Entity({ "vinyl", "player" }, ": You flick on the Vinyl Player and it starts playing some Twenty-One Pilots.\n: You bounce along to the beats.\n: You see a substantial collection of 15 or more other Vinyl’s on display next to the player.");
	Entity* book = new Entity({ "book" }, ": You pick up the book, the cover reads “Step Up and Focus”.\n: You skim through the pages and find lots of information and techniques to improve your self-evaluation\n: and how to approach situations that you encounter. +5 to confidence!");

	Area* area0 = new Area("door", doorDescription);
	Area* area1 = new Area("desk", deskDescription);
	Area* area2 = new Area("bed", bedDescription);
	Area* area3 = new Area("radiator", radiatorDescription);

	area1->placeEntity(std::shared_ptr<Entity>(creeper));
	area1->placeEntity(std::shared_ptr<Entity>(visual));
	area1->placeEntity(std::shared_ptr<Entity>(atom));
	area1->placeEntity(std::shared_ptr<Entity>(git));
	area1->placeEntity(std::shared_ptr<Entity>(league));
	area1->placeEntity(std::shared_ptr<Entity>(emulator));
	area1->placeEntity(std::shared_ptr<Entity>(rollercoaster));
	area1->placeEntity(std::shared_ptr<Entity>(webmail));

	area2->placeEntity(std::shared_ptr<Entity>(mobile));
	area2->placeEntity(std::shared_ptr<Entity>(laptop));

	area3->placeEntity(std::shared_ptr<Entity>(vinyl));
	area3->placeEntity(std::shared_ptr<Entity>(book));

	m_areas.push_back(std::unique_ptr<Area>(area0));
	m_areas.push_back(std::unique_ptr<Area>(area1));
	m_areas.push_back(std::unique_ptr<Area>(area2));
	m_areas.push_back(std::unique_ptr<Area>(area3));

	m_currentArea = 0;
}

Game::~Game()
{
}

int32_t Game::execute()
{
	std::cout << "               ============================================               " << std::endl;
	std::cout << "               ==                A RARE DAY              ==               " << std::endl;
	std::cout << "               ==              by Jamie Massey           ==               " << std::endl;
	std::cout << "               ============================================               " << std::endl << std::endl;

	std::cout << ": The sun shines in through the curtains. You pick up and look at your phone." << std::endl;
	std::cout << ": It reads 9am on a Saturday. You sit up and get ready for the day. " << std::endl;
	std::cout << ": Looking around the room you can see your BED, RADIATOR, and DESK." << std::endl << std::endl;

	std::cout << " -- available commands: examine <item>, move <area>, help <command>, describe, exit" << std::endl << std::endl;

	while (true)
	{
		std::cout << "[" << m_areas[m_currentArea].get()->getName().c_str() << "]> ";
		std::string nextLine = "";
		std::getline(std::cin, nextLine);

		m_expressions.clear();
		m_expressions = parseExpressions(nextLine);
		m_tokens.clear();
		m_tokens = extractTokens(m_expressions);
		if (m_tokens.size() > 0 && m_tokens[0] == ExprToken::EXIT)
			return 0;

		parse();
	}

	return 1;
}

std::vector<std::string> Game::parseExpressions(std::string expr)
{
	std::vector<std::string> result;
	std::stringstream stream(expr);
	std::string element;

	while (std::getline(stream, element, ' '))
	{
		std::transform(element.begin(), element.end(), element.begin(), ::tolower);
		result.push_back(element);
	}
	
	return result;
}

std::vector<ExprToken> Game::extractTokens(std::vector<std::string> expressions)
{
	std::vector<ExprToken> tokens;
	for each (std::string element in expressions)
	{
		if (element == "examine")
			tokens.push_back(ExprToken::EXAMINE);
		else if (element == "describe")
			tokens.push_back(ExprToken::DESCRIBE);
		else if (element == "move")
			tokens.push_back(ExprToken::MOVE);
		else if (element == "exit")
			tokens.push_back(ExprToken::EXIT);
		else if (element == "help")
			tokens.push_back(ExprToken::HELP);
		else
			tokens.push_back(ExprToken::WORD);
	}

	return tokens;
}

std::vector<std::string> Game::collate()
{
	std::vector<std::string> results;
	for (size_t i = 0; i < m_expressions.size(); i++)
	{
		if (m_tokens[i] == ExprToken::WORD)
			results.push_back(m_expressions[i]);
	}

	return results;
}

void Game::parse()
{
	if (m_tokens.empty())
		return;

	std::cout << std::endl;
	if (m_tokens[0] == ExprToken::EXAMINE)
		processExamine();
	else if (m_tokens[0] == ExprToken::MOVE)
		processMove();
	else if (m_tokens[0] == ExprToken::HELP)
		processHelp();
	else if (m_tokens[0] == ExprToken::DESCRIBE)
		std::cout << m_areas[m_currentArea].get()->getDescription() << std::endl;
	else
		std::cout << "! nothing happens." << std::endl;

	std::cout << std::endl;
}

void Game::processMove()
{
	if (m_tokens.size() <= 1 || m_tokens[1] != ExprToken::WORD)
	{
		std::cout << "! no location specified" << std::endl;
		return;
	}

	bool areaChanged = false;
	for (size_t i = 0; i < m_areas.size(); i++)
	{
		if (m_areas[i].get()->getName() == m_expressions[1])
		{
			m_currentArea = i;
			areaChanged = true;
		}
	}

	if (areaChanged)
	{
		std::cout << "! moved to [" << m_areas[m_currentArea].get()->getName() << "]" << std::endl;
		std::cout << m_areas[m_currentArea].get()->getDescription().c_str() << std::endl;
	}
	else
		std::cout << "! [" << m_expressions[1] << "] is not somewhere you can move to" << std::endl;
}

void Game::processExamine()
{
	if (m_tokens.size() <= 1)
	{
		std::cout << "! you must specify an object" << std::endl;
		return;
	}		

	bool entityFound = false;
	for each (std::shared_ptr<Entity> entity in m_areas[m_currentArea].get()->getEntities())
	{
		if (entity.get()->isIdentified(collate()))
		{
			entity.get()->description();
			entityFound = true;
			break;
		}
	}

	if (!entityFound)
		std::cout << "! object does not exist" << std::endl;
}

void Game::processHelp()
{
	if (m_tokens.size() <= 1 || m_tokens[1] == ExprToken::WORD)
	{
		std::cout << "! no command specified" << std::endl;
		return;
	}

	if (m_tokens[1] == ExprToken::DESCRIBE)
		std::cout << "! 'describe' will give you an idea of where you are and what entities exist" << std::endl;
	else if (m_tokens[1] == ExprToken::EXAMINE)
		std::cout << "! 'examine <item>' allows you to examine objects in your vacinity" << std::endl;
	else if (m_tokens[1] == ExprToken::HELP)
		std::cout << "! uuuhhmm ... yes?" << std::endl;
	else if (m_tokens[1] == ExprToken::EXIT)
		std::cout << "! exits from the game!" << std::endl;
	else if (m_tokens[1] == ExprToken::MOVE)
		std::cout << "! 'move <area>' allows you to move to different areas of the game such as the BED" << std::endl;
	else
		std::cout << "! " << m_expressions[1] << " is not a valid command." << std::endl;
}
