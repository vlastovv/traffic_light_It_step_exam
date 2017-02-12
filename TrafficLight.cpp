
#include"TrafficLight.h"

#include<map>

std::map<int,TrafficLight> Lights;

void run_traffic_light (int id )
{
	TrafficLight light;
	Lights.insert (std::pair<int,TrafficLight>(id,light) );
	Lights[id].run ( );
}
void stop_traffic_light (int id )
{
	Lights [ id ].stop ( );
}