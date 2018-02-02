#ifndef FLIGHT_H_
#define FLIGHT_H_
#include <iostream>
#include <ctime>
#include "application.h"
#include <string>
#include <list>

using namespace std;

class flight{
private:
	string destination;					/* The destination of the flight */
	time_t depart_t;					/* The time that the flight departs */
	time_t duration;					/* The total duration of the flight */
	int maxCapacity_A;					/* The MAX Capacity of A-class sits */
	int maxCapacity_B;					/* The MAX Capacity of Economy Class sits */
	int Capacity_A;						/* The current on-board passengers in A-Class */
	int Capacity_B;						/* The current on-board passengers in Economy Class */
	int Capacity;						/* The tota current on-board passengers */
	list<application> bookings;			/* A list of the booking sits */
public:
	/* The Constractor of the flight object */
	flight(string destination_, time_t depart_t_, time_t duration_, int maxCapacityA_, int maxCapacityB_)
	:destination(destination_), depart_t(depart_t_), duration(duration_), maxCapacity_A(maxCapacityA_), maxCapacity_B(maxCapacityB_), Capacity_A(0), Capacity_B(0), Capacity(0)
	{

	}
	bool add_passenger(application );	/* A function that adds a passenger in a flight. Returns true on success, false on failure */
	bool cansel_reservations(int );		/* A function that deletes all reservations of an id given. Returns true on success, false on failure */
	time_t departs_at(void){			/* Returns the time that the flight will depart */
		return depart_t;
	}
	time_t arrives_at(void){			/* Returns the time that the flight will arrive to the destination */
		return (depart_t+duration);
	}
	string get_destination(void){		/* Returns a string with the destinatios of the booking. */
		return destination;
	}
	int get_available(char cl = 'C' );	/* Returns the available for the class given (A: A-Class, B-Economy Class) or the total without class */
	list<application> get_bookings(){	/* Returms a list with the total reserves of the flight */
		return bookings;
	}
};

#endif /* FLIGHT_H_ */
