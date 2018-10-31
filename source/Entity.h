#ifndef _ENTITY_H
#define _ENTITY_H

#include <vector>
#include <memory>
#include <map>
#include <iostream>

class Entity
{
public:
	Entity(std::vector<std::string> identifier, std::string description);
	~Entity();

	bool isIdentified(std::vector<std::string> expressions) const;
	void description();

	std::string getIdentifier();

protected:
	std::string				 m_description;
	std::vector<std::string> m_identifier;
};

#endif // _ENTITY_H
