/*
* @author Dufale Yann
* @file Pression.hpp
* @date 29/09/2020
* @brief This class with the class Sensor allows us to generate data for the Pression
*/

//
// Define guards
#ifndef PRESSION_HPP_
#define PRESSION_HPP_

#include "Sensor.hpp"
/*
 * @class Pression
 * @brief This class with the class Sensor allows us to generate data for the Pression
 */

class Pression : public Sensor {

  public :

	/*
	 * @brief Default Constructor
	 */

	Pression();

	/*
     * @brief Default Desctructor
	 */

	virtual ~Pression();


	/*
	 * @brief Constructor by recopy
	 * @param copyObject_p Object of the Pression class
	 */

	Pression(const Pression& copyObject_p);

	/*
	*@brief Affectation Operator
	*@return this (type Pression) Self-reference symbol
	*@param copyObject_p Object of the Pression class
	*/

	Pression & operator=(const Pression& copyObject_p);

	/*
	* @brief Allows the scheduler to take a random value from the Pression sensor
	* @return A random value (type int) thanks to the function aleaGenVal (In this methods we just give two numbers for our range of value )
	*/

	int getData() override ;

};

#endif /* PRESSION_HPP_ */
