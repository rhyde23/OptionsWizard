//Standard libraries
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

//Include header files for pricing model classes
#include "BlackScholes.h"

//Include SFML Graphics library
#include "SFML/Graphics.hpp"

using namespace std;

//Define the "windowWidth" constant
const int windowWidth = 800;

//Define the "windowHeight" constant
const int windowHeight = 800;

//Main function
int main(int argc, char* argv[])
{

    /*
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
    */
    
    //Create window object
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "OptionsWizard");

    //Create event object for event handling such as window close
    sf::Event e;

    //Create Arial font object for title text
    sf::Font arialFont;

    //Load the arial font file 
    arialFont.loadFromFile("arial.ttf");

    //Create a Text oject for the title text using the arial font
    sf::Text title("OptionsWizard", arialFont, 30);

    //Get the width of the text block
    int textWidth = title.getLocalBounds().width;

    //Set the position of the text at the top middle of the screen
    title.setPosition((windowWidth-textWidth)/2, 10);

    //Set the title text color to black
    title.setFillColor(sf::Color::Black);

    //Window loop
    while (window.isOpen()) {

        //Event handling loop
        while (window.pollEvent(e)) {

            //If the user is trying to close the window
            if (e.type == sf::Event::Closed) {

                //Close the window
                window.close();
            }
        }

        //Set the background of the window to Red
        window.clear(sf::Color::Red);

        //Display the title
        window.draw(title);

        //Update the window display for this frame
        window.display();

    }

    return 0;
}
