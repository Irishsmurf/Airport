#include "UI.hpp"

using namespace std;

//Adds a passenger to our database if not there already
//Then looks up flight in flight table
//Adds passenger to flight
void UI::addPassenger()
{
	cout << "\033[2J\033[1;1H";
	int command;
	//Ask information about passenger
	Passenger p;
	p.get();
	char seatType;
	char passengerType;
	cout << "What type of Passenger are you adding?\n1)Business\n2)Economy\n\n";
	cin >> command;
	switch(command)
	{
		case 1:
			passengerType = 'b';
			break;
		case 2:
			passengerType = 'e';
			break;
	}
	if(passengerType == 'b')
	{
		cout << "What seat would you like: \n1)Window\n2)Aisle\n\n";
		cin >> command;
		switch(command)
		{
			case 1:
				seatType = 'w';
				break;
			case 2:
				seatType = 'a';
				break;
			default:
				seatType = 'w';
		}
		cout << "How many bags are being checked in:\n1)Three or less\n2)Four or more\n";
		cin >> command;
		switch(command)
		{
			case 1:
			{
				cout << "No further charges for baggage.\n";
				break;
			}
			case 2:
			{
				cout << "Please enter the Exact number of bags: ";
				cin >> command;
				cout << "The passenger must pay a further €" << (command - 3)*25 << " in baggage charges.\n"; 
				break;
			}
		}
	}
	else
	{
		cout << "What seat would you like: \n1)Window\n2)Aisle\n3)Middle\n\n";
		cin >> command;
		switch(command)
		{
			case 1:
				seatType = 'w';
				break;
			case 2:
				seatType = 'a';
				break;
			case 3:
				seatType = 'm';
				break;
		}
		cout << "How many bags are being checked in:\n1)One \n2)Two or more\n";
		cin >> command;
		switch(command)
		{
			case 1:
			{
				cout << "No further charges for baggage.\n";
				break;
			}
			case 2:
			{
				cout << "Please enter the Exact number of bags: ";
				cin >> command;
				cout << "The passenger must pay a further €" << (command - 1)*25 << " in baggage charges.\n"; 
				break;
			}
		}
	}

	//Add to passenger table
	
	//Ask about flight information
	cout << "Enter flight code ( or enter \"list\" to see all flights ): ";
	string fCode;
	cin >> fCode;
	if(fCode == "list")
	{
		printAllFlights();
		cout << "Enter flight code: ";
		cin >> fCode;
	}
	Flight f(fCode);
	//Lookup flight in flight table
	set<Flight>::iterator pFlight = flightTable.find(f);
	if(pFlight == flightTable.end())
	{
		cout << "Flight not Found.\n "<< endl;
		return;	
	}
	//find flight with that flight code, if not there print error
	f = *pFlight;
//Add Passenger with a Pointer to a Passenger and a seat type
	f.addPassenger(&p, seatType, passengerType);
	passengerTable.insert(p); //place in the passenger table
	f.print();	//prints flight out
	flightTable.erase(pFlight);	//takes out of the set so we add the updated version
	flightTable.insert(f);
	cout << "Successfully added Passenger to ";
	if(passengerType == 'b')
	{
		cout << "a business class seat on flight "<<fCode<<". \n"<<endl;;
	}
	else
	{
		cout <<"an economy class seat on flight "<<fCode<<".\n"<<endl;
	}
}

//Looks up passenger in passenger table
//Asks for a flight code
//Checks if passenger is booked on a plane with that flight code
void UI::checkBooking()
{
	cout << "\033[2J\033[1;1H";
	//Ask for passenger details
	Passenger p;
	p.get();
	
	//Search if passenger is in passenger table
	//if he isn't print error message
	set<Passenger>::iterator pPassenger = passengerTable.find(p);
	if(pPassenger == passengerTable.end())
	{
		cout << "That person is not in our database" << endl << endl;
		return;
	}
	//Ask for Flight code
	cout << "Enter Flight Code: ";
	string fCode;
	cin >> fCode;
	Flight f(fCode);
	set<Flight>::iterator pFlight = flightTable.find(f);
	if(pFlight == flightTable.end())
	{
		cout << "That flight is not in out Database" << endl << endl;
		return;
	}
	p.onFlight(fCode);
	//Look up in flight table
	//If it's not there print error message
	cout << "\n----------------------------------\n";
	//search through all the passenger's bookings to see if one of them points to the flight
	//Print yes or no
}

