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
 * It's a derivation class of Sensor and we chose the type float here for the Humidity values
 */

class Humidity : public Sensor<float> {

  public :

	/*
	 * @brief Default Constructor
	 */

	Humidity();

	/*
	 * @brief Destroyer of the Class
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
	*@param egalObject_p Object of the Humidity class
	*/

	Humidity & operator=(const Humidity& egalObject_p);

	/*
	* @brief Allows the class Scheduler to recover humidity Data
	* @return A random value (type float) thanks to the function aleaGenVal (In this methods we just give two numbers for our range of value )
	*/

	float getData() override;
};



#endif /* HUMIDITY_HPP_ */
