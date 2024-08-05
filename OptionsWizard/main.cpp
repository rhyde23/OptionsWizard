//Import iostream
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

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

    string selected_model;

    //main loop
    while (running) {

        //Menu
       

        try {
            cout << "Enter a number to select one of the following pricing models" << endl;

            for (int i = 1; i <= models.size(); ++i) {
                cout << i;
                cout << ": " + models[i - 1] << endl;
            }

            cout << ">> ";

            cin >> model_choice;

            // Check for input failure
            if (cin.fail()) {
                throw invalid_argument("Invalid input. Not an integer.");
            }

            // Clear the error state if input is valid
            cin.clear();
            cin.ignore(10000, '\n'); // Discard invalid input up to 10,000 characters

            // If we reach this point, the input is an integer

            if (model_choice <= models.size()) {
                selected_model = models[model_choice - 1];
                cout << selected_model << endl;
                break; // Exit the loop
            }
            else {
                cout << "Invalid input. Enter a number between 1 and ";
                cout << models.size() << endl;
                cout << "" << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << std::endl; // Display the error message
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }
    }

    return 0;
}
