#pragma once

#include<vector>

void run_state_machine_thread ( );
void stop_state_machine_thread ( );

class StateMachine
{
public:
	void run ( )
	{
	};
	void stop ( )
	{
		m_stop = true;
	}
private:
	bool m_stop = false;

	std::vector<TrafficLight> m_lights;
	
};

