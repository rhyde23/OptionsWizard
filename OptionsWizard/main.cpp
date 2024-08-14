//Incliude strings
#include <string>

//Include vectors
#include <vector>

//Include iostream for cout for testing purposes
#include <iostream>

//Include header files for pricing model classes
#include "BlackScholes.h"
#include "Binomial.h"
#include "MonteCarlo.h"
#include "Bachelier.h"

//Include SFML Graphics library
#include "SFML/Graphics.hpp"

using namespace std;

//Define the "windowWidth" constant
const int windowWidth = 800;

//Define the "windowHeight" constant
const int windowHeight = 800;

//Define the "inputBoxOutlineThickness" constant
const int inputBoxOutlineThickness = 2;

//Define the "ButtonOutlineThickness" constant
const int ButtonOutlineThickness = 5;

//Define const coordinates of the menu button
const int menuSpriteX = 10;
const int menuSpriteY = 10;

//The "screen" integer dictates which screen user is on
int screen = 0;

//Create color objects lightGray and darkGray
sf::Color lightGray(200, 200, 200);
sf::Color darkGray(100, 100, 100);

//Create font object
sf::Font font;

//Button class
class Button {
public:

    //The "AssoiciatedScreen" integer dictates which screen is switched to after button click
    int AssociatedScreen; 

    //Constructor

    //Takes in x-coordinate of the button, y-coordinate of the button, width of the button, the associated screen of the button when clicked, height of the button, and the button's title 
    Button(int x, int y, int width, int height, int associatedscreen, string buttonString) {

        //Set the "AssociatedScreen" integer
        AssociatedScreen = associatedscreen;

        //Set the size of the button as a vector with the width and height from the Constructor
        button.setSize(sf::Vector2f(width, height));

        //Set the position of the button at the coordinate (x, y)
        button.setPosition(x, y);

        //Set the color of the button to lightGray
        button.setFillColor(darkGray);

        //Set an outline thickness for the button
        button.setOutlineThickness(ButtonOutlineThickness);

        //Set the button's outline color to black
        button.setOutlineColor(sf::Color::Black);

        //Load the arial font file 
        font.loadFromFile("arial.ttf");

        //Use the "setFont" method to set the font of this text object to arial
        text.setFont(font);

        //Set the character size of the text to 20
        text.setCharacterSize(15);

        //Set the string of the text to the buttonString constructor arg
        text.setString(buttonString);

        int textWidth = text.getLocalBounds().width;
        int textHeight = text.getLocalBounds().height;
            
        //Set the position of the text to the exact center of the button rectangle
        text.setPosition(x+((width-textWidth)/2), y+((height-textHeight)/2));

        //Set the color of the text to black
        text.setFillColor(sf::Color::Black);
    }

    //Draw method
    void draw(sf::RenderWindow& window) {

        //Draw the button
        window.draw(button);

        //Draw the button's name
        window.draw(text);
    }

    //Method for handling mouse button clicks and mouse moves
    void handleInput(sf::Event& event, const sf::RenderWindow& window) {

        //If the mouse has moved
        if (event.type == sf::Event::MouseMoved) {
            
            //If the mouse is within the bounds of the button
            if (button.getGlobalBounds().contains(static_cast<int>(event.mouseMove.x), static_cast<int>(event.mouseMove.y))) {

                //Color the button light gray to create a hovering effect
                button.setFillColor(lightGray);
            }

            //If the mouse is not within the bounds of the button
            else {

                //Color the button dark gray because it's not being hovered over
                button.setFillColor(darkGray);
            }
        }

        //If the mouse is pressed
        if (event.type == sf::Event::MouseButtonPressed) {

            //If the left mouse button is pressed
            if (event.mouseButton.button == sf::Mouse::Left) {

                //If the mouse click is within the bounds of the button
                if (button.getGlobalBounds().contains(static_cast<int>(event.mouseButton.x), static_cast<int>(event.mouseButton.y))) {

                    //Change the screen integer to the screen associated with this button
                    screen = AssociatedScreen;
                }
            }
        }
    }
private:

    //Create RectangleShape object for button
    sf::RectangleShape button;

    //Create Text object for the text of the button's name
    sf::Text text;
};

//Input Box Class
class InputBox {
public:

    //Constructor

    //Takes in x-coordinate of input box, y-coordinate of input box, width of input box, and height of input box 
    InputBox(int x, int y, int width, int height) {

        //Set the "isActive" to false by default
        isActive = false;

        //Set the size of the box as a vector with the width and height from the Constructor
        box.setSize(sf::Vector2f(width, height));
        
        //Set the position of the box at the coordinate (x, y)
        box.setPosition(x, y);

        //Set the color of the box to lightGray
        box.setFillColor(darkGray);

        //Set an outline thickness
        box.setOutlineThickness(inputBoxOutlineThickness);

        //Set the box's outline color to black
        box.setOutlineColor(sf::Color::Black);

        //Load the arial font file 
        font.loadFromFile("arial.ttf");

        //Use the "setFont" method to set the font of this text object to arial
        text.setFont(font);

        //Set the position of the text (change later)
        text.setPosition(x, y);

        //Set the color of the text to black
        text.setFillColor(sf::Color::Black);

        //Set the character size of the text to 20
        text.setCharacterSize(20);
    }

    //Draw method
    void draw(sf::RenderWindow& window) {

        //Draw the input text box
        window.draw(box);

        //Draw the inputted text 
        window.draw(text);
    }