void UI::displayPassengerDetails()
{
	cout << "\033[2J\033[1;1H";
	//Ask for passenger details
	Passenger p;
	p.get();
	
	//Search if passenger is in passenger table
	//if he isn't print error message
	set<Passenger>::iterator pPassenger = passengerTable.find(p);
	if(pPassenger == passengerTable.end())
	{
		cout << "That person is not in our database" << endl << endl;
		return;
	}
	cout << "\n----------------------------------\n";
	Passenger pass = *pPassenger;
	pass.printFlightDetails();
	
	//Print details of all flight passenger is on
	//Have a special case for the passenger has no flights booked
	
}

void UI::cancelBooking()
{
	cout << "\033[2J\033[1;1H";
	
	//Ask information about passenger
	Passenger p;
	p.get();
	
	cout << "\033[2J\033[1;1H";
	//Search if passenger is in passenger table
	//if he isn't print error message
	set<Passenger>::iterator pPassenger = passengerTable.find(p);
	if(pPassenger == passengerTable.end())
	{
		cout << "That person is not in our database" << endl << endl;
		return;
	}
	p = *pPassenger;
	p.print();
	//Ask for Flight code
	//Look up in flight table
	//If it's not there print an error message
	//remove pointers between passenger and seat
	cout << "\n----------------------------------\n";
}

void UI::addFlight()
{
	cout << "\033[2J\033[1;1H";
	//Ask for Flight details
	//Create flight using those details

	//Add to flight table
	Flight f;
	f.get();
	flightTable.insert(f);
	cout << "\033[2J\033[1;1H";
	cout << "Successfully added to the Flight Table:\n";
	f.print();
	cout << "\n----------------------------------\n";
}

void UI::cancelFlight()
{
	string fCode;
	cout << "\033[2J\033[1;1H";
	Flight f;
	f.getCode();
	set<Flight>::iterator pFlight = flightTable.find(f);
	if(pFlight == flightTable.end())
	{
		cout << "That flight is not in out Database" << endl << endl;
		return;
	}
	Flight copy = *pFlight;
	copy.cancelFlight();
	flightTable.erase(pFlight);
	flightTable.insert(copy);

	printAllFlights();
	cout << "\n----------------------------------\n";
	//Ask for Flight code
	//Create flight using those details
	//Search for flight in flight tables
	//If it's not there print error
	//Otherwise remove it from the flight table
	//Cancel all bookings with that flight
}

void UI::lookupFlight()
{
	cout << "\033[2J\033[1;1H";
	string fCode;
	cout << "Flight Data Lookup.\n\n";
	//Ask for flight code
	Flight f;
	f.getCode();
	set<Flight>::iterator pFlight = flightTable.find(f);
	if(pFlight == flightTable.end())
	{
		cout << "That Flight does not exist within our Database\n\n";
		return;
	}
	f = *pFlight;
	f.print();
	cout << "\n----------------------------------\n";
	//Lookup in table
	//if it's not there print error
	//Otherwise print the details of the flight
}

void UI::printAllPassengers()
{
	cout << "There are " <<passengerTable.size() << " passengers:" << endl;
	set<Passenger>::iterator i;
	for(i = passengerTable.begin(); i != passengerTable.end(); ++i)
		cout << i->name << endl;
	cout << "\n----------------------------------\n";
}

void UI::printAllFlights()
{
	Flight f;
	cout<< "There are "<<flightTable.size() << " flights:"<< endl;
	if(flightTable.size() == 0)
	{
		cout << "\n";
		return;
	}

	set<Flight>::iterator i;
	for(i = flightTable.begin(); i != flightTable.end(); ++i)
	{
		f = *i;
		f.print();
	}
	cout << "\n----------------------------------\n";
}
