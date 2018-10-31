#include "Entity.h"

Entity::Entity(std::string identifier, std::string description, std::string examined, bool shouldEnter)
{
	m_identifier = identifier;
	m_description = description;
	m_examined = examined;
	m_shouldEnter = shouldEnter;
}

Entity::~Entity()
{
	m_children.clear();
}

void Entity::setParent(std::shared_ptr<Entity> parent)
{
	m_children.push_back(parent);
}

void Entity::addChild(std::shared_ptr<Entity> child)
{
	child.get()->setParent(std::shared_ptr<Entity>(this));
	m_children.push_back(child);
}

std::shared_ptr<Entity> Entity::find(std::string identifier)
{
	return nullptr; // TODO
}

std::string Entity::getIdentifier() const
{
	return m_identifier;
}

std::string Entity::getDescription() const
{
	return m_description;
}

std::string Entity::getExamined() const
{
	if (m_examined == "" && m_parent)
		return m_parent.get()->getExamined();

	return m_examined;
}

std::shared_ptr<Entity> Entity::getParent()
{
	return m_parent;
}

std::vector<std::shared_ptr<Entity>> Entity::getChildren()
{
	return m_children;
}
