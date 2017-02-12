#pragma once

#include<iostream>	
#include<thread>

class Config
{
public:
	Config ( );
	static Config* instance ( );
	std::ostream& get_stream ( );		
	void write_lights_to_file ( int dt );	
private:
	void output_thread_function (  );
	static Config* m_instance;	   
	std::thread m_file_thread;	   	
	int m_roads;
	bool m_write_to_file = false;
	int m_dt = 0;
};
