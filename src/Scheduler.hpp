/*
* @author Dufale Yann
* @file Scheduler.hpp
* @date 29/09/2021
* @brief This class will define the frequency at which the data from the sensors will be retrieved
*to be transmitted to the server.
*/

//
// Define guards
#ifndef SCHEDULER_HPP_
#define SCHEDULER_HPP_

#include <iostream>
#include "Temperature.hpp"
#include "Light.hpp"
#include "Pression.hpp"
#include "Humidity.hpp"
#include "Server.hpp"

/**
* @class Scheduler
* @brief This class will define the frequency at which the data from the sensors will be retrieved
*to be transmitted to the server.
*/

/*
* @brief The default frequency of my Sleep
*/
enum{DEFAULT_FREQUENCY=5000} ; //< The time between two sensor measurements

class Scheduler {

  private:

	char m_entry; //< This variable will be useful to keep the choice of the user
	int  m_nbValue; //< The number of value that want the user

	Temperature m_objTemp ;
	Light m_objLight ;
	Humidity m_objHumidity ;
	Pression m_objPression ;

	Server m_serv ;

	short int m_light ; //< The sensor's data of the light
	short int m_humidity ; //< The sensor's data of the humidity
	short int m_pression ; //< The sensor's data of the pression
	short int m_temperature ; //< The sensor's data of the temperature

  public :

	/*
	 * @brief Default Constructor
	 *This function allow us to recover data from sensors and send it to the serveur every x second
	 *
	 */

	Scheduler();

	/*
	 * @brief Default destructor
	 */

	virtual ~Scheduler();

	/*
	 * @brief Constructor by recopy
	 * @param copyObject_p Object of the Sheduler Class
	 */

	Scheduler(const Scheduler& copyObject_p) ;

	/*
	 *@brief Affectation Operator
	 *@return this (type Scheduler) Self-reference symbol
	 *@param copyObject_p Object of the Scheduler class
	 */

	Scheduler & operator =(const Scheduler& copyObject_p);

};


#endif /* SCHEDULER_HPP_ */
