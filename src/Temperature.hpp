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
 * @brief This class allows us to generate data for the Temperature
 * It's a derivation class of Sensor and we chose the type float for the Temperature
 */

class Temperature : public Sensor<float> {


  public :

	/*
	 * @brief Default Constructor
	 */

	Temperature();

	/*
	 * @brief Destroyer of the class
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
	 *@param egalObject_p Object of the Temperature class
	 */

	Temperature & operator=(const Temperature& egalObject_p);

	/*
	* @brief Allows the class Scheduler to recover Temperature Data
	* @return A random value (type float) thanks to the function aleaGenVal (In this methods we just give two numbers for our range of value )
	*/

	float getData() override ;

};


#endif /* TEMPERATURE_HPP_ */
