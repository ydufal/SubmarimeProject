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


#include "Temperature.hpp"
#include "Light.hpp"
#include "Pression.hpp"
#include "Humidity.hpp"
#include "Server.hpp"

#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <sstream>


/**
* @class Scheduler
* @brief This class will define the frequency at which the data from the sensors will be retrieved
*to be transmitted to the server.
*/


class Scheduler {

  private:


	int m_totalTime ; //< This value is used to know for how long the user want to run the program
	char m_choiceConsole ; //< Attribute used to choose to display or ont his value in the console
	char m_choiceFile ; //<Attribute used to choose to register his data in the files
	Temperature m_objTemp ;
	Light m_objLight ;
	Humidity m_objHumidity ;
	Pression m_objPression ;

	Server m_serv ;
	/*Initialize our Objects*/

	bool m_light ; //< The sensor's data of the light
	float m_humidity ; //< The sensor's data of the humidity
	int m_pression ; //< The sensor's data of the pression
	float m_temperature ; //< The sensor's data of the temperature

	std::mutex mu;//<attribute in order to use concurrency

  public :

	/*
	 * @brief Default Constructor
	 *This function allow us to recover data from sensors and send it to the server every x second
	 *
	 */

	Scheduler();

	/*
	 * @brief Default destroyer
	 */

	virtual ~Scheduler();

	/*
	 * @brief Constructor by recopy
	 * @param copyObject_p Object of the Scheduler Class
	 */

	Scheduler(const Scheduler& copyObject_p) ;

	/*
	 *@brief Affectation Operator
	 *@return this (type Scheduler) Self-reference symbol
	 *@param egalObject_p Object of the Scheduler class
	 */

	Scheduler & operator =(const Scheduler& egalObject_p);

	/*
	 *@brief We use this functions for our thread in order to generate data depending on each sensor
	 *@param (string type)The file where we want to register our data
	 *@param (T1 type) The type of the sensor data (int,float,bool)
	 *@param (T2 type) The Object sensor
	 *@param (char type) The type of data to determine the Sensor data
	 *@param (int type) The frequency of recovering data
	 */
	template<typename T1, typename T2> //< function template because of the type of Data and Object
		 void run(const std::string file_p ,T1& sensorData_p, T2& object_p, char type_p, int frequency_p)
		 {
				for(int i=0 ; i <(m_totalTime/frequency_p); i++) //< We run the thread until the time ask by the user (To do that we divided the total time by the frequency)
			 	 	{
					auto now = std::chrono::system_clock::now(); //< We recover the time of our computer
					std::this_thread::sleep_until(now +std::chrono::seconds(frequency_p));
		 			///< wait a certain time in order to recover the data with a frequency

			 			sensorData_p = object_p.getData(); //< we recover the data thanks to the function getData
			 			std::lock_guard<std::mutex> guard(mu); //< This line only allows us to organize the access of the console (concurrency)
						m_serv.consolWrite( sensorData_p, type_p, m_choiceConsole); //< To write the data in our console according to the user choice
			 			m_serv.fileWrite(file_p, sensorData_p, type_p , m_choiceFile); //<To write the data in our Log according to the user choice

			 		}
		 }
};


#endif /* SCHEDULER_HPP_ */
