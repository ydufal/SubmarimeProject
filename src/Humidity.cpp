/*
* @author Dufale Yann
* @file Humidity.cpp
* @date 01/10/2021
* @brief This class with the class Sensor allows us to generate data for the Humidity
*/

#include "Humidity.hpp"

Humidity::Humidity(){ m_data = aleaGenVal(45,20);}; //< return a value in the range 45-20 thanks to the function aleaGenval
//< We do that to have a first value between 45 and 20 and after we will change our range (in the getData)in order to be consistent

Humidity::~Humidity(){};

Humidity::Humidity(const Humidity& copyObject_p){};

Humidity& Humidity::operator =(const Humidity& egalObject_p){return *this;};

float Humidity::getData()
{
	m_data = aleaGenVal(m_data + 2, m_data - 2) ; //< Assign a Ramdom value in the range -2/+2 of the previous value in order to be consistent

				if (m_data < 20){

					m_data = aleaGenVal(20 + 3, 20); //< If the value is smaller than 20 we set the value between 20 and 23

					}else if (m_data > 45){

						m_data = aleaGenVal(45, 45-3) ; //< If the value is higer than 45 we set the value between 45 and 42

			/*This method allows us to not go to far in both way */
					}

		return m_data ;
}




