#ifndef _AREA_H
#define _AREA_H

#include <memory>

#include "Entity.h"

/** 
 * \brief Area Class defining world
 * \details Defines an Area of the world with associated items (Entity objects) 
 * \version 1.0
 * \author Jamie Massey
 * \date October 2018
 * \copyright GNU General Public License
 */
class Area
{
public:
	/** 
	 * Area constructor 
	 *
	 * \param name string representation for the name of this Area
	 * \param description string representation for the description for this Area
	 */
	Area(std::string name, std::string description);

	/** Area Destructor **/
	~Area();

	/** 
	 * Adds an Entity as a shared_ptr to this Area object 
	 *
	 * \param identifiers vector list of identifiers that linearly describe this Entity
	 * \param description std::string representation to be outputted for this object
	 */
	void placeEntity(std::vector<std::string> identifiers, std::string description);

	/** \returns the name of this Area as a string **/
	std::string getName() const;

	/** \returns the description of this Area with any child Entities listed **/
	std::string getDescription();

	/** 
	 * Retrieve an entity at the specified index
	 *
	 * \param index number representation of the index to retrieve the Entity from
	 * \returns Raw memory pointer to the found Entity object
	 */
	Entity* getEntity(size_t index);

	/** \returns the number that represents the number of entities that are stored in this Area **/
	size_t getEntityCount() const;

private:
	/** 
	 * Helper function that helps produce the list of entities for getDescription() 
	 *
	 * \returns constructed string with all the entities together in one readable stream (including \n escape characters)
	 */
	std::string processEntities();

protected:
	std::string							 m_name;        ///< string representation storing the name of this Area
	std::string						     m_description; ///< string representation storing the description for this Area
	std::vector<std::unique_ptr<Entity>> m_entities;    ///< stores shared_ptr objects with all entities that are relevant to this Area
};

#endif // _AREA_H
