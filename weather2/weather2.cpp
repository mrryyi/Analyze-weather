#include "pch.h"

// Explanation from pch.h
// TimeOfDay	// Represents an amount of time or time of day.
// Date			// Represents a date. y m d.
// SliceOfData	// Represents a slice of weather data identified by PLACE and timeofday.
// Day			// Represents a day, having two vectors of SliceOfData (inside/outside).
// Timing		// Used to simplify timing algorithms.
// Manager		// The manager that contains the days.

/*

Structure: 
	[Manager]
	Has:
		Seasons
		Days
	Does:
		Reads		file
		Calculates	mold and averages of days
					( Or rather, in an iterating for loop, calls the
					  functions in the days that do so. )
					seasons
					
		Sorts		days
		Searches	for a day
		Prints		days

	Seasons are:
		Just a set of 3 members of
		manager, not a class.

	[Days]
	Has:
		A date
		slices of data
			> inside
			> outside
		Average temperatures
		Average humidities
		Max difference in temperature
	Does:
		Compare itself against another day.
		Average its values.
		Calculates mold risk index and time.

	[Slices of data]
	Has:
		A time of day
		A temperature
		A humidity
		A place
	Does:
		Give if it has mold risk.




	Why these data types?
		It came naturally to divide the information into
		days (bundled in a manager)
		data (bundled in a day)
		
		Because what is a central term in the requirements specification?
			Days.
		What's the primary data we're working with?
			Pieces of data contained within a day, separated by time of day.

		What do we want to sort and search?
			Days.

		What do we want to sort by?
			Things that are attributed to days, calculated by the pieces of data
			that is attributed to days.

		Therefore, a day has pieces of data, and saved results of calculations of
		those pieces of data.

		Since we don't need 
*/


int main()
{
	
	std::cout << "[1]  test\n[2]  real\n\nInput: ";

	int choice = getInteger(1, 2);

	std::string filename;

	switch (choice) {
	case 1:
		filename = "tempdata4test.csv";
		break;
	case 2:
		filename = "tempdata4.csv";
	}


	Manager manager(filename);


	/*
	
	Perform the calculations using slices of data.

	*/

	manager.averageTheValuesOfDays();
	manager.calculateMold();
	manager.calculateDooring();
	manager.calculateSeasons();
	
	/*
	
	Release the slices of data, as all we need for the program now is
	the information we got from them.

	*/

	manager.cutOffSlicesFromDays();

	// A main menu choicing.
	bool menuing = true;
	while (menuing) {

		// Gives instruction of what you can do.
		std::cout << std::endl;
		std::cout << "[1]  Sort days and show a list." << std::endl;
		std::cout << "[2]  Search day and get avg temp." << std::endl;
		std::cout << "[3]  Find autumn and winter start dates" << std::endl;
		std::cout << "[4]  Just print the days." << std::endl;
		std::cout << "[5]  Get door opening details." << std::endl;
		std::cout << "[6]  Exit." << std::endl;

		std::cout << std::endl;
		std::cout << "Input: ";
		choice = getInteger(1, 6);
		std::cout << std::endl;

		switch (choice) {
		case 1:
			// Sorts by chosen type and then displays.
			manager.sortMenuAndDisplay();
			break;
		case 2:
			// Searches day by input.
			manager.searchDay();
			break;
		case 3:
			// Prints the season start dates.
			manager.printSeasons();
			break;
		case 4:
			// Prints the days and some of the day's information.
			manager.printDays();
			break;
		case 5:
			// Prints the door calculation details.
			manager.printDoorStuff();
			break;
		case 6:
			menuing = false;
			break;
		default:
			menuing = false;
			break;
		}

		std::cout << std::endl;

	}
	manager.~Manager();
}