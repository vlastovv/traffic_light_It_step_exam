#pragma once

void run_traffic_light (int id );
void stop_traffic_light (int id );

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

class TrafficLight
{
public:
private:
	TLightType m_size;
	Color m_color;
public:
	void run ( );
	void stop ( );
};
