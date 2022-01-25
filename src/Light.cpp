/*
* @author Dufale Yann
* @file Light.cpp
* @date 29/09/2021
* @brief This class with the class Sensor allows us to generate data for the Light
*/


#include "Light.hpp"

Light::Light(){};

Light::~Light(){};

Light::Light(const Light& copyObject_p){};

Light& Light::operator =(const Light& copyObject_p){return *this;};

int Light::getData()
{
	return aleaGenVal(2,0) ; //< return a value in the range 0-1 thanks to the function aleaGenval
}
