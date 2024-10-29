#include "Functionality.h"
using namespace std;

// Total and tax initialized globally 
double total = 0.0;
double tax = 0.0;
double subTotal = 0.0;


// Function for top and bottom of the menu.
void menuBorder(int menuWidth) {
    // This loop creates the styles that are needed for top and bottom menu border.
    for (int i = 0; i < menuWidth; i++) {
        if (i == 0 || i == menuWidth - 1) {
            cout << "|";
        }
        else {
            cout << "-";
        }
    }
    cout << endl;
}

// Function for menu display template.
void menuTemplate(Menu currentMenu, bool price) {
    // Clear the screen each time a new menu is loaded.
    system("cls");

    const int menuWidth = 35;
    menuBorder(menuWidth);

    if (price == true) {
        // This loop will style and place each menu item inside of the menu.
        for (int i = 0; i < currentMenu.getSize(); i++) {
            cout << "| " << i + 1 << " - " << currentMenu.getItem(i);

            /*This sets the space between item name and price 13
              is the amount of space needed for other output.*/
            int itemSpacing = menuWidth - (currentMenu.getItem(i).length() + 13);
            for (int i = 0; i < itemSpacing; i++) {
                cout << ".";
            }

            // Set the cout precision to 2 for 2 decimal places.
            cout.precision(2);

            // Fixed to set the number of places after the decimal, and set the field width to help with aligning values.
            cout << "$" << fixed << setw(5) << currentMenu.getPrice(i) << "|";
            cout << endl;
        }
    }
    else {
        // This loop will style and place each menu item inside of the menu.
        for (int i = 0; i < currentMenu.getSize(); i++) {
            cout << "| " << i + 1 << " - " << currentMenu.getItem(i);

            // This sets the space between item name and price
            int itemSpacing = menuWidth - (currentMenu.getItem(i).length() + 7);
            for (int i = 0; i < itemSpacing; i++) {
                cout << ".";
            }
            cout << "|" << endl;
        }
    }

    menuBorder(menuWidth);

    cout << currentMenu.getPrompt() << endl;
}

// Function for movie menu.
void menuTemplate(Movie currentMenu) {
    // Clear the screen each time a new menu is loaded.
    system("cls");

    const int menuWidth = 50;
    menuBorder(menuWidth);

    // This loop will style and place each menu item inside of the menu.
    for (int i = 0; i < currentMenu.getSize(); i++) {
        cout << "| " << i + 1 << " - " << currentMenu.getMovie(i);

        // This sets the space between movie name and genre
        int genreSpacing = menuWidth - (currentMenu.getMovie(i).length() + currentMenu.getGenre(i).length() + 11);
        for (int i = 0; i < genreSpacing; i++) {
            cout << ".";
        }
        cout << currentMenu.getGenre(i);

        // This sets the space between genre and rating.
        int ratingSpacing = menuWidth - ((genreSpacing + currentMenu.getGenre(i).length()) + currentMenu.getMovie(i).length() + currentMenu.getRating(i).length() + 7);
        for (int i = 0; i < ratingSpacing; i++) {
            cout << ".";
        }

        cout << currentMenu.getRating(i);

        cout << "|" << endl;
    }
    menuBorder(menuWidth);

    cout << currentMenu.getPrompt() << endl;
}

// Function to get the amount of a specific item the customer would like and return that value.
int amountToPurchase() {
    int amount;

    cout << "How many of this item would you like? ";
    cin >> amount;

    return amount;
}

// Function to reset total between menus.
void totalReset() {
    total = 0.0;
    tax = 0.0;
    subTotal = 0.0;
}

// Function to calculate and adjust total and tax.
void totalCalc(double itemPrice, int amount) {
    // 7% sales tax applied to each item.
    const double salesTax = 0.07;

    // Applies the sales tax to each item and adding those values to the total sales tax and total.
    total += ((itemPrice * salesTax) + itemPrice) * amount;
    subTotal += itemPrice * amount;
    tax += (itemPrice * salesTax) * amount;
}

