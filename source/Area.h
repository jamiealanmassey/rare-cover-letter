#ifndef _AREA_H
#define _AREA_H

#include <memory>

#include "Entity.h"

class Area
{
public:
	Area(std::string name, std::string description);
	~Area();

	void placeEntity(std::shared_ptr<Entity> entity);

	std::string getName() const;
	std::string getDescription();
	std::vector<std::shared_ptr<Entity>> getEntities() const;

private:
	std::string processEntities();

protected:
	std::string							 m_name;
	std::string						     m_description;
	std::vector<std::shared_ptr<Entity>> m_entities;
};

#endif // _AREA_H
