#pragma once

#include<vector>
#include"TrafficLight.h"

void run_state_machine_thread ( );
void stop_state_machine_thread ( );

class StateMachine
{
public:
	void run ( );
	void stop ( );
private:
	bool m_stop = false;
};

