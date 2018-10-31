#ifndef _ENTITY_H
#define _ENTITY_H

#include <vector>
#include <memory>

class Entity
{
public:
	Entity(std::string identifier, std::string description, std::string examined, bool shouldEnter);
	~Entity();

	void setParent(std::shared_ptr<Entity> parent);
	void addChild(std::shared_ptr<Entity> child);

	std::shared_ptr<Entity> find(std::string identifier);

	std::string getIdentifier()  const;
	std::string getDescription() const;
	std::string getExamined()    const;

	std::shared_ptr<Entity> getParent();
	std::vector<std::shared_ptr<Entity>> getChildren();

protected:
	bool m_shouldEnter;
	std::string m_identifier;
	std::string m_description;
	std::string m_examined;
	std::shared_ptr<Entity> m_parent;
	std::vector<std::shared_ptr<Entity>> m_children;
};

#endif // _ENTITY_H
