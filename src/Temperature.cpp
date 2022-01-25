/*
* @author Dufale Yann
* @file Temperature.cpp
* @date 01/10/2021
* @brief This class with the class Sensor allows us to generate data for the Temperature
*/

#include "Temperature.hpp"


Temperature::Temperature(){};

Temperature:: ~Temperature(){};

Temperature::Temperature(const Temperature& secondObject_p){};

Temperature& Temperature::operator=(const Temperature& copyObject_p){return *this ;};

int Temperature::getData()
{
	return aleaGenVal( 15 ,10) ; //< return a value in the range 10-25 thanks to the function aleaGenval
}




