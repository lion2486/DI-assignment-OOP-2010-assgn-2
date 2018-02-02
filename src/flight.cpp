#include "flight.h"

using namespace std;


bool flight::add_passenger(application apl){
		if(apl.is_luxury_class()){
			if(Capacity_A < maxCapacity_A){
				Capacity_A ++;
				bookings.push_back(apl);
				Capacity ++;
				return true;
			}
		}
		else{
			if(Capacity_B < maxCapacity_B){
				Capacity_B ++;
				bookings.push_back(apl);
				Capacity ++;
				return true;
			}
		}
		return false;
	}
bool flight::cansel_reservations(int id){
		bool flag = false;
		if(Capacity_A+Capacity_B <= 0)
			return flag;
		for(list<application>::iterator it=bookings.begin();it!=bookings.end(); ++it ){
			if(it->get_id() == id)
			{
				if(it->is_luxury_class())
					Capacity_A --;
				else
					Capacity_B --;
				Capacity --;
				bookings.erase(it);
				flag = true;
			}
		}
		return flag;
	}
int flight::get_available(char cl ){
		if(cl == 'A')
			return maxCapacity_A - Capacity_A;
		if(cl == 'B')
			return maxCapacity_B - Capacity_B;
		return (maxCapacity_A - Capacity_A)+ ( maxCapacity_B - Capacity_B);
	}
