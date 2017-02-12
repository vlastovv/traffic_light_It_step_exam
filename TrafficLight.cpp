
#include"TrafficLight.h"	
 
#include"Config.h"

std::map<int,TrafficLight*> Lights;	  
std::map<int ,std::thread> Lights_thread;

void run_traffic_light (int id )
{
	Lights.insert ( std::pair<int , TrafficLight*> ( id ,new TrafficLight (id) ) );
	Lights_thread [ id ] = std::thread ( &TrafficLight::run , Lights [ id ] );
}
void set_traffic_light_color ( int id,Color color )
{
	Lights [ id ]->set_color (color );
}	
void stop_traffic_light ( int id )
{
	Lights [ id ]->stop ( );
	Lights_thread [ id ].join ( );
	Lights.erase ( id );
}

//-------------------------------------------------------------------------
TrafficLight::TrafficLight ( int id ) :m_id ( id )
{

}
void TrafficLight::run ( )
{
	for ( ;;)
	{
		if ( m_stop == true )
			break;
		fire_light ( );
	}
}
void TrafficLight::fire_light ( )
{
	//empty function for lightening Traffic Light
};
void TrafficLight::set_color ( Color color )
{
	m_color = color;
}
Color TrafficLight::get_color ( )
{
	return m_color;
}
void TrafficLight::stop ( )
{
	m_stop = true;
}