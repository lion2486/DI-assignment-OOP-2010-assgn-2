#include <iostream>
#include <ctime>
#include "airport.h"
#include "flight.h"
#include "application.h"
#include <fstream>


using namespace std;

int main(int argc, char *argv[]){
    airport air(0, 10);
    ifstream in("flights.txt");
    ifstream inf("applications.txt");
    char choice;
    while (!in.eof() && air.get_avail_termilals() > 0) {
        string dest;
        time_t a, b;
        in >> dest >> a >> b ;
        if (!in.good() || !air.get_avail_termilals())
        	break;
        air.add_flight(dest, a, b, 20, 60);
    }
	while (!inf.eof()) {
		int id;
		char cla;
		string name, surname, destination;
		time_t leave_t, arrive_t;
		inf >> id >> name >> surname >> leave_t >> arrive_t >> destination >> cla;
		if (!inf.good())
			break;
		air.add_application(id, name, surname, destination, leave_t, arrive_t, cla);
	}
    if(argc == 1){
		air.show_timetable();
		air.show_people_waiting();
		cout << "There was " << air.get_failed() << " failed applications" << endl;
		air.flow_time(200);
		while (!in.eof() && air.get_avail_termilals() > 0) {
			string dest;
			time_t a, b;
			in >> dest >> a >> b ;
			if (!in.good() || !air.get_avail_termilals())
				break;
			air.add_flight(dest, a, b, 20, 60);
		}
		air.show_timetable();
		cout << "Waiting:" << endl;
		air.show_people_waiting();
		cout << "There was " << air.get_failed() << " failed applications" << endl;
    }
    else if(argc == 2 && argv[1][0] == 'a'){
		cout << "Choices:"
				"\nn: Current Time\n"
				"t: show_timetable\n"
				"w: show_people_waiting\n"
				"c: cancel_flight\n"
				"f: flow_time\n"
				"s: Failed applications' statistics\n"
				"x: Exit" << endl;
		cin >> choice;
		while(choice != 'x'){
			switch(choice){
			int id;
			time_t flow;
				case 't':	air.show_timetable();
							break;
				case 'w':	cout << "Waiting:" << endl;
							air.show_people_waiting();
							break;
				case 'c':	cout << "Give the id to delete" << endl;
							cin >> id;
							air.cancel_flight(id);
							break;
				case 'f':	cout << "Give time to flow" << endl;
							cin >> flow;
							air.flow_time(flow);
							break;
				case 'n':	cout << "Current time is: " << air.get_time() << endl;
							break;
				case 's':	cout << "There was " << air.get_failed() << " failed applications" << endl;
							break;
			}
			 while (!in.eof() && air.get_avail_termilals() > 0) {
					string dest;
					time_t a, b;
					in >> dest >> a >> b ;
					if (!in.good() || !air.get_avail_termilals())
						break;
					air.add_flight(dest, a, b, 20, 60);
				}
			 cout << "Choices:"
						"\nn: Current Time\n"
						"t: show_timetable\n"
						"w: show_people_waiting\n"
						"c: cancel_flight\n"
						"f: flow_time\n"
						"s: Failed applications' statistics\n"
						"x: Exit" << endl;
			 cin >> choice;
		}
	}
    return 0;
}

