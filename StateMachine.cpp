
#include"StateMachine.h"  
#include<mutex>

StateMachine state_machine;
std::mutex wm;

void run_state_machine_thread ( )
{
	state_machine.run ( );
}
void stop_state_machine_thread ( )
{
	wm.lock ( );
	state_machine.stop ( );
	wm.unlock ( );
}