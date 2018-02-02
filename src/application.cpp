#include "application.h"

using namespace std;

bool application::matches(time_t departs_at, time_t arrives_at, string get_destination, int get_available){
		if(departs_at >= leave_t && arrives_at <= arrive_t && get_destination == destination && get_available >0 )
			return true;
		return false;
	}
