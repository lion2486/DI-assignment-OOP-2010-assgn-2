#ifndef AIRPORT_H_
#define AIRPORT_H_
#include <iostream>
#include <ctime>
#include <list>
#include "application.h"
#include "flight.h"
#include <string>

using namespace std;

class airport{
private:
	int failed_Applications;							/* The number of the failed application */
	int term_num ;										/* The number of the terminal stations of the airport */
	list<application> li;								/* A list with all the waiting applications */
	time_t current_time;								/* The current time at the airport */
    flight **terminal;									/* A pointer to handle an array */
public:
	airport(time_t ti, int num)							/* The constractor of the airport-class */
	:failed_Applications(0),term_num(num), current_time(ti)
	{
        terminal = new flight*[num];					/* An array for the flight in terminals */
		for(int i=0;i<term_num;i++)						/* initialise of an empy-pointer */
			terminal[i] = NULL;
	}
	time_t get_time(){									/* Returns the current time of the airport */
		return current_time;
	}
	/* A function that adds an application to the airport */
	void add_application(int , string , string , string , time_t , time_t , char );
	void cancel_application(int );						/* A function that removes all application with an id */
	int add_flight(string , time_t , time_t , int , int );/* Adds a flight to an empty terminal */
	void cancel_flight(int );							/* Removes a flight from a terminal */
	void show_timetable();								/* Show all flights in terminals by time-sorting */
	void show_people_waiting(){							/* Shows all waiting applicants */
		for(list<application>::iterator it=li.begin();it!=li.end(); ++it )
			cout << it->get_name() << endl;
		return;
	}
	int flow_time(time_t );								/* Flows the airport's time */
	int get_avail_termilals(){							/* Returns the number of available terminals */
		int j(0);
		for(int i=0;i<term_num;i++)
			if(terminal[i] == NULL)
				j++;
	return j;
	}
	int get_failed(){ return failed_Applications; }
};
#endif /* AIRPORT_H_ */
