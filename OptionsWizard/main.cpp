//Incliude strings
#include <string>

//Include vectors
#include <vector>

#include <iostream>

//Include header files for pricing model classes
#include "BlackScholes.h"

//Include SFML Graphics library
#include "SFML/Graphics.hpp"

using namespace std;

//Define the "windowWidth" constant
const int windowWidth = 800;

//Define the "windowHeight" constant
const int windowHeight = 800;

//Define the "inputBoxOutlineThickness" constant
const int inputBoxOutlineThickness = 2;

const int ButtonOutlineThickness = 5;

const int menuSpriteX = 10;
const int menuSpriteY = 10;

bool onMenu = false;

//Create color object lightGray
sf::Color lightGray(200, 200, 200);
sf::Color darkGray(100, 100, 100);


sf::Font font;

class Button {
public:

    //Constructor

    //Takes in x-coordinate of input box, y-coordinate of input box, width of input box, and height of input box 
    Button(int x, int y, int width, int height, string buttonString) {

        //Set the size of the box as a vector with the width and height from the Constructor
        button.setSize(sf::Vector2f(width, height));

        //Set the position of the box at the coordinate (x, y)
        button.setPosition(x, y);

        //Set the color of the box to lightGray
        button.setFillColor(darkGray);

        //Set an outline thickness
        button.setOutlineThickness(ButtonOutlineThickness);

        //Set the box's outline color to black
        button.setOutlineColor(sf::Color::Black);

        //Load the arial font file 
        font.loadFromFile("arial.ttf");

        //Use the "setFont" method to set the font of this text object to arial
        text.setFont(font);

        //Set the position of the text (change later)
        text.setPosition(x, y);

        //Set the color of the text to black
        text.setFillColor(sf::Color::Black);

        //Set the character size of the text to 20
        text.setCharacterSize(40);

        text.setString(buttonString);
    }

    //Draw method
    void draw(sf::RenderWindow& window) {

        //Draw the input text box
        window.draw(button);

        //Draw the inputted text 
        window.draw(text);
    }

    //Method for handling mouse button clicks in text fields
    void handleInput(sf::Event& event, const sf::RenderWindow& window) {


        if (event.type == sf::Event::MouseMoved) {
            if (button.getGlobalBounds().contains(static_cast<int>(event.mouseMove.x), static_cast<int>(event.mouseMove.y))) {
                button.setFillColor(darkGray);
            }
            else {
                button.setFillColor(lightGray);
            }
        }




        //If the mouse is pressed
        if (event.type == sf::Event::MouseButtonPressed) {

            //If the left mouse button is pressed
            if (event.mouseButton.button == sf::Mouse::Left) {

                //If the mouse click is within the bounds of the input box
                if (button.getGlobalBounds().contains(static_cast<int>(event.mouseButton.x), static_cast<int>(event.mouseButton.y))) {

                    cout << "clicked" << endl;
                }
            }
        }
    }
private:

    //
    sf::RectangleShape button;

    //
    sf::Text text;

    //
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
        box.setFillColor(lightGray);

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


        if (event.type == sf::Event::MouseMoved) {
            if (box.getGlobalBounds().contains(static_cast<int>(event.mouseMove.x), static_cast<int>(event.mouseMove.y))) {
                if (!isActive) {
                    box.setFillColor(sf::Color::White); // Hover color
                }
            }
            else {
                if (!isActive) {
                    box.setFillColor(lightGray); // Default color
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


                    box.setFillColor(lightGray);
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
    
    //Create window object
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "OptionsWizard");


    sf::Texture menuImg;
    menuImg.loadFromFile("menu.jpg");

    sf::Sprite menuSprite;
    menuSprite.setTexture(menuImg);


    menuSprite.setPosition(menuSpriteX, menuSpriteY);

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

    Button testButton(200, 200, 200, 40, "Black-Scholes");

    //Window loop
    while (window.isOpen()) {

        //Event handling loop
        while (window.pollEvent(e)) {

            if (e.mouseButton.button == sf::Mouse::Left) {

                //If the mouse click is within the bounds of the menu button
                if (menuSprite.getGlobalBounds().contains(static_cast<int>(e.mouseButton.x), static_cast<int>(e.mouseButton.y))) {
                    onMenu = true;
                }
            }

            //If the user is trying to close the window
            if (e.type == sf::Event::Closed) {

                //Close the window
                window.close();
            }

            if (onMenu == true) {
                testButton.handleInput(e, window);
            }
            else {
                testInput.handleInput(e, window);
            }


        }

        //Set the background of the window to white
        window.clear(sf::Color::White);

        //Display the title
        if (onMenu == true) {
            window.draw(menuTitle);
            testButton.draw(window);

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
