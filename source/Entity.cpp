#include "Entity.h"

Entity::Entity(std::vector<std::string> identifier, std::string description)
{
	m_identifier = identifier;
	m_description = description;
}

Entity::~Entity()
{
}

bool Entity::isIdentified(std::vector<std::string> expressions) const
{
	for (auto expr : expressions)
	{
		auto hasExpression = false;
		for (auto identifier : m_identifier)
		{
			if (identifier == expr)
				hasExpression = true;
		}

		if (!hasExpression)
			return false;
	}

	return true;
}

void Entity::description()
{
	std::cout << m_description.c_str() << std::endl;
}

std::string Entity::getIdentifier()
{
	std::string result = "";
	for (auto identifier : m_identifier)
		result += (" " + identifier);

	return result;
}
