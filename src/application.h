#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class application{
private:
	int id;												/* The id of the application */
	string name;										/* The name of the applicant */
	string surname;										/* The surname of the applicant */
	string destination;									/* The destination of the applicant */
	time_t leave_t;										/* The max time that applicant wants to leave */
	time_t arrive_t;									/* The max time that the applicant wants to be to his destination */
	char cla;											/* The class of the applicant's sit (A: A-Class, B: Economy Class ) */

public:
	/* The constractor of an application */
	application(int id_, string name_, string surname_, string destination_, time_t leave_t_, time_t arrive_t_, char cla_)
	:id(id_),name(name_),surname(surname_), destination(destination_), leave_t(leave_t_), arrive_t(arrive_t_), cla(cla_)
	{
		
	}
	bool matches(time_t , time_t , string , int );		/* A function that checks on an application
														   if the flight's details is correct to be on-board.
														   Returns true on maching, otherwise, false */
	bool is_luxury_class(){								/* A function that checks if the application is for a A-Class sit. */
		return (cla == 'A');
	}
	int get_id(){										/* Returns the id of the application */
		return id;
	}
	string get_name(){									/* Returns the name and the surname of the applicant, with a space between them */
		return name + " " + surname;
	}
	time_t arrived_by(){								/* Returns the time that the applicant want to be to his destination */

		return arrive_t;
	}
	time_t leave_by(){									/* Returns the time that the applicant want to leave */

			return leave_t;
		}
};

#endif /* APPLICATION_H_ */
