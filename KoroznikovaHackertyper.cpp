#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream> 

using namespace sf;
using namespace std;

char s[4];
int LEN = 0;
int POSITION = 0;
string COMPLETE_text;
sf::Font font;
sf::Text text;

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    std::fstream file ("main.cpp");

    file.seekg(0, file.end);
    LEN = file.tellg();

    text.setFont(font);
    text.setColor(sf::Color::Red);
    text.setCharacterSize(20);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {

                if (POSITION < LEN) {

                    window.clear();
                    file.seekg(POSITION,file.beg);
                    file.read(s, 4);
                    POSITION += 4;
                    COMPLETE_text += s;
                    text.setString(COMPLETE_text);
                    window.draw(text);
                    window.display();
                }
	}
	}
	}
    
return 0;
}