// Function for concession menu final reciept.
void recieptFinal(Menu mainMenu, Menu candyMenu, Menu drinkMenu) {
    // Creat spacing between the items above and the current Cart.
    cout << endl << endl;

    int menuWidth = 35;
    menuBorder(menuWidth);

    // These 2 loops are used to create the header for the cart.
    for (int i = 0; i < 15; i++) {
        if (i == 0) {
            cout << "|";
        }
        else {
            cout << "-";
        }
    }
    cout << "Cart:";
    for (int i = 0; i < 15; i++) {
        if (i == 14) {
            cout << "|";
        }
        else {
            cout << "-";
        }
    }
    cout << endl;

    // Populates the cart with items the user has seleced.
    for (int i = 0; i < mainMenu.getSize(); i++) {
        if (mainMenu.getPurchased(i) > 0) {
            cout << "| " << mainMenu.getPurchased(i) << " x " << mainMenu.getItem(i);

            // This sets the space between item name and the end of the menu.
            int itemSpacing = menuWidth - (mainMenu.getItem(i).length() + to_string(mainMenu.getPurchased(i)).length() + 12);

            // Used to fill the empty space between item name and menu border.
            for (int i = 0; i < itemSpacing; i++) {
                cout << ".";
            }

            // Set the cout precision to 2 for 2 decimal places.
            cout.precision(2);

            // Fixed to set the number of places after the decimal, and set the field width to help with aligning values.
            cout << "$" << fixed << setw(5) << mainMenu.getPrice(i) << "|";
            cout << endl;

            // The else if to create a sub category for candy and drinks displaying which item from the submenu the customer selects.
            if (i == 1) {
                for (int i = 0; i < candyMenu.getSize(); i++) {
                    if (candyMenu.getPurchased(i) > 0) {
                        cout << "|\t" << candyMenu.getPurchased(i) << " x " << candyMenu.getItem(i);
                        int itemSpacing = menuWidth - (candyMenu.getItem(i).length() + to_string(candyMenu.getPurchased(i)).length() + 12);
                        for (int i = 0; i < itemSpacing; i++) {
                            cout << ".";
                        }
                        cout << "|" << endl;
                    }
                }
            }
            else if (i == 3) {
                for (int i = 0; i < drinkMenu.getSize(); i++) {
                    if (drinkMenu.getPurchased(i) > 0) {
                        cout << "|\t" << drinkMenu.getPurchased(i) << " x " << drinkMenu.getItem(i);
                        int itemSpacing = menuWidth - (drinkMenu.getItem(i).length() + to_string(drinkMenu.getPurchased(i)).length() + 12);
                        for (int i = 0; i < itemSpacing; i++) {
                            cout << ".";
                        }
                        cout << "|" << endl;
                    }
                }
            }
        }
    }
    cout << endl;

    cout << "Sales Tax:" << fixed << setw(6) << tax << endl << endl;
    cout << "Sub Total:" << fixed << setw(6) << subTotal << endl << endl;
    cout << "Total:" << fixed << setw(6) << total << endl << endl;
}

// Function for concessions menu running total.
void recieptUpdate(Menu mainMenu, Menu candyMenu, Menu drinkMenu) {
    // Create the rolling reciept.
    recieptFinal(mainMenu, candyMenu, drinkMenu);

    // Prompt the user to make another selection.
    cout << "You may make another selection or enter 0 to confirm and end transaction: ";
}

// Function for getting the users ticket choice, and adjusting available tickets and the value of purchased tickets.
void ticketChoice(Movie& movieMenu, Menu& ticketMenu, int availTickets[], int userIndex) {
    int ticketChoice;
    cin >> ticketChoice;

    while (ticketChoice != 0) {
        
        int ticketIndex = ticketChoice - 1;
        int amount = amountToPurchase();

        if (availTickets[userIndex] >= amount) {
            totalCalc(ticketMenu.getPrice(ticketIndex), amount);
            movieMenu.setPurchased(userIndex, amount);
            ticketMenu.setPurchased(ticketIndex, amount);
            availTickets[userIndex] -= amount;
        }
        else {
            cout << "There are not enough tickets ramining for " << movieMenu.getMovie(userIndex) << ". There are only " << availTickets[userIndex] << " tickets available." << endl;

            cout << endl << "Enter any number to be returned to the movie selection menu.";

            // Create a temp input to pause and let the user read that there were not enough tickets.
            int notEnough;

            cin >> notEnough;
            ticketChoice = 0;
            break;
        }

        // Prompt the user again.
        cout << "Make another ticket type selection or enter 0 to return to movie selection.";
        cin >> ticketChoice;
    }
}

