// This is the implementation file for TheatreStates.h header file.
#include "TheatreState.h"

// Function to build and use the concessions menu.
void concessionMenu() {
    totalReset();
    
    // Initialize the user input.
    int userSelection;

    // Menu size and item information for the main menu.
    const int mainSize = 5;
    string mainItems[mainSize] = { "Popcorn", "Candy", "Nachos", "Drink", "HotDog" };
    double mainPrice[mainSize] = { 10.95, 8.99, 7.95, 6.69, 1.99 };
    string mainPrompt = "Enter the number associated with the item you would like (Ex: Enter 1 for Popcorn.)";
    int mainPurchased[mainSize] = { 0, 0, 0, 0, 0 };

    // Menu size and item information for candy.
    const int candySize = 4;
    string candyItems[candySize] = { "Mike and Ike", "Jolly Ranchers", "Sour Patch Kids", "DOTS Gumdrops" };
    string candyPrompt = "Enter the number associated with the candy you would like. (0 to return without candy.)";
    int candyPurchased[candySize] = { 0, 0, 0, 0 };

    // Menu size and item information for the drinks.
    const int drinkSize = 6;
    string drinkItems[drinkSize] = { "Dr.Pepper", "Coke", "Mountain Dew", "Sprite", "Sunkist", "Brisk Iced Tea" };
    string drinkPrompt = "Enter the number associated with the drink you would like. (0 to return without a drink.)";
    int drinkPurchased[6] = { 0, 0, 0, 0, 0, 0 };

    // Instantiate the menu's 
    Menu mainMenu(mainItems, mainSize, mainPrompt, mainPurchased, mainPrice);
    Menu candyMenu(candyItems, candySize, candyPrompt, candyPurchased);
    Menu drinkMenu(drinkItems, drinkSize, drinkPrompt, drinkPurchased);

    // Initial greeting for the customer.
    cout << "Hello, welcome to the AIMax concessions stand please follow on screen instructions to make your concessions purchase." << endl;

    menuTemplate(mainMenu, true);

    // Get user input for item selection.
    cin >> userSelection;

    // Sentinel loop to allow continuous selections until the user is done.
    while (userSelection != 0) {

        // Creating a value for the index of the item the user selected (off by 1 from userSelection).
        int userIndex = userSelection - 1;

        // Switch for each user selection from the main menu.
        switch (userSelection) {
        case 1: {
            // Get the amount the user wants to purchase
            int amount = amountToPurchase();

            // Display the main menu again.
            menuTemplate(mainMenu, true);

            // Input validation before changing cart/total values.
            if (amount > 0) {
                // Calculate the new total
                totalCalc(mainMenu.getPrice(userIndex), amount);

                // Add the items to the cart.
                mainMenu.setPurchased(userIndex, amount);
            }
            else {
                cout << endl;
                cout << "The amount entered was either 0 or negative witch is invalid returned without adding to cart." << endl;
            }

            break;
        }
        case 2: {

            // Initializing a second input variable for submenu selection.
            int candySelection = 0;

            // Display the candy menu.
            menuTemplate(candyMenu, false);

            // Get the candy selection from the user.
            cin >> candySelection;

            // Get the amount to be purchased.
            int amount = amountToPurchase();

            // Create the user index for candy. (off by 1 from candySelection)
            int candyIndex = candySelection - 1;

            // Call the menu again.
            menuTemplate(mainMenu, true);

            // Input validation and allowing the user to leave if they do not want candy.
            if (candyIndex >= 0 && candyIndex < candyMenu.getSize() && amount > 0) {

                // Setting cart items needs to set candy in main items and the specific candy the customer wants.
                mainMenu.setPurchased(userIndex, amount);
                candyMenu.setPurchased(candyIndex, amount);

                // Calculate the new total.
                totalCalc(mainMenu.getPrice(userIndex), amount);
            }
            else if (candyIndex == -1) {
                cout << endl;
                cout << "Returned without adding candy." << endl;
            }
            else if (amount <= 0) {
                cout << endl;
                cout << "The amount entered was either 0 or negative witch is invalid returned without adding to cart." << endl;
            }
            else {
                cout << "Invalid selection returned without adding to the cart." << endl;
            }

            break;
        }
        case 3: {

            // Get the amount the user wants to purchase
            int amount = amountToPurchase();

            // Display the main menu again.
            menuTemplate(mainMenu, true);


            if (amount > 0) {
                // Calculate the new total
                totalCalc(mainMenu.getPrice(userIndex), amount);

                // Add the items to the cart.
                mainMenu.setPurchased(userIndex, amount);
            }
            else {
                cout << endl;
                cout << "The amount entered was either 0 or negative witch is invalid returned without adding to cart." << endl;
            }
            break;
        }
        case 4: {
            // drinkMenu(userIndex);
            int drinkSelection = 0;


            // Display the drink menu.
            menuTemplate(drinkMenu, false);

            // Get the drink selection from the user.
            cin >> drinkSelection;

            // Get the amount to be purchased.
            int amount = amountToPurchase();

            int drinkIndex = drinkSelection - 1;



            menuTemplate(mainMenu, true);

            // Add items to cart.
            if (drinkIndex >= 0 && drinkIndex < drinkMenu.getSize() && amount > 0) {
                mainMenu.setPurchased(userIndex, amount);
                drinkMenu.setPurchased(drinkIndex, amount);

                totalCalc(mainMenu.getPrice(userIndex), amount);
            }
            else if (drinkIndex == -1) {
                cout << endl;
                cout << "Returned without adding a drink." << endl;
            }
            else if (amount <= 0) {
                cout << endl;
                cout << "The amount entered was either 0 or negative witch is invalid returned without adding to cart." << endl;
            }
            else {
                cout << endl;
                cout << "Invalid selection returned without adding to the cart." << endl;
            }

            break;
        }
        case 5: {
            // Get the amount the user wants to purchase
            int amount = amountToPurchase();

            // Display the main menu again.
            menuTemplate(mainMenu, true);

            if (amount > 0) {
                // Calculate the new total
                totalCalc(mainMenu.getPrice(userIndex), amount);

                // Add the items to the cart.
                mainMenu.setPurchased(userIndex, amount);
            }
            else {
                cout << endl;
                cout << "The amount entered was either 0 or negative witch is invalid returned without adding to cart." << endl;
            }
            break;
        }
              // Default cause if user selects a value outside of the possible menu selections.
        default: {
            // Display the main menu again.
            menuTemplate(mainMenu, true);

            // Inform the user that the input was invalid.
            cout << endl << "Invalid input the value entered is outside of possible menu selections." << endl;
        }
        }

        // Present the cart items for the customer. 
        recieptUpdate(mainMenu, candyMenu, drinkMenu);

        cin >> userSelection;
    }

    // Clear the screen to present the reset and end the transaction.
    system("cls");

    // Display a final reciept for the customer.
    cout << "Thanks for getting your concessions here is your final reciept." << endl << endl;
    recieptFinal(mainMenu, candyMenu, drinkMenu);
    cout << "We hope you enjoy your movie!";
}

