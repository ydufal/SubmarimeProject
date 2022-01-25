/*
* @author Dufale Yann
* @file Temperature.hpp
* @date 29/09/2021
* @brief This class with the class Sensor allows us to generate data for the Temperature
*/

//
// Define guards
#ifndef TEMPERATURE_HPP_
#define TEMPERATURE_HPP_

#include "Sensor.hpp"
/*
 * @class Temperature
 * @brief This class with the class Sensor allows us to generate data for the Temperature
 */

class Temperature : public Sensor {


  public :

	/*
	 * @brief Default Constructor
	 */

	Temperature();

	/*
	 * @brief Destructor of the class
	 */

	virtual ~Temperature();

	/*
	 * @brief Constructor by recopy
	 * @param copyObject_p Object of the Temperature class
	 */

	Temperature(const Temperature& copyObject_p) ;

	/*
	 *@brief Affectation Operator
	 *@return this (type Temperature) Self-reference symbol
	 *@param copyObject_p Object of the Temperature class
	 */

	Temperature & operator=(const Temperature& copyObject_p);

	/*
	* @brief Allows the scheduler to take a random value from the Temperature sensor
	* @return A random value (type int) thanks to the function aleaGenVal (In this methods we just give two numbers for our range of value )
	*/

	int getData() override ;

};


#endif /* TEMPERATURE_HPP_ */
