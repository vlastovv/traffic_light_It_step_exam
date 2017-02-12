#pragma once

#include<thread>
#include<map>	 

enum Color
{
	Off ,
	Green ,
	Yellow ,
	Red ,
	RedYellow ,
};
enum TLightType
{
	BigTlight ,
	SmallTLight ,
};		

void run_traffic_light (int id );
void set_traffic_light_color ( int id,Color color );
void stop_traffic_light (int id );

class TrafficLight
{
public:
	TrafficLight ( int id );
	void run ( );
	void fire_light ( );
	void set_color ( Color color );
	Color get_color ( );
	void stop ( );
private:
	TLightType m_size;
	Color m_color;
	bool m_stop = false;
	int m_id;		
};

extern std::map<int , TrafficLight*> Lights;
