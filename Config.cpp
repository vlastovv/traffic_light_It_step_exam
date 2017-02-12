
#include"Config.h"
#include"TrafficLight.h"

Config* Config::m_instance = nullptr;

void Config::output_thread_function ()
{
	for ( ;;)
	{
		if ( m_write_to_file == false )
		{
			continue;
		}
		if ( !Lights.size ( ) )
			return;
		std::ostream&  stream = Config::instance ( )->get_stream ( );
		stream.width ( 5 );
		stream << m_dt;
		for ( auto i = Lights.begin ( ); i != Lights.end ( ); i++ )
		{
			std::cout.width ( 12 );
			Color color = i->second->get_color ( );
			switch ( color )
			{
				case Color::Green:
					{
						stream << "Green";
					}
					break;
				case Color::Off:
					{
						stream << "Off";
					}
					break;
				case Color::Red:
					{
						stream << "Red";
					}
					break;
				case Color::RedYellow:
					{
						stream << "RedYellow";
					}
					break;
				case Color::Yellow:
					{
						stream << "Yellow";
					}
					break;
			}
		}
		stream << "\n";
		m_write_to_file = false;
	}
};	  

std::ostream& Config::get_stream ( )
{
	return std::cout;
}
void Config::write_lights_to_file ( int dt )
{	
	m_write_to_file = true;
	m_dt = dt;
}	 	   

Config::Config ( )
{
	m_file_thread = std::thread ( &Config::output_thread_function,this);
}	 


Config* Config::instance ( )
{
	if ( !m_instance )
	{
		m_instance = new Config;
	}
	
	return m_instance;
}