// Function to build and use the ticketing menu.
void ticketMenu(){
    

    // Initialize user input.
    int userSelection;

    // Create the data for movie menu object.
    const int movieSize = 5;
    string movieTitles[movieSize] = { "Attack of the Killer Tomatoes", "Rocky Horror Picture Show", "Pink Floyd - The Wall", "Monty Python and the Holy Grail", "Young Frankenstein" };
    int moviePurchased[movieSize] = { 0, 0, 0, 0, 0 };
    string movieRating[movieSize] = { "PG", "R", "R", "PG", "PG" };
    string movieGenre[movieSize] = { "com/hor", "com/mus", "dram/mus", "com", "com" };
    string moviePrompt = "Select a movie you would like to see, when done making selections you may press 0 to pay and move to concessions.";

    // Create the ticket array for how many tickets there are for each movie 0-30 inclusive.
    int availTickets[movieSize];
    srand(time(0));
    for (int i = 0; i < movieSize; i++) {
        availTickets[i] = rand() % 31;
    }

    // Create the movie menu.
    Movie movieMenu(movieTitles, movieSize, moviePrompt, moviePurchased, movieRating, movieGenre);

    // Create the data for the prices of tickets
    const int ticketSize = 4;
    string ticketItems[ticketSize] = { "Adult", "Child", "Senior", "Matinee" };
    int ticketPurchased[ticketSize] = { 0, 0, 0, 0 };
    double ticketPrice[ticketSize] = { 15.00, 10.00, 7.00, 5.00 };
    string ticketPrompt = "Please select the kind of ticket you would like to purchase to return without purchasing tickets for this movie enter 0.";

    // Create the ticket menu for each movie.
    Menu mov1Menu(ticketItems, ticketSize, ticketPrompt, ticketPurchased, ticketPrice);
    Menu mov2Menu(ticketItems, ticketSize, ticketPrompt, ticketPurchased, ticketPrice);
    Menu mov3Menu(ticketItems, ticketSize, ticketPrompt, ticketPurchased, ticketPrice);
    Menu mov4Menu(ticketItems, ticketSize, ticketPrompt, ticketPurchased, ticketPrice);
    Menu mov5Menu(ticketItems, ticketSize, ticketPrompt, ticketPurchased, ticketPrice);

    // Provide a greeting to the AiMax theatre.
    cout << "Hello, welcome to the AIMax theatre ticket booth please follow on screen instructions to make your ticket purchase." << endl;

    // Initial movie selection menu.
    menuTemplate(movieMenu);

    cin >> userSelection;
    
    // Sentinal loop for movie selections.
    while (userSelection != 0) {
        
        int userIndex = userSelection - 1;

        // Switch for movie selections 1-5 to the respective movie menu.
        switch (userSelection) {
            
        case 1: {

            menuTemplate(mov1Menu, true);
            
            ticketChoice(movieMenu, mov1Menu, availTickets, userIndex);
            break;
            }

        case 2: {

            menuTemplate(mov2Menu, true);

            ticketChoice(movieMenu, mov2Menu, availTickets, userIndex);
            break;
        }

        case 3: {

            menuTemplate(mov3Menu, true);

            ticketChoice(movieMenu, mov3Menu, availTickets, userIndex);
            break;
        }

        case 4: {

            menuTemplate(mov4Menu, true);

            ticketChoice(movieMenu, mov4Menu, availTickets, userIndex);
            break;
        }

        case 5: {

            menuTemplate(mov5Menu, true);

            ticketChoice(movieMenu, mov5Menu, availTickets, userIndex);
            break;
        }

        default: {
            // Inform the user that the input was invalid.
            cout << endl << "Invalid input the value entered is outside of possible menu selections." << endl;
        }
        }

        // Create the main move selection menu again and show the users current cart.
        menuTemplate(movieMenu);
        ticketUpdate(mov1Menu, mov2Menu, mov3Menu, mov4Menu, mov5Menu, movieMenu);
        // Prompt the user that they can select another movie.
        cout << "You may select another movie to purchase tickets for or use 0 to conclude selections and move to concessions.";
        cin >> userSelection;
        }
    // Display the final reciept for ticketing and allow the user to move to concessions.
    ticketFinal(mov1Menu, mov2Menu, mov3Menu, mov4Menu, mov5Menu, movieMenu);
}