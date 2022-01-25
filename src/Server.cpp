/*
* @author Dufale Yann
* @file Server.cpp
* @date 29/09/2021
* @brief This class receives data and allows us to watch or store the data
*/

#include "Server.hpp"

Server::Server(){time(&now);m_date=ctime(&now);};

Server::~Server(){};

Server::Server(const Server& copyObject_p){}; // @suppress("Class members should be properly initialized")

Server& Server::operator =(const Server& egalObject_p){return *this;};








