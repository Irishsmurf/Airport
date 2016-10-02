#ifndef Passenger_H
#define Passenger_H

#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include "Seat.hpp"

class Seat;
class Flight;

using std::string;
using std::vector;

class Passenger {
  public:
  Passenger(string name, string dob);
  Passenger();
  void assignSeat(Seat* pSeat);
  void onFlight(string fCode);
  void print();
  void get();
  bool operator<(const Passenger &b)const;
  void printFlightDetails();
  string name;
  string dob;
  string phone;
  string email;
  vector<string> bookedFlights;
};
#endif
