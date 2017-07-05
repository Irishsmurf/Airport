#ifndef Seat_H
#define Seat_H

class Passenger;
#include "Flight.hpp"
class Flight;

class Seat {
	public:
		Seat();
		Seat(Passenger* perp0, Flight* flight0, char type0);
		Passenger* perp;
		Flight* flight;
		void printFlight();
		char type;
};
#endif
