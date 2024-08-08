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

//Input Box Class
class InputBox {
public:

    //Constructor
    InputBox(int x, int y, int width, int height) {

        isActive = false;

        box.setSize(sf::Vector2f(width, height));
        box.setPosition(x, y);
        box.setFillColor(sf::Color::White);
        box.setOutlineThickness(2);
        box.setOutlineColor(sf::Color::Black);

        font.loadFromFile("arial.ttf");

        text.setFont(font);

        text.setPosition(x + 5, y + 5);
        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(20);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(box);
        window.draw(text);
    }

    void handleInput(sf::Event& event, const sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                cout << "ohno" << endl;
                if (box.getGlobalBounds().contains(static_cast<int>(event.mouseButton.x), static_cast<int>(event.mouseButton.y))) {
                    cout << "detected" << endl;
                    isActive = true;
                    box.setOutlineColor(sf::Color::Blue); // Highlight the active box
                }
                else {
                    isActive = false;
                    box.setOutlineColor(sf::Color::Black);
                }
            }
        }

        if (isActive && event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 8 && !userInput.empty()) {  // Backspace
                userInput.pop_back();
            }
            else if (isAllowedCharacter(event.text.unicode)) {
                userInput += static_cast<char>(event.text.unicode);
            }
            text.setString(userInput);
        }
    }

private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    std::string userInput;
    bool isActive;

    bool isAllowedCharacter(sf::Uint32 unicode) {
        // Check if the character is a number (0-9) or a period (.)
        return (unicode >= '0' && unicode <= '9') || unicode == '.';
    }
};





//Main function
int main(int argc, char* argv[])
{
    
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

    InputBox testInput(200, 200, 100, 20);

    //Window loop
    while (window.isOpen()) {

        //Event handling loop
        while (window.pollEvent(e)) {

            //If the user is trying to close the window
            if (e.type == sf::Event::Closed) {

                //Close the window
                window.close();
            }

            testInput.handleInput(e, window);

        }

        //Set the background of the window to Red
        window.clear(sf::Color::Red);

        //Display the title
        window.draw(title);

        testInput.draw(window);

        //Update the window display for this frame
        window.display();

    }

    return 0;
}