    //Method for handling mouse button clicks in text fields and key presses
    void handleInput(sf::Event& event, const sf::RenderWindow& window) {

        //If the mouse has moved
        if (event.type == sf::Event::MouseMoved) {

            //If the mouse is within the bounds of the input box
            if (box.getGlobalBounds().contains(static_cast<int>(event.mouseMove.x), static_cast<int>(event.mouseMove.y))) {

                //If the input box is not the active one
                if (!isActive) {

                    //Fill the input box with light gray to create a hovering effect
                    box.setFillColor(lightGray);
                }
            }

            //If the mouse is not within the bounds of the box
            else {

                //If the input box is not the active one
                if (!isActive) {

                    //Fill the input box with dark gray because it is not hovered over
                    box.setFillColor(darkGray);
                }
            }
        }




        //If the mouse is pressed
        if (event.type == sf::Event::MouseButtonPressed) {

            //If the left mouse button is pressed
            if (event.mouseButton.button == sf::Mouse::Left) {

                //If the mouse click is within the bounds of the input box
                if (box.getGlobalBounds().contains(static_cast<int>(event.mouseButton.x), static_cast<int>(event.mouseButton.y))) {

                    //Set the "isActive" boolean to true
                    isActive = true;

                    //Highlight the box by setting the outline color to red
                    box.setOutlineColor(sf::Color::Red); 
                }

                //If the mouse click is outside the bounds of the input box
                else {

                    //Set the "isActive" boolean to false
                    isActive = false;

                    //Highlight the box by setting the outline color to black
                    box.setOutlineColor(sf::Color::Black);

                    //Fill the box with dark Gray because the mouse is not over the input box
                    box.setFillColor(darkGray);
                }
            }
        }

        //If this box is active and a key is pressed
        if (isActive && event.type == sf::Event::TextEntered) {

            //If the backspace key is pressed and the userInput string is not an empty string
            if (event.text.unicode == 8 && !userInput.empty()) {

                //Remove the last character of the string
                userInput.pop_back();
            }

            //If the key pressed is not backspace, and the key pressed is a number
            else if (isNumberOrPeriod(event.text.unicode)) {
                userInput += static_cast<char>(event.text.unicode);
            }

            //Update the text object with the changed userInput string
            text.setString(userInput);
        }
    }

private:

    //Create a RectangleShape object called box for the user input box
    sf::RectangleShape box;

    //Create a Text object called text for the user input text
    sf::Text text;

    //Create a string for this user input box
    string userInput;

    //Create a boolean "isActive" to determine if user is selecting this text box
    bool isActive;

    //Method for checking if typed character is a number 0-9 or a period
    bool isNumberOrPeriod(sf::Uint32 unicode) {
        return (unicode >= '0' && unicode <= '9') || unicode == '.';
    }
};





//Main function
int main(int argc, char* argv[])
{
    //Test object
    Bachelier bachelier(100.0, 105.0, 1.0, 0.05, 0.2);

    //test call and put methods
    double callPrice = bachelier.getCallPrice();
    double putPrice = bachelier.getPutPrice();

    cout << "Call Option Price: " << callPrice << endl;
    cout << "Put Option Price: " << putPrice << endl;




    //Create window object
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "OptionsWizard");

    //Create Texture object for the menu image for the menu button sprit
    sf::Texture menuImg;

    //Load the image jpg file
    menuImg.loadFromFile("menu.jpg");

    //Create the Sprite object for the menu sprite and set its image as the menuImg
    sf::Sprite menuSprite;
    menuSprite.setTexture(menuImg);

    //Set the menu sprite's position
    menuSprite.setPosition(menuSpriteX, menuSpriteY);

    //Scale down the image to 10% of it's original size
    menuSprite.setScale(0.1, 0.1);

    //Create event object for event handling such as window close
    sf::Event e;

    //Load the arial font file 
    font.loadFromFile("arial.ttf");

    //Create a Text oject for the title text using the arial font
    sf::Text menuTitle("Menu", font, 30);

    //Get the width of the text block
    int textWidth = menuTitle.getLocalBounds().width;

    //Set the position of the text at the top middle of the screen
    menuTitle.setPosition((windowWidth-textWidth)/2, 10);

    //Set the title text color to black
    menuTitle.setFillColor(sf::Color::Black);

    //Create testInput object
    InputBox testInput(200, 200, 100, 20);


    vector<Button> buttons;

    buttons.emplace_back(200, 100, 200, 40, 1, "Black-Scholes");
    buttons.emplace_back(200, 200, 200, 40, 2, "Binomial");
    buttons.emplace_back(200, 300, 200, 40, 3, "Monte Carlo Simulation");
    buttons.emplace_back(200, 400, 200, 40, 4, "Bachelier");

    //Window loop
    while (window.isOpen()) {

        //Event handling loop
        while (window.pollEvent(e)) {

            if (e.mouseButton.button == sf::Mouse::Left) {

                //If the mouse click is within the bounds of the menu button
                if (menuSprite.getGlobalBounds().contains(static_cast<int>(e.mouseButton.x), static_cast<int>(e.mouseButton.y))) {
                    screen = 0;
                }
            }

            //If the user is trying to close the window
            if (e.type == sf::Event::Closed) {

                //Close the window
                window.close();
            }

            if (screen == 0) {
                for (int i = 0; i < buttons.size(); ++i) {
                    buttons[i].handleInput(e, window);
                }
            }
            else {
                testInput.handleInput(e, window);
            }


        }

        //Set the background of the window to white
        window.clear(sf::Color::White);

        //Display the title
        if (screen == 0) {
            window.draw(menuTitle);
            for (int j = 0; j < buttons.size(); ++j) {
                buttons[j].draw(window);
            }

        }
        else {
            testInput.draw(window);
        }

        window.draw(menuSprite);

        //Update the window display for this frame
        window.display();

    }

    return 0;
}
