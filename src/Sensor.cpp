/*
* @author Dufale Yann
* @file Sensor.cpp
* @date 01/10/2021
* @brief This class allows us to generate data with our subclass
*/

#include "Sensor.hpp"


Sensor::Sensor(){};

Sensor::~Sensor(){};

Sensor::Sensor(const Sensor& copyObject_p) {};

Sensor& Sensor::operator =(const Sensor& copyObject_p){return *this;};

int Sensor::getData(){return 0;}; //< We just initialize the function

int Sensor:: aleaGenVal(const int& maxRange_p, const int& minRange_p)
{
	int position(0);

	position = rand () % maxRange_p + minRange_p ; //< Create a ramdom number between a range in paramater

	return position ;
}




