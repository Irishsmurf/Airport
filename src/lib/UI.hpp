#ifndef UI_H
#define UI_H

#include <iostream>
#include <stdlib.h>
#include <set>

#include "Seat.hpp"
#include "Passenger.hpp"
#include "Flight.hpp"

using std::set;

class UI {	
  public:
  void addPassenger();
  void checkBooking();
  void displayPassengerDetails();
  void cancelBooking();
  void addFlight();
  void cancelFlight();
  void lookupFlight();
  void printAllPassengers();
  void printAllFlights();

  //private:
  //Set of Flights
  set <Flight> flightTable;
  //Ser of Passengers
  set <Passenger> passengerTable;
};
#endif
