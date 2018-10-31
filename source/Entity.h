#ifndef _ENTITY_H
#define _ENTITY_H

#include <vector>
#include <memory>
#include <map>
#include <iostream>

/**
 * \brief Entity Class defining items
 * \details Defines an Item that can exist in the world and be stored in Areas
 * \version 1.0
 * \author Jamie Massey
 * \date October 2018
 * \copyright GNU General Public License
 */
class Entity
{
public:
	/**
	 * Entity Constructor
	 *
	 * \param identifier list of keywords that linearly put together identify this Entity
	 * \param description description that will be outputted when examined
	 */
	Entity(std::vector<std::string> identifier, std::string description);

	/** Entity Destructor **/
	~Entity();

	/**
	 * Compares the given input expressions against the stored identifiers to see 
	 * if this is the correct object
	 * 
	 * \param expressions list of expressions to be compared
	 * \returns true if the expressions match the identifiers
	 */
	bool isIdentified(std::vector<std::string> expressions) const;

	/** \returns stored m_description to be outputted **/
	void description();

	/**
	 * Compresses all identifiers into a single stream so that they can be displayed in
	 * a user-friendly way inside of the console
	 *
	 * \returns stream of the compiled identifiers from m_identifier
	 */
	std::string getIdentifier();

protected:
	std::string				 m_description; ///< stores description to be outputted to console
	std::vector<std::string> m_identifier;  ///< stores a list of identifiers that unified identify this object
};

#endif // _ENTITY_H
