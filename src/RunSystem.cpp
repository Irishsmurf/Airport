#include "lib/UI.hpp"

using namespace std;

int main()
{
  system("clear");
  cout << "Welcome to our reservation system\n\n";
  int command;
  UI ui;
  while (true)
  {
    cout << "Enter command\n";
    cout << "1) Add Passenger\n2) Check if passenger is booked\n3) Display passenger booking details\n";
    cout << "4) Cancel Reservation\n5) Add flight\n6) Cancel Flight\n";
    cout << "7) Look up flight data\n8) Display Flights\n9) Display Passengers\n0) Exit\n";
    cin >> command;
    switch(command) {
      case 1:
        ui.addPassenger();
        break;

      case 2:
        ui.checkBooking();
        break;

      case 3:
        ui.displayPassengerDetails();
        break;

      case 4:
        ui.cancelBooking();
        break;

      case 5:
        ui.addFlight();
        break;

      case 6:
        ui.cancelFlight();
        break;

      case 7:
        ui.lookupFlight();
        break;

      case 8:
        system("clear");
        ui.printAllFlights();
        break;

      case 9:
        system("clear");
        ui.printAllPassengers();
        break;
      case 0:
        system("clear");
        cout << "Goodbye!\n\n";
        return 0;
      default:
        system("clear");
        cout << "Not a valid command!\n\n";
    }
  }
  return 0;
}
