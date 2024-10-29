#include "Objects.h"

// This function is used to transfer one array to a new array.
void arrayTransfer(int amountPurchased[], int newArray[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		newArray[i] = amountPurchased[i];
	}
}

// Overloaded to fit string array's.
void arrayTransfer(string amountPurchased[], string newArray[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		newArray[i] = amountPurchased[i];
	}
}

// Overloaded to fit double arrays
void arrayTransfer(double amountPurchased[], double newArray[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		newArray[i] = amountPurchased[i];
	}
}

// No arg menu constructor.
Menu::Menu() {
	// No-arg creation.
}

// Menu without a price.
Menu::Menu(string menuItems[], int menuSize, string menuPrompt, int amountPurchased[]) {
	size = menuSize;
	prompt = menuPrompt;

	// Move each array to the specified member.
	arrayTransfer(amountPurchased, purchased, menuSize);
	arrayTransfer(menuItems, items, menuSize);
	
}

// Menu with a price.
Menu::Menu(string menuItems[], int menuSize, string menuPrompt, int amountPurchased[], double menuPrice[]) {
	size = menuSize;
	prompt = menuPrompt;

	// Move each array to the specified member.
	arrayTransfer(amountPurchased, purchased, menuSize);
	arrayTransfer(menuItems, items, menuSize);
	arrayTransfer(menuPrice, price, menuSize);
}


// Returns the prompt for this menu.
string Menu::getPrompt() {
	return prompt;
}

// Returns the price of the specified item.
double Menu::getPrice(int itemIndex) {
	return price[itemIndex];
}

// Returns the name of the specified item.
string Menu::getItem(int itemIndex) {
	return items[itemIndex];
}

// Returns the size.
int Menu::getSize() {
	return size;
}

// Returns the number of a specific item that was purchased.
int Menu::getPurchased(int itemIndex) {
	return purchased[itemIndex];
}

// Sets the number of a specific item was purchased.
void Menu::setPurchased(int itemIndex, int amount) {
	purchased[itemIndex] += amount;
}

// No arg movie constructor.
Movie::Movie() {
	// No-arg creation.
}

// Movie constructor.
Movie::Movie(string movieTitles[], int movieSize, string moviePrompt, int amountPurchased[], string movieRating[], string movieGenre[]) {
	size = movieSize;
	prompt = moviePrompt;

	// Move each array to the specified member.
	arrayTransfer(movieTitles, movie, movieSize);
	arrayTransfer(amountPurchased, purchased, movieSize);
	arrayTransfer(movieRating, rating, movieSize);
	arrayTransfer(movieGenre, genre, movieSize);
}

// Returns the title of the movie at index.
string Movie::getMovie(int movieIndex) {
	return movie[movieIndex];
}

// Returns the size.
int Movie::getSize() {
	return size;
}

// Returns the prompt
string Movie::getPrompt() {
	return prompt;
}

// Sets the number of tickets purchased for specified movie.
void Movie::setPurchased(int movieIndex, int amount) {
	purchased[movieIndex] += amount;
}

// Returns the number of tickets purchased for specified movie.
int Movie::getPurchased(int movieIndex) {
	return purchased[movieIndex];
}

// Returns the rating of specified movie.
string Movie::getRating(int movieIndex) {
	return rating[movieIndex];
}

// Returns the genre of specified movie.
string Movie::getGenre(int movieIndex) {
	return genre[movieIndex];
}