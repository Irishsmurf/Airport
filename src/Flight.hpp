#ifndef Flight_H
#define Flight_H

#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "Passenger.hpp"
class Seat;
using std::string;
using std::vector;
class Flight
{
	public:
		bool operator<(const Flight &f)const;
		Flight(string flightcode0);
		Flight();
		void getCode();
		void get();//Gets info from STD input
		void print();//prints Data
		void addPassenger(Passenger* pPoint , char seatType0, char passengerType);
		void cancelFlight();
		bool flightStatus;
		string flightCode;
		string departure;
		string destination;
		string returnPrint();
		string flightDate;
		string departTime;
		string arrivalTime;
		int capacity; //Maximum number of all seats combined, divide by three to get the array size
		vector <Seat> window;
		vector <Seat> middle;
		vector <Seat> aisle;	
		int economyCount;
		int seatsFilled;
};
#endif
