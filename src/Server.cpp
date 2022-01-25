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

Server& Server::operator =(const Server& copyObject_p){return *this;};

void Server::consolWrite( short int& light_p, short int& humidity_p, short int& pression_p, short int& temperature_p) const
{
   std::cout << "-------------------------------------------------------------" << std::endl ;
   std::cout << "|Pression| Pressure on the submarine (bar): " << pression_p << std::endl ; //< Display the Pression value
   std::cout << "|Humidity| indoor humidity (%): " << humidity_p << std::endl ; //< Display the Humidity value
   std::cout << "|Light| true(1) or false(0): " << light_p << std::endl ; //< Display the light value
   std::cout << "|Temperature| indoor temperature (Celcius): " << temperature_p << std::endl ; //< Display the Tempearture value
   std::cout << "-------------------------------------------------------------" << std::endl ;

}

void Server::fileWrite(const std::string file_p,const int& dataCaptor_p, const char type)
{

	std::ofstream myStream(file_p.c_str(), std::ios::app); // we create our stream in order to write in our file


  if(myStream) // we check that our stream work well
  {

	  time(&now) ;
	  m_date = ctime(&now);
	  myStream << m_date << std::endl ;
	  myStream << dataCaptor_p  ; // we write our data in our log

	  switch(type){ //< according to the type of data we write the good type associate

	  case 'H' :
		  myStream << "%" << std::endl ;
		  break ;
	  case 'T':
		  myStream << "°C" << std::endl ;
	  	  break ;
	  case 'L':
		  myStream << " On(1)/Off(0)" << std::endl ;
	  	  break ;
	  case 'P':
		  myStream << " Bar" << std::endl ;
	  	  break ;
	  default:
	  	  break ;
	  }


	  myStream << "----------------------------------" << std::endl ;
  }
  else
  {
	 std::cerr << "Eror : Impossible to open one/some files" << std::endl; // if not we signal a eror
  }
}







