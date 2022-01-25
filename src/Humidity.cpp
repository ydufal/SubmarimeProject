/*
* @author Dufale Yann
* @file Humidity.cpp
* @date 01/10/2021
* @brief This class with the class Sensor allows us to generate data for the Humidity
*/

#include "Humidity.hpp"

Humidity::Humidity(){};

Humidity::~Humidity(){};

Humidity::Humidity(const Humidity& copyObject_p){};

Humidity& Humidity::operator =(const Humidity& copyObject_p){return *this;};

int Humidity::getData()
{
	return aleaGenVal(25,20) ; //< return a value in the range 45-20 thanks to the function aleaGenval
}




