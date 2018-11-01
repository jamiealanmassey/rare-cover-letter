#include "Area.h"

Area::Area(std::string name, std::string description)
{
	m_name = name;
	m_description = description;
}

Area::~Area()
{
}

void Area::placeEntity(std::vector<std::string> identifiers, std::string description)
{
	m_entities.emplace_back(std::make_unique<Entity>(identifiers, description));
}

std::string Area::getName() const
{
	return m_name;
}

std::string Area::getDescription()
{
	std::string result = m_description;
	if (m_entities.size() > 0)
	{
		result.append(" \n\n");
		result.append("   items\n");
		result.append(" ---------\n");
		result.append(processEntities());
	}

	return result;
}

Entity* Area::getEntity(size_t index)
{
	return m_entities[index].get();
}

size_t Area::getEntityCount() const
{
	return m_entities.size();
}

std::string Area::processEntities()
{
	std::string result = "";
	for (size_t i = 0; i < m_entities.size(); i++)
	{
		
		if (i > 3 && i < m_entities.size() - 1 && i % 4 == 1)
			result += (",\n" + m_entities[i].get()->getIdentifier());
		else if (i > 0)
			result += ("," + m_entities[i].get()->getIdentifier());
		else
			result += m_entities[i].get()->getIdentifier();
	}

	return result;
}
