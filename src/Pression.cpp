/*
* @author Dufale Yann
* @file Pression.cpp
* @date 01/10/2021
* @brief This class with the class Sensor allows us to generate data for the Pression
*/

#include "Pression.hpp"

Pression::Pression(){};

Pression::~Pression(){};

Pression::Pression(const Pression& copyObject_p){};

Pression& Pression::operator =(const Pression& copyObject_p){return *this;};

int Pression::getData()
{
	return aleaGenVal( 60 , 70) ; //< return a value in the range 70-130 thanks to the function aleaGenval
}
