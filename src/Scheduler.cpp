/*
* @author Dufale Yann
* @file Scheduler.cpp
* @date 01/10/2021
* @brief This class will define the frequency at which the data from the sensors will be retrieved
*to be transmitted to the server.
*/

#include "Scheduler.hpp"

/*
*@brief This definition allow us to define a time in the programm
*/

#if (_WIN32) || (_WIN64)
	#include <windows.h> //< if the user is on windows we include the library windows
#else
	#include <unistd.h> //< if the user is on MacOS or Linux we include the library unistd
#endif


Scheduler::Scheduler():m_entry('Z'), m_nbValue(0), m_light(0), m_humidity(0), m_pression(0), m_temperature(0) //< We initialize our attributs
{

	std::cout << "Hello welcome to the IOT submarine project! (If you want to see data from the submarine you are in the good place)\n" << std::endl ;

	std::cout<< "Press S to display the sensor's data or any others key to quit.\n" << std::endl ;

	std::cin >> m_entry ;	//< We saved the value given by the user in m_entry

	if(m_entry == 'S' || m_entry == 's')	//< We check If the user want to generate value to not ask the nbValue if the user said no
	{
		do{

		std::cout << "\nHow many value do you want? (between 1 and 100)" <<std::endl ;

		std::cin >> m_nbValue ;	//< We saved the Number of value given by the user in m_nbValue

		}while(m_nbValue<1 || m_nbValue>100 );	// we check that the value is in the range 1-100


		while(m_entry == 'S' || m_entry == 's') //< While the user want to generate new value
		{
			for(int i=0 ; i < m_nbValue ; i++)	//< we generate nbValue ask by the user
			{
				m_temperature = m_objTemp.getData() ;	//< We saved the Random value of the temperature thanks to getData
				m_humidity = m_objHumidity.getData() ;	//< We saved the Random value of the Humidity thanks to getData
				m_light = m_objLight.getData() ;		//< We saved the Random value of the Light thanks to getData
				m_pression = m_objPression.getData();	//< We saved the Random value of the Pression thanks to getData

 /*We can call gatData four times and do not call the same function thanks to our override of getData in the Class Sensor and thier subClass*/

				     //< We write the data in the file corresponding
				m_serv.fileWrite("log/Temperature.log",m_objTemp.getData(),'T');
				m_serv.fileWrite("log/Humidity.log",m_objHumidity.getData(),'H');
				m_serv.fileWrite("log/Light.log",m_objLight.getData(),'L');
				m_serv.fileWrite("log/Pression.log",m_objPression.getData(),'P');

				m_serv.consolWrite( m_light, m_humidity, m_pression, m_temperature) ;	//< We display the value with the method consolWrite



				Sleep(DEFAULT_FREQUENCY); //< Wait 5 second before printing another sensor's data
			}

			std::cout<< "Press S to display the sensor's data or any others key to quit." << std::endl ;

			std::cin >> m_entry ;	//< We saved the value given by the user in m_entry

				if(m_entry == 'S' || m_entry == 's') //< We check If the user want to generate value to not ask the nbValue if the user said no
				{
					do{

						std::cout << "How many value do you want? (between 1 and 100)" <<std::endl ;

						std::cin >> m_nbValue ;	//< We saved the Number of value given by the user in m_nbValue

						}while(m_nbValue<1 || m_nbValue>100 );	// we check that the value is in the range 1-100

				}
		}
	}


}


Scheduler::~Scheduler(){};

Scheduler::Scheduler(const Scheduler& copyObject_p): m_entry(copyObject_p.m_entry), m_nbValue(copyObject_p.m_nbValue), m_light(copyObject_p.m_light),
m_humidity(copyObject_p.m_humidity), m_pression(copyObject_p.m_pression), m_temperature(copyObject_p.m_temperature) //< copy our attributs
{

}

Scheduler& Scheduler::operator =(const Scheduler& copyObject_p)
{
	//< Dertermine our conditions
	this->m_entry = copyObject_p.m_entry ;
	this->m_nbValue = copyObject_p.m_nbValue ;
	this->m_light = copyObject_p.m_light ;
	this->m_humidity = copyObject_p.m_humidity;
	this->m_pression = copyObject_p.m_pression;
	this->m_temperature = copyObject_p.m_temperature ;

	return *this;
}











