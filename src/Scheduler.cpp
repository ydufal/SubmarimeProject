/*
* @author Dufale Yann
* @file Scheduler.cpp
* @date 01/10/2021
* @brief This class will define the frequency at which the data from the sensors will be retrieved
*to be transmitted to the server.
*/

#include "Scheduler.hpp"

Scheduler::Scheduler():m_totalTime(100000), m_choiceConsole('c'),m_choiceFile('f'), m_light(0), m_humidity(0), m_pression(0), m_temperature(0)
{
	bool isNumber = true ;
	int j(0) ;
	std::string str;
	//< use to verify the value given by the user

	m_temperature = m_objTemp.getData() ;	//< We saved a Random value of the temperature thanks to getData
	m_humidity = m_objHumidity.getData() ;	//< We saved a Random value of the Humidity thanks to getData
	m_pression = m_objPression.getData();   //< We saved a Random value of the Pression thanks to getData
	m_light = m_objLight.getData() ;		//< We saved a Random value of the Light thanks to getData

	std::cout << "Hello welcome to the IOT submarine project! (If you want to see data from the submarine you are in the good place)\n" << std::endl ;
	std::cout << "====================================================================================================================="<<std::endl ;
	std::cout << "=                                                                                                                   ="<<std::endl ;
	std::cout << "=                                Hello welcome to the IOT submarine project!                                        ="<<std::endl ;
	std::cout << "=                            This program is use to recover data from 4 Sensors                                     ="<<std::endl ;
	std::cout << "=                                And to put it into some files corresponding                                        ="<<std::endl ;
	std::cout << "=                                       Please enjoy it and Have fun                                                ="<<std::endl ;
	std::cout << "=                                                                                                                   ="<<std::endl ;
	std::cout << "====================================================================================================================="<<std::endl ;

	std::cout<< "\nFirst You have to know that our submarine recover : " << std::endl ;
	std::cout<< "||Light Data|| : every 12.5 sec" <<std::endl ;
	std::cout<< "||Temperature Data|| : every 10 sec" <<std::endl ;
	std::cout<< "||Pressure Data|| : every 5 sec" <<std::endl ;
	std::cout<< "||Humidity Data|| : every 7.5 sec" <<std::endl ;


	do{
		do{
		isNumber = true ; //< We reinitializes IsNumber
		if(j!=0){std::cout<< "\n         The value is not correct" ;};//< We only want to not display that the first time of the loop
		std::cout<< "\n         Please choose for How long the program will work (time in s) higher than 10 : " ;
		std::cin >> str ; //< The value of the User

				for(unsigned int i(0); i< str.size();++i)	//< we go through the whole string
				{
				if(!isdigit(str[i])) //< check that each things write is a digit
					{
						isNumber = false ;
						break ; //< we break the for because it is not necessary to stay
						j++ ; //< increments the variable j to say we pass by there
					}
				}
			}while(!isNumber); //< While that Isnumber is not true

		std::istringstream iss(str); //Transition string to int
		iss >> m_totalTime; //< We recover the value
		j++ ; //< increments the variable j to say we pass by there
		}while(m_totalTime < 10) ;



	std::cout <<"\n\nDo you want to write yours values in your console (y/n) : " ;
	std::cin >> m_choiceConsole ;

	while( m_choiceConsole !='y' && m_choiceConsole !='n')
	{
		std::cout <<"\nYou have chosen a wrong value please choose a correct value : " ;
		std::cin >> m_choiceConsole ;
	}

	std::cout <<"\nDo you want to write yours values in your File (y/n) : " ;
	std::cin >> m_choiceFile ;

		while( m_choiceFile !='y' && m_choiceFile !='n')
		{
			std::cout <<"\nYou have chosen a wrong value please choose a correct value : " ;
			std::cin >> m_choiceFile ;
		}

	std::cout << "\nThe data is begin loaded\n " << std::endl;

	//< We launch at the same time our four Sensors with different time of record thanks to our thread and the function run
	std::thread T_temperature(&Scheduler::run<float,Temperature>, this, "log/Temperature.log", std::ref(m_temperature), std::ref(m_objTemp),('T'), (10));
	std::thread T_humidity(&Scheduler::run<float,Humidity>, this, "log/Humidity.log", std::ref(m_humidity), std::ref(m_objHumidity),('H'), (7.5));
	std::thread T_light(&Scheduler::run<bool,Light>, this, "log/Light.log", std::ref(m_light), std::ref(m_objLight),('L'), (12.5));
	std::thread T_pression(&Scheduler::run<int,Pression>, this, "log/Pression.log", std::ref(m_pression), std::ref(m_objPression),('P'), (5));


		try {


		}catch (...){
			T_temperature.join();	//< Join them otherwise only the first thread are going to be launched
			T_humidity.join();
			T_light.join();
			T_pression.join();

			throw;
		}

		T_temperature.join();	//< It's the same thing
		T_humidity.join() ;
		T_light.join();
		T_pression.join();

		std::cout << "\nThank you to use our program see you soon"  ;
}


Scheduler::~Scheduler(){};

Scheduler::Scheduler(const Scheduler& copyObject_p)
{
	//< copy our attributes
		this->m_totalTime = copyObject_p.m_totalTime ;
		this->m_light = copyObject_p.m_light ;
		this->m_humidity = copyObject_p.m_humidity;
		this->m_pression = copyObject_p.m_pression;
		this->m_temperature = copyObject_p.m_temperature ;
		this->m_choiceConsole = copyObject_p.m_choiceConsole ;
		this->m_choiceFile = copyObject_p.m_choiceFile ;

}

Scheduler& Scheduler::operator=(const Scheduler& egalObject_p)
{
	//< Determine our conditions
	this->m_totalTime = egalObject_p.m_totalTime ;
	this->m_light = egalObject_p.m_light ;
	this->m_humidity = egalObject_p.m_humidity;
	this->m_pression = egalObject_p.m_pression;
	this->m_temperature = egalObject_p.m_temperature ;
	this->m_choiceConsole = egalObject_p.m_choiceConsole ;
	this->m_choiceFile = egalObject_p.m_choiceFile ;


	return *this;
}











