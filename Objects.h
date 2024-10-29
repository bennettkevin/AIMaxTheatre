// This file is the header file for objects.
// For implementation see "../Source Files/Objects.cpp"
#include <string>
using namespace std;



// Object for the different menu's.
class Menu {
public:
	// Constructors
	
	// No-Arg constructor
	Menu();

	// Menu without a price.
	Menu(string menuItems[], int menuSize, string menuPrompt, int amountPurchased[]);

	// Menu with a price.
	Menu(string menuItems[], int menuSize, string menuPrompt, int amountPurchased[], double menuPrice[]);

	// Returns the size.
	int getSize();

	// Returns the name of the specified item.
	string getItem(int itemIndex);

	// Returns the price of the specified item.
	double getPrice(int itemIndex);

	// Returns the prompt for this menu.
	string getPrompt();

	// Sets the number of a specific item was purchased.
	void setPurchased(int itemIndex, int amount);

	// Returns the number of a specific item that was purchased.
	int getPurchased(int itemIndex);

	// Privately declare obj. members.
private:

	// Size of the arrays for iteration.
	int size;

	// Array to hold items in the menu.
	string items[8];

	// Prompt for the user.
	string prompt;

	// Array to hold the number of items purchased for specified item.
	int purchased[8];

	// Array of item prices.
	double price[8];
};

// Object to hold movie information for the movies that can be selected.
class Movie {
public:
	// Constructors 
	Movie();

	// Movie with rating
	Movie(string movieTitles[], int movieSize, string moviePrompt, int amountPurchased[], string movieRating[], string movieGenre[]);

	// Returns the title of the movie at index.
	string getMovie(int movieIndex);

	// Returns the size.
	int getSize();

	// Returns the prompt
	string getPrompt();

	// Sets the number of tickets purchased for specified movie.
	void setPurchased(int movieIndex, int amount);

	// Returns the number of tickets purchased for specified movie.
	int getPurchased(int movieIndex);

	// Returns the rating of specified movie.
	string getRating(int movieIndex);

	// Returns the genre of specified movie.
	string getGenre(int movieIndex);

private:

	// Array of movies that can be viewed.
	string movie[8];

	// Size of the array's for iteration
	int size;

	// Prompt for the specific menu.
	string prompt;

	// The number of tickets for each movie that has been purchased.
	int purchased[8];

	// The rating of the movie.
	string rating[8];

	// The genre of the movie.
	string genre[8];
};