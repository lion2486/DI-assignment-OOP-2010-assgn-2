#include "airport.h"

using namespace std;

int airport::flow_time(time_t flow){
		int s(0);
		current_time += flow;
		for(int i=0;i<term_num;i++){
			if(terminal[i] != NULL){
				if(terminal[i]->departs_at() <= current_time){
					cout << "Flight to " << terminal[i]->get_destination() << " departs now!" << endl;
					list<application> tmp = terminal[i]->get_bookings();
					cout << "With " << tmp.size() << " passengers" << endl;
					for(list<application>::iterator it=tmp.begin();it!=tmp.end(); ++it )
						cout << it->get_name() << endl;
					delete terminal[i];
					terminal[i] = NULL;
					s++;
				}
			}
		}
		for (list<application>::iterator ipt=li.begin();ipt!=li.end(); ipt++ ){
			if(ipt->leave_by() <= current_time){
				li.erase(ipt);
				failed_Applications ++;
				ipt=li.begin();
			}
		}
		for(int y=0;y<term_num;y++){
			if(terminal[y] != NULL)
				for (list<application>::iterator itt=li.begin();itt!=li.end(); itt++ )

					if(itt->matches( terminal[y]->departs_at(), terminal[y]->arrives_at(), terminal[y]->get_destination(), terminal[y]->get_available()))
						terminal[y]->add_passenger(*itt);
				}
		return s;
	}

void airport::cancel_flight(int i){
	if(terminal[i] != NULL){
		list<application> tmp = terminal[i]->get_bookings();
		for(list<application>::iterator it=tmp.begin();it!=tmp.end(); ++it )
			li.push_front(*it);
		delete terminal[i];
		terminal[i] = NULL;
	}
	return;
}
int airport::add_flight(string destination, time_t depart_t, time_t duration, int maxCapacityA, int maxCapacityB){
		for(int i=0;i<term_num;i++)
			if(terminal[i] == NULL){
				terminal[i] = new flight(destination, depart_t, duration, maxCapacityA, maxCapacityB);
				return i;
			}
		return -1;
	}
void airport::add_application(int id, string name, string surname, string destination, time_t leave_t, time_t arrive_t, char cla){
		application tmp(id, name, surname, destination, leave_t, arrive_t, cla);
		for(int i=0;i<term_num;i++){
			if(tmp.matches( terminal[i]->departs_at(), terminal[i]->arrives_at(), terminal[i]->get_destination(), terminal[i]->get_available()))
			{
				terminal[i]->add_passenger(tmp);
				return;
			}
		}
		li.push_back(tmp);
		return;
	}
void airport::cancel_application(int id){
	for(int i=0;i<term_num;i++){
		if(terminal[i] != NULL)
			terminal[i]->cansel_reservations(id);
	}
	for (list<application>::iterator iter=li.begin();iter!=li.end(); ++iter ){
		if(iter->get_id() == id)
			li.erase(iter);
	}
	return;
}
void airport::show_timetable(){
	flight *term[term_num];
	for(int i=0;i<term_num;i++)
		term[i]=terminal[i];
	flight * temp;
	for(int x=0; x<term_num; x++)
		for(int y=0; y<term_num-1; y++)
			if(term[y]->departs_at()>term[y+1]->departs_at())
			{
				temp = term[y+1];
				term[y+1] = term[y];
				term[y] = temp;
			}
	for(int i=0;i<term_num;i++)
		cout << "Flight to " << term[i]->get_destination() << " departs at: " << term[i]->departs_at() << endl;
	}

