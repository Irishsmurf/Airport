#include "Seat.hpp"
using namespace std;

//Constructor for seat;
Seat::Seat(Passenger* perp0, Flight* flight0, char type0) {
  perp = perp0;
  flight = flight0;
  type = type0;
}
//Empty Constuctor
Seat::Seat() {
}
//Print the flight
void Seat::printFlight() {
  Flight f = *flight;
  f.print();
}
