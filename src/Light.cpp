/*
* @author Dufale Yann
* @file Light.cpp
* @date 29/09/2021
* @brief This class with the class Sensor allows us to generate data for the Light
*/

#include "Light.hpp"

Light::Light(){m_data = aleaGenVal(2);};//< return a value in the range 0-1 thanks to the function aleaGenval the second Version

Light::~Light(){};

Light::Light(const Light& copyObject_p){};

Light& Light::operator =(const Light& egalObject_p)
{
	return *this;
}

bool Light::getData()
{
	return m_data = aleaGenVal(2) ; //< return a value in the range 0-1 thanks to the function aleaGenval the second Version
}
