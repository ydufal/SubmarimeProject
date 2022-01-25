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

#include <stdlib.h>
#include <random>
#include <iostream>


/*
 * @class Sensor
 * @brief This class allows us to generate data with our subclass
 */

template<class T> // class Template
class Sensor{

  protected :

	T m_data ; //< This data is used in our sensors for the function getData in order to generate the data

	/*
	* @brief This function allow us to generate a random value of different type thanks to the template
	* @return A random value between a range in parameter
	* @param Two parameters (type int ) which allow us to define a range of value
	*/

	T aleaGenVal(const int& maxRange_p, const int& minRange_p)
	{
		return minRange_p + static_cast <T>(rand()) /( static_cast <T>(RAND_MAX/(maxRange_p-minRange_p))); //< return a random number
	}

	/*
	* @brief This function allow us to generate a random value of different type thanks to the template
	* @return A random value between a range in parameter
	* @param (type int ) which allow us to define a number of Value that we can generate
	*/

	T aleaGenVal(const int& nbValue_p)
	{
		return rand()%nbValue_p ;
	}

  public :

	/*
	* @brief Default Constructor
	*/

	Sensor(){};

	/*
	* @brief Default Destroyer
	*/

	virtual ~Sensor(){};

	/*
	* @brief Constructor by recopy
	* @param copyObject_p Object of the class Sensor
	*/

	Sensor(const Sensor<T>& copyObject_p){};


	/*
	*@brief Affectation Operator
	*@return this (type Sensor) Self-reference symbol
	*@param egalObject_p Object of the Sensor class
	*/

	Sensor<T> & operator=(const Sensor<T>& egalObject_p){return *this;};

	/*
	* @brief This function is an intermediate between the Scheduler and the subclass getData in order to access this data in the Scheduler
	* @return T value type in our program (int float or bool)
	*/

	virtual T getData(){return m_data;};

};


#endif /* SENSOR_HPP_ */
