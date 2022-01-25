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
 */

class Light : public Sensor {


  public :

	/*
	 * @brief Default Constructor
	 */

	Light();

	/*
	 * @brief Desctructor of the Class
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
	*@param copyObject_p Object of the Light class
	*/

	Light & operator=(const Light& copyObject_p);

	/*
	* @brief Allows the scheduler to take a random value from the Light sensor
	* @return A random value (type int) thanks to the function aleaGenVal (In this methods we just give two numbers for our range of value )
	*/

	int getData() override ;

};



#endif /* LIGHT_HPP_ */
