//Standard libraries
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

//Include header files for pricing model classes
#include "BlackScholes.h"

using namespace std;

//Main function
int main(int argc, char* argv[])
{

    //Options Wizard title!
    cout << "Options Wizard" << endl;

    //"running" set to true if app is open
    bool running = true;

    //"models" is a vector of strings that contains the names of the choices of pricing models
    vector<string> models{"Black-Scholes Model"};

    //"model_choice" is integer that will be determined by cin user input for choice of pricing model
    int model_choice;

    //Main loop
    while (running) {

        //Menu
        //Try to take valid user input
        try {

            //Enter message
            cout << "Enter a number to select one of the following pricing models" << endl;

            //For loop to print out all options
            for (int i = 1; i <= models.size(); ++i) {
                
                //Print the number assigned to this option
                cout << i;
                
                //Print out the model name
                cout << ": " + models[i - 1] << endl;
            }

            //Get user input
            cout << "\n>> ";
            cin >> model_choice;
            cout << "" << endl;

            //Check for input failure (not valid integer)
            if (cin.fail()) {
                throw invalid_argument("Invalid input. Not an integer.");
            }

            //Clear the error state if input is valid
            cin.clear();

            // Discard invalid input
            cin.ignore(10000, '\n');

            //Check if the model choice integer is less than or equal to the amount of options available
            if (model_choice <= models.size()) {

                if (model_choice == 1) {
                    cout << "You have selected Black-Scholes" << endl;

                    BlackScholes bs_obj;
                    bs_obj.displayInputs();

                }

                break;
            }

            //If the model choice integer is too large
            else {

                //Display error message
                cout << "Invalid input. Enter a number between 1 and ";
                cout << models.size() << endl;
                cout << "" << endl;
            }
        }

        //If the input is not a valid integer
        catch (const invalid_argument& e) {

            //Display error message
            cout << e.what() << endl;
            cin.clear(); 
            cin.ignore(10000, '\n');
        }
    }

    return 0;
}
