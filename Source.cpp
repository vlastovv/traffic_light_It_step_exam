
#include<iostream>	   
#include<thread>	

#include"StateMachine.h"
#include"Menu.h"


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