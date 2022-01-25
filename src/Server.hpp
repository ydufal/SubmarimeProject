/*
* @author Dufale Yann
* @file Server.hpp
* @date 29/09/2021
* @brief This class receives data and allows us to watch or store the data in our logs
*/

//
// Define guards
#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

/**
 * @class Server
 * @brief This class receives data and allows us to watch or store the data in our logs
 */

class Server {

  private :

	/*Attributes to show the date of the measure in our logs*/
	time_t now;
	char *m_date;

  public :

	/*
	 * @brief Default Constructor
	 */

	Server();

	/*
     * @brief Destroyer of the Class
	 */

	virtual ~Server();

	/*
	 * @brief Constructor by recopy
	 * @param copyObject_p Object of the Server Class
	 */

	Server(const Server& copyObject_p);


	/*
	*@brief Affectation Operator
	*@return this (type Server) Self-reference symbol
	*@param egalObject_p Object of the Server class
	*/

	 Server & operator =(const Server& egalObject_p);

	/**
	 * @brief This class allows us to display the data of the sensors
	 * @param data_p (type T) Data of one sensor
	 * @param type_p char use to know which type of data that we receive
	 * @param choice_p char type a variable that allows us to know if the user want to display the data or not in the console
	 *
	 */

	template <typename T>
	void consolWrite(const T& data_p,const char type_p, const char choice_p)
	{
		if(choice_p == 'y') //< If the User want to display the Data
		{
			switch(type_p){ //< according to the type of data we want to display the data of one specific Sensor

				  case 'H' :
					   std::cout << "\n********************************************\n" << "|Humidity| indoor humidity (%): " << data_p << std::endl ; //< Display the Humidity value
					  break ;
				  case 'T':
					   std::cout << "\n********************************************\n" << "|Temperature| indoor temperature (Celcius): " << data_p << std::endl ; //< Display the Temperature value
				  	  break ;
				  case 'L':
					   std::cout << "\n********************************************\n" << "|Light| On(1)/off(0) : " << data_p << std::endl ; //< Display the light value
				  	  break ;
				  case 'P':
					   std::cout << "\n********************************************\n" << "|Pression| Pressure on the submarine (bar): " << data_p << std::endl ; //< Display the pressure value
				  	  break ;
				  default:
				  	  break ;
				  }
		}

		}


	/**
	 * @brief This class store the captors data in a file log
	 * @param dataCaptor_p type T(several type) The Data of one sensor
	 * @param file_p string type The file log according to the captor data
	 * @param choice_p char type This variable allow us to know If the user want to register the data in the logs
	 * @param type_p Char type ( To know which type of data that we receive )
	 */
	template <typename T>
	void fileWrite(const std::string file_p, const T& dataCaptor_p, const char type_p, const char choice_p)
	{
		if(choice_p == 'y') //< If the User want to store the data
		{

			std::ofstream myStream(file_p.c_str(), std::ios::app); // we create our stream in order to write in our file


			if(myStream) // we check that our stream work well
			{

				time(&now) ;
				m_date = ctime(&now); //< We recover the data and time of the computer in order to put it in the log
				myStream << m_date << std::endl ; //< we write the date and time in our log
				myStream << dataCaptor_p  ; // we write our data in our log

				switch(type_p){ //< according to the type of data we write the good type associate

				case 'H' :
					myStream << "%" << std::endl ;
					break ;
				case 'T':
					myStream << "°C" << std::endl ;
					break ;
				case 'L':
					myStream << " On(1)/Off(0)" << std::endl ;
					break ;
				case 'P':
					myStream << " Bar" << std::endl ;
					break ;
				default:
					break ;
				}


				myStream << "----------------------------------" << std::endl ;
			}
			else
			{
				std::cerr << "Eror : Impossible to open one file" << std::endl; // if not we signal a error
			}
		}
	}
};

#endif /* SERVER_HPP_ */
