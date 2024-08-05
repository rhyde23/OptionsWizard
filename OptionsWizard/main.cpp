//Import iostream
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Main function
int main()
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
        cout << "Enter a number to select one of the following pricing models" << endl;

        for (int i = 1; i <= models.size(); ++i) {
            cout << i << endl;
        }

        cout << ">>";

        cin >> model_choice;

        selected_model = models[model_choice-1];

        cout << selected_model << endl;
    }

    return 0;
}
