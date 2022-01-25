/*
* @author Dufale Yann
* @file Server.hpp
* @date 29/09/2021
* @brief This class receives data and allows us to watch or store the data
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
 * @brief This class receives data and allows us to watch or store the data
 */

class Server {

  private :

	/*Attributs to show the date of the mesure in our files*/
	time_t now;
	char *m_date;

  public :

	/*
	 * @brief Default Constructor
	 */

	Server();

	/*
     * @brief Desctructor of the Class
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
	*@param copyObject_p Object of the Server class
	*/

	 Server & operator =(const Server& copyObject_p);

	/**
	 * @brief This class allows us watch to the data of the sensors
	 * @param light_p (type int) The Light Data
	 * @param humidity_p (type int) The Humidity Data
	 * @param pression_p (type int) The Pression Data
	 * @param temperature_p (type int) The Temperature Data
	 */


	void consolWrite( short int& light_p, short int& humidity_p, short int& pression_p, short int& temperature_p) const;

	/**
	 * @brief This class store the captors data in a file logs
	 * @param p_dataCaptor type int
	 * @param p_file type string
	 */

	void fileWrite(const std::string p_file, const int& p_dataCaptor, const char type);


};

#endif /* SERVER_HPP_ */
