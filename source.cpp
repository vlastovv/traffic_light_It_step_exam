
#include<iostream>	   
#include<thread>
#include<fstream>
#include<mutex>


//==========================================
class Config
{
public:
	Config* instance ( );
public:
	std::fstream& getStream ( );
	int m_roads;
};

////==========================================
////---------------header--------------
//void run_state_machine ( );
//void stop_state_machine ( );
//
//class StateMachine
//{		
//public:	 	
//	void run ( )
//	{
//	};
//	void stop ( )
//	{
//		m_stop = true;
//	}
//private:
//	bool m_stop = false;
//};
//
////-------------------cpp-------------
//StateMachine state_machine;
//std::mutex wm;
//void run_state_machine_thread ( )
//{
//	state_machine.run ( );
//}
//void stop_state_machine_thread ( )
//{
//	wm.lock ( );
//	state_machine.stop ( );
//	wm.unlock ( );
//}

#include"TrafficLight.h"
//===========================================
//enum Color
//{
//	Off,
//	Green,
//	Yellow,
//	Red,
//	RedYellow,
//};						 
//enum TLightType
//{
//	BigTlight,
//	SmallTLight,
//};
//
//class TrafficLight
//{
//public:
//private:		 
//	TLightType m_size;
//	Color m_color;
//public:
//	void run ( );
//};
//
//#include<vector>
//class TrafficLightManager
//{
//public:
//	std::vector<TrafficLight> m_lights;
//	std::vector<std::thread> m_light_threads;
//public:
//};
//===========================================
class Menu
{
public:
	void run ( ) 
	{
	};
};

#include"StateMachine.h"
//===========================================
class MainThread
{
public:
	MainThread ( )
	{				 
	}
	~MainThread ( ) { };
public:
	Menu m_menu;

	std::thread	m_state_machine_thread;
public:
	void run_main_thread ( )
	{
		m_state_machine_thread = std::thread ( run_state_machine_thread );	 

		m_menu.run ( );	

		stop_state_machine_thread ( );  

		m_state_machine_thread.join ( );
	}		   
};			 

void main ( )
{
	MainThread main_thread;		
	main_thread.run_main_thread ( );

}
