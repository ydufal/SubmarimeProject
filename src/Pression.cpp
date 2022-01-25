/*
* @author Dufale Yann
* @file Pression.cpp
* @date 01/10/2021
* @brief This class with the class Sensor allows us to generate data for the Pression
*/

#include "Pression.hpp"

Pression::Pression(){m_data = aleaGenVal(100,50);};//< return a value in the range 100-50 thanks to the function aleaGenval

//< We do that to have a first value between 50 and 100 and after we will change our range (in the getData)in order to be consistent

Pression::~Pression(){};

Pression::Pression(const Pression& copyObject_p){};

Pression& Pression::operator =(const Pression& egalObject_p){return *this;};

int Pression::getData()
{
	m_data = aleaGenVal(m_data + 2, m_data - 2) ; //< Assign a Random value in the range -2/+2 of the previous value in order to be consistent

			if (m_data < 50){

				m_data = aleaGenVal(50 + 4, 50); //< If the value is smaller than 50 we set the value between 50 and 54

				}else if (m_data > 100){

					m_data = aleaGenVal(100, 100-4); //< If the value is higher than 100 we set the value between 100 and 96

		/*This method allows us to not go to far in both way */
				}

	return m_data ;
}