// For the sub categories on the ticket reciept only called in this file.
void subMenu(Menu& ticketMenu, int menuWidth) {
    // Set the cout precision to 2 for 2 decimal places.
    cout.precision(2);

    // The else if to create a sub category for candy and drinks displaying which item from the submenu the customer selects.
    for (int i = 0; i < ticketMenu.getSize(); i++) {
        if (ticketMenu.getPurchased(i) > 0) {
            cout << "|\t" << ticketMenu.getPurchased(i) << " x " << ticketMenu.getItem(i);
            int itemSpacing = menuWidth - (ticketMenu.getItem(i).length() + to_string(ticketMenu.getPurchased(i)).length() + 18);
            for (int i = 0; i < itemSpacing; i++) {
                cout << ".";
            }
            cout << "$" << fixed << setw(5) << ticketMenu.getPrice(i);
            cout << "|" << endl;
        }
    }
}

// Function for ticketing menu running total.
void ticketUpdate(Menu& mov1Menu, Menu& mov2Menu, Menu& mov3Menu, Menu& mov4Menu, Menu& mov5Menu, Movie& movieMenu) {
    // Creat spacing between the items above and the current Cart.
    cout << endl << endl;

    int menuWidth = 50;
    menuBorder(menuWidth);
    
    // These 2 loops are used to create the header for the cart.
    for (int i = 0; i < 22; i++) {
        if (i == 0) {
            cout << "|";
        }
        else {
            cout << "-";
        }
    }
    cout << "Cart:";
    for (int i = 0; i < 23; i++) {
        if (i == 22) {
            cout << "|";
        }
        else {
            cout << "-";
        }
    }
    cout << endl;

    // Populates the cart with items the user has seleced.
    for (int i = 0; i < movieMenu.getSize(); i++) {
        if (movieMenu.getPurchased(i) > 0) {
            cout << "| " << movieMenu.getPurchased(i) << " x " << movieMenu.getMovie(i);

            // This sets the space between item name and the end of the menu.
            int itemSpacing = menuWidth - (movieMenu.getMovie(i).length() + to_string(movieMenu.getPurchased(i)).length() + 6);

            // Used to fill the empty space between item name and menu border.
            for (int i = 0; i < itemSpacing; i++) {
                cout << ".";
            }

            cout << "|" << endl;
            switch (i) {
            case 0: {
                subMenu(mov1Menu, menuWidth);
                break;
            }
            case 1: {
                subMenu(mov2Menu, menuWidth);
                break;
            }
            case 2: {
                subMenu(mov3Menu, menuWidth);
                break;
            }
            case 3: {
                subMenu(mov4Menu, menuWidth);
                break;
            }
            case 4: {
                subMenu(mov5Menu, menuWidth);
                break;
            }
            default: {
                // Inform the user that the input was invalid.
                cout << endl << "Invalid input the value entered is outside of possible menu selections." << endl;
            }
            }
            
        }
    }
    cout << "Sales Tax:" << fixed << setw(6) << tax << endl << endl;
    cout << "Sub Total:" << fixed << setw(6) << subTotal << endl << endl;
    cout << "Total:" << fixed << setw(6) << total << endl << endl;
}

// Function for ticketing menu final reciept.
void ticketFinal(Menu& mov1Menu, Menu& mov2Menu, Menu& mov3Menu, Menu& mov4Menu, Menu& mov5Menu, Movie& movieMenu) {
    system("cls");

    ticketUpdate(mov1Menu, mov2Menu, mov3Menu, mov4Menu, mov5Menu, movieMenu);

    // Create user input for confirmation and moving to concessions.
    int toConcessions;

    cout << endl << "This is your final reciept from the ticket purchases. Enter any number to confirm and move to concessions.";
    cin >> toConcessions;
}




