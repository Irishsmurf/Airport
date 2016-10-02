#include "Passenger.hpp"

using namespace std;

Passenger::Passenger(string name0, string dob0) {
  name = name0;
  dob = dob0;
}

Passenger::Passenger(){}

bool isNumeric(string num) {
  istringstream in(num);
  double inpValue;
  if(in >> inpValue) {
    return true;
  }
  else
    return false;
}

void Passenger::get() {
  string firstName, lastName;
  cout << "Enter first name: ";
  cin >> firstName;
  cout << "Enter second name: ";
  cin >> lastName;
  name = firstName + " " + lastName;
  cout << "Enter phone number: ";
  cin >> phone;
  while(!isNumeric(phone)) {
    cout << "Not a valid number, please try again: ";
    cin >> phone;
  }
  cout << "Enter Date of Birth (E.g. 28/11/1990): ";
  cin >> dob;

  cout << endl;
}

void Passenger::print() {
  cout << name << " " << dob << endl;
}
void Passenger::onFlight(string fCode) {
  vector<string>::iterator i;
  cout << "Booked on " <<  bookedFlights.size() << " seats " << endl;
  for(i = bookedFlights.begin(); i != bookedFlights.end(); ++i) {
    string out = *i;
    out = out.substr(0, 4);
    if(out == fCode) {
      cout<< "The Passenger is on Flight " << fCode << endl;
    }
  }
  cout<< "The passenger is not on Flight " << fCode<<endl;
}
void Passenger::printFlightDetails() {
  cout << name << " is booked on the following flights:" << endl;
  vector<string>::iterator i;
  cout << "Booked on " <<  bookedFlights.size() << " seats " << endl;
  for(i = bookedFlights.begin(); i != bookedFlights.end(); ++i) {
    string out = *i;
    cout << out;
  }
  cout << "\n---------------------------------\n";
}

bool Passenger::operator<(const Passenger &b)const {
  return name.compare(b.name) < 0;
}
void Passenger::assignSeat(Seat* seat) {
  cout << "Adding Seat" << endl;
  Seat s = *seat;
  Flight f = *s.flight;
  bookedFlights.push_back(f.returnPrint());

}
