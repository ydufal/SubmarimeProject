/*
* @author Dufale Yann
* @file Temperature.cpp
* @date 01/10/2021
* @brief This class with the class Sensor allows us to generate data for the Temperature
*/

#include "Temperature.hpp"


Temperature::Temperature(){m_data=aleaGenVal(25,10);}; //< return a value in the range 25-10 thanks to the function aleaGenval
//< We do that to have a first value between 10 and 25 and after we will change our range (in the getData)in order to be consistent

Temperature:: ~Temperature(){};

Temperature::Temperature(const Temperature& secondObject_p){};

Temperature& Temperature::operator=(const Temperature& egalObject_p)
{
	return *this ;
}

float Temperature::getData()
{
	m_data = aleaGenVal(m_data + 1, m_data - 1) ; //< Assign a Random value in the range -1/+1 of the previous value in order to be consistent

	if (m_data < 10){

		m_data = aleaGenVal(10 + 2, 10); //< If the value is smaller than 10 we set the value between 10 and 12

		}else if (m_data > 25){

			m_data = aleaGenVal(25, 25-2); //< If the value is higher than 25 we set the value between 25 and 23

/*This method allows us to not go to far in both way */

		}

	return m_data ;
}




