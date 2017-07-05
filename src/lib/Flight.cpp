#include "Flight.hpp"
using namespace std;


Flight::Flight(){
  //Empty constructor
}

Flight::Flight(string flightcode0):flightCode(flightcode0) {
  //Empty
}


bool Flight::operator<(const Flight &f)const {
  return flightCode.compare(f.flightCode) < 0;
}

void Flight::getCode() {
  cout << "\033[2J\033[1;1H";
  cout << "Enter the flight code: ";
  cin >> flightCode;
}


void Flight::get() {
  int command;
  stringstream ss;
  flightStatus = true;
  cout << "\033[2J\033[1;1H"; //Clears the screen; Instead of using the resource heavy System call.
                //This is the ANSI escape character sequence which clears
                //the screen and then returns the cursor back to column zero of row zero
  srand( time(NULL) ); //Random Seed
  int random = rand() % 1000; //Random number between 0 - 999
  cout << "Enter the Departure city: ";
  cin >> departure;
  cout << "Enter the Flight Destination: ";
  cin >> destination;
  char s = departure[0]; //Get first letter
  ss << s;
  s = destination[0]; //get second letter
  ss << s;
  ss << random;
  ss >> flightCode; //put the flight code together
  cout << "Enter Flight Size:\n1)120 (Short Haul Flight)\n2)300 (Long Haul Flight)\n";
  cin >> command;
  switch(command) {
    case 1:
      capacity = 120;
      break;
    case 2:
      capacity = 300;
      break;
  }
  cout << "Enter Departure Time: ";
  cin >> departTime;
  cout << "Enter Flight Arrival Time: ";
  cin >> arrivalTime;
  cout << "Enter Flight Date: ";
  cin >> flightDate;
  seatsFilled = 0;
  economyCount = 0;
  cout << "\n";
}



string Flight::returnPrint() {
  string out = flightCode;
  out.append(" --- ");
  out.append(departure);
  out.append(" -> ");
  out.append(destination);
  if(!flightStatus) {
    out.append(" [CANCELLED \n");
  }
  else
    out.append("\n");
  return out;
}
void Flight::print() {
  cout << flightCode << " --- " << departure
    << " ("<<departTime<<") -> " << destination << " ("<<arrivalTime<<")";
  if(capacity == 120) {
    cout << " ("<< seatsFilled << "/" << capacity << ") (Short Haul Flight) ";
  }
  else {
    cout << " ("<< seatsFilled << "/" << capacity << ") (Long Haul Flight) ";
  }
  if(!flightStatus) {
    cout << " [CANCELLED] \n";
  }
  else {
    cout << "\n";
  }
}

void Flight::addPassenger(Passenger* pPoint, char seatType, char passengerType){
  cout << "Adding Passenger \n";
  //Checking to see what type of passenger.
  if(passengerType == 'b') {
    if(window.size() < capacity/3 && seatType == 'w') {
      //Assign the Business Passenger a seat
      Flight* fPoint = this;
      Seat perp = Seat(pPoint, fPoint, 'w');
      pPoint->assignSeat(&perp);
      window.push_back(perp);
      seatsFilled++;
    }
    else if(aisle.size() < capacity/3 && seatType == 'a') {
      Flight* fPoint = this;
      Seat perp = Seat(pPoint, fPoint, 'a');
      pPoint->assignSeat(&perp);
      //assign buisness passenger a aisle seat
      aisle.push_back(perp);
      seatsFilled++;
    }
    else {
      //Throw an error, No Seats available
      cout << "Sorry No seats available onboard this flight\n";
    }
  }
  else if(passengerType == 'e') {
    double eAllowed = capacity*0.85;
    if(eAllowed > economyCount) {
      //Not a business passenger so assign a middle seat
      if(window.size() < capacity/3 && seatType == 'w') {
        //Assign Window Seat
        Flight* fPoint = this;
        Seat perp = Seat(pPoint, fPoint, 'w');
        pPoint->assignSeat(&perp);
        window.push_back(perp);
        economyCount++;
        seatsFilled++;
      }
      else if(middle.size() < capacity/3 && seatType == 'm' ) {
        //Assign middle seat
        Flight* fPoint = this;
        Seat perp = Seat(pPoint, fPoint, 'm');
        pPoint->assignSeat(&perp);
        middle.push_back(perp);
        economyCount++;
        seatsFilled++;
      }
      else if(aisle.size() < capacity/3 && seatType == 'a') {
        //Assign aisle seat
        Flight* fPoint = this;
        Seat perp = Seat(pPoint, fPoint, 'a');
        pPoint->assignSeat(&perp);
        aisle.push_back(perp);
        economyCount++;
        seatsFilled++;
      }
      else {
        //Throw an error, no seats available
        cout << "Sorry No seats available onboard this flight\n";
      }
    }
    else
      cout << "Sorry No seats available onboard this flight\n";
  }
}

void Flight::cancelFlight() {
  flightStatus = false;
  print();
}
