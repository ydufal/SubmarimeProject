/*
* @author Dufale Yann
* @file Light.hpp
* @date 29/09/2021
* @brief This class with the class Sensor allows us to generate data for the Light
*/

//
// Define guards
#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "Sensor.hpp"
/*
 * @class Light
 * @brief This class with the class Sensor allows us to generate data for the Light
 * It's a derivation class of Sensor and we chose the type bool here for the Light values
 */

class Light : public Sensor<bool> {

  public :

	/*
	 * @brief Default Constructor
	 */

	Light();

	/*
	 * @brief Destroyer of the Class
	 */

	virtual ~Light();

	/*
	 * @brief Constructor by recopy
	 * @param copyObject_p Object of the Light class
	 */

	Light(const Light& copyObject_p) ;

	/*
	*@brief Affectation Operator
	*@return this (type Light) Self-reference symbol
	*@param egalObject_p Object of the Light class
	*/

	Light & operator=(const Light& egalObject_p);

	/*
	* @brief Allows the class Scheduler to recover Light Data
	* @return A random value (type bool) thanks to the function aleaGenVal (In this methods we just give the range of value )
	*/

	bool getData() override;

};



#endif /* LIGHT_HPP_ */
