/*
* @author Dufale Yann
* @file Humidity.hpp
* @date 29/09/2021
* @brief This class with the class Sensor allows us to generate data for the Humidity
*/

//
// Define guards
#ifndef HUMIDITY_HPP_
#define HUMIDITY_HPP_

#include "Sensor.hpp"
/*
 * @class Humidity
 * @brief This class with the class Sensor allows us to generate data for the Humidity
 */

class Humidity : public Sensor {

  public :

	/*
	 * @brief Default Constructor
	 */

	Humidity();

	/*
	 * @brief Destructor of the Class
	 */

	virtual ~Humidity();

	/*
	 * @brief Constructor by recopy
	 * @param copyObject_p Object of the Humidity class
	 */

	Humidity(const Humidity& copyObject_p) ;


	/*
	*@brief Affectation Operator
	*@return this (type Humidity) Self-reference symbol
	*@param copyObject_p Object of the Humidity class
	*/

	Humidity & operator=(const Humidity& copyObject_p);

	/*
	* @brief Allows the scheduler to take a random value from the Humidity sensor
	* @return A random value (type int) thanks to the function aleaGenVal (In this methods we just give two numbers for our range of value )
	*/

	int getData() override ;
};



#endif /* HUMIDITY_HPP_ */
