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
	 * \param entity shared_ptr referencing the Entity to be added
	 */
	void placeEntity(std::shared_ptr<Entity> entity);

	/** \returns the name of this Area as a string **/
	std::string getName() const;

	/** \returns the description of this Area with any child Entities listed **/
	std::string getDescription();

	/** \returns a vector of shared_ptr<Entity> objects stored in this Area **/
	std::vector<std::shared_ptr<Entity>> getEntities() const;

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
	std::vector<std::shared_ptr<Entity>> m_entities;    ///< stores shared_ptr objects with all entities that are relevant to this Area
};

#endif // _AREA_H
