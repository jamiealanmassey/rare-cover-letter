#include "Area.h"

Area::Area(std::string name, std::string description)
{
	m_name = name;
	m_description = description;
}

Area::~Area()
{
}

void Area::placeEntity(std::shared_ptr<Entity> entity)
{
	m_entities.push_back(entity);
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
		result.append(" Items\n");
		result.append(" ---------\n");
		result.append(processEntities());
	}

	return result;
}

std::vector<std::shared_ptr<Entity>> Area::getEntities() const
{
	return m_entities;
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
