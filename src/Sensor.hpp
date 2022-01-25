/*
* @author Dufale Yann
* @file Sensor.hpp
* @date 29/09/2021
* @brief This class allows us to generate data with our subclass
*/

//
// Define guards
#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#include <ctime>
#include <cstdlib>

/*
 * @class Sensor
 * @brief This class allows us to generate data with our subclass
 */

class Sensor{


  public :

	/*
	* @brief Default Constructor
	*/

	Sensor();

	/*
	* @brief Default Destructor
	*/

	virtual ~Sensor();

	/*
	* @brief Constructor by recopy
	* @param copyObject_p Object of the class Sensor
	*/

	Sensor(const Sensor& copyObject_p);


	/*
	*@brief Affectation Operator
	*@return this (type Sensor) Self-reference symbol
	*@param copyObject_p Object of the Sensor class
	*/

	Sensor & operator=(const Sensor& copyObject_p);

	/*
	 * @brief This function is an intermediate between the Scheduler and the subclass getData
	 */

	virtual int getData();

  protected :

	/*
	* @brief This function allow us to generate a random value
	* @return A random value between a range in paramater
	* @param Two paramaters (type int ) which allow us to define a range of value
	*/

	int aleaGenVal(const int& maxRange_p, const int& minRange_p)  ;
};


#endif /* SENSOR_HPP_ */
