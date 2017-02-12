
#include"StateMachine.h"  
#include"Config.h"

StateMachine state_machine;
//-------------------------------
void run_state_machine_thread ( )
{
	state_machine.run ( );
}
void stop_state_machine_thread ( )
{
	state_machine.stop ( );
}
//-------------------------------
void StateMachine::run ( )
{
	//start Traffic lights treads
	for ( int i = 0; i < 4; i++ )
	{
		run_traffic_light ( i );
	}
	for ( ;;)
	{
		if ( m_stop == true )
			break;
		//TODO: dt
		std::this_thread::sleep_for ( std::chrono::milliseconds ( 20 ) );
		for ( int i = 0; i < 4; i++ )
		{
			//TODO:	color
			set_traffic_light_color ( i , Color::RedYellow );
		}
		
		Config::instance()->write_lights_to_file ( 100);
	}
	//stop Traffic lights treads
	for ( int i = 0; i < 4; i++ )
	{
		stop_traffic_light ( i );
	}
};
void StateMachine::stop ( )
{
	m_stop = true;
}