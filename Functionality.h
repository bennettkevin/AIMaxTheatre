// This file is the header file for functionality in the menus.
// For implementation see "../Source Files/Functionality.cpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Objects.h"



// Function for top and bottom of the menu.
void menuBorder(int menuWidth);

// Function for menu display template.
void menuTemplate(Menu currentMenu, bool price);

// Function for the movie menu.
void menuTemplate(Movie currentMenu);

// Function to get the amount of a specific item the customer would like and return that value.
int amountToPurchase();

// Function to reset total between menus.
void totalReset();

// Function to calculate and adjust total and tax.
void totalCalc(double itemPrice, int amount);

// Function for concession menu final reciept.
void recieptFinal(Menu mainMenu, Menu candyMenu, Menu drinkMenu);

// Function for concessions menu running total.
void recieptUpdate(Menu mainMenu, Menu candyMenu, Menu drinkMenu);

// Function for getting the users ticket choice, and adjusting available tickets and the value of purchased tickets. 
void ticketChoice(Movie& movieMenu, Menu& ticketMenu, int availTickets[], int userIndex);

// Function for ticketing menu running total.
void ticketUpdate(Menu& mov1Menu, Menu& mov2Menu, Menu& mov3Menu, Menu& mov4Menu, Menu& mov5Menu, Movie& movieMenu);

// Function for ticketing menu final reciept.
void ticketFinal(Menu& mov1Menu, Menu& mov2Menu, Menu& mov3Menu, Menu& mov4Menu, Menu& mov5Menu, Movie& movieMenu);