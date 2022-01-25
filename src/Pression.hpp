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
 * It's a derivation class of Sensor and we chose the type int here for the pression
 */

class Pression : public Sensor<int> {


  public :

	/*
	 * @brief Default Constructor
	 */

	Pression();

	/*
     * @brief Default Destroyer
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
	*@param egalObject_p Object of the Pression class
	*/

	Pression & operator=(const Pression& egalObject_p);

	/*
	* @brief Allows the class Scheduler to recover Pression Data
	* @return A random value (type int) thanks to the function aleaGenVal (In this methods we just give two numbers for our range of value )
	*/

	int getData() override;

};

#endif /* PRESSION_HPP_ */
