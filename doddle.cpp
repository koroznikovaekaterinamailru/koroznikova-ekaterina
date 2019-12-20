#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

struct Plat
{ 
    int x = 0;
    int y = 0;
    float dy = 0;
    int weightPlarform = 80;
    int heightPlatform = 15;
    int number_of_points = 0;
    int weight = 500;
    int height = 700;
};

void drawPlatform(Plat* plat, int array, sf::RenderWindow* window) 
{ 
    sf::RectangleShape platform(sf::Vector2f(plat -> weightPlarform, plat -> heightPlatform)); 
    platform.setFillColor(sf::Color(150, 50, 250)); 
    for (int i = 0; i < array ;i++)
    {
        platform.setPosition(plat[i].x, plat[i].y); 
        window -> draw(platform); 
    }
}

void JumpOnPlatform(Plat* plat, int array, sf::RenderWindow* window) 
{
    for (int i = 0; i < array; i++)
    { 
        if(((plat -> x + 50) > plat[i].x) && ((plat -> x + 30) < (plat[i].x + plat -> weightPlarform)) && (plat -> y + 75 > plat[i].y) && (plat -> y + 75 < plat[i].y + plat -> heightPlatform) && (plat -> dy > 0))               
        {
            plat -> dy = -10;
            plat -> number_of_points += 1;
        }    
    }
} 

void PlatformPosition(Plat* plat, int array, sf::RenderWindow* window) 
{
    for (int i = 0; i < array; i++) 
    { 
        plat[i].x = rand() % (plat -> weight - plat -> weightPlarform); 
        plat[i].y = rand() % (plat -> height - plat -> heightPlatform); 
        for(int j = 0; j < array; j++)
        {
            abs(plat[j].x - plat[i].x) < plat -> weightPlarform;
            abs(plat[j].y - plat[i].y) < plat -> heightPlatform;
        }   
    }   
}


void Scroll(Plat* plat, int array, sf::RenderWindow* window)
{
    int scroll = 200;
    if (plat -> y < scroll)
        for (int i = 0; i < array; i++)
        {
            plat -> y = scroll;
            plat[i].y -=  plat -> dy;
            if (plat[i].y > plat -> height) 
                {
                    plat[i].y = 0; 
                    plat[i].x = rand() % (plat -> weight - plat -> weightPlarform);
                }
        }
}

void DrawMonster(Plat* plat, int array, sf::RenderWindow* window)
{
    sf::Texture monster;
    monster.loadFromFile("monster.png");
    sf::Sprite spriteMonster(monster);
    spriteMonster.setPosition(plat -> x, plat -> y); 
    window -> draw(spriteMonster);    
}

void MoveMonster(Plat* plat, int array, sf::RenderWindow* window) 
{ 
    sf::Texture  gameover;
    gameover.loadFromFile("gameover.png");
    sf::Sprite spriteGameOver(gameover);
    spriteGameOver.setPosition(sf::Vector2f(100, 250));

    plat -> dy += 0.15;
    plat -> y += plat -> dy;

    if (plat -> x < 0)
        plat -> x += 3;
    if ((plat -> x) > (plat -> weight - 80))
        plat -> x -= 3;

    if (plat -> number_of_points < 1)
    {
        if (plat -> y > 620)  
        {
            plat -> dy = -10;
        }
    }
    else
    {    
        if (plat -> y > plat -> height)  
        {
            window -> draw(spriteGameOver);    
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        plat -> x += 3; 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
        plat -> x -= 3; 
} 

void FromMenuToRecords(Plat* plat, sf::RenderWindow* window) 
{
    sf :: Font font;
    font.loadFromFile("calibri.ttf");
    sf::Text text; 
    text.setFont(font); 
    text.setCharacterSize(30);
    text.setFillColor(sf::Color(255, 255, 255));
    text.setPosition(plat -> weight/2 - 20, plat -> height/2 - 20);

    sf::Texture background;
    background.loadFromFile("1.jpg");
    sf::Sprite spriteBack(background);

    window -> clear();
    window -> draw(spriteBack);
    text.setString("NUMBERS OF POINTS");            
    text.setString(std::to_string(plat -> number_of_points));
    window -> draw(text);
}

int main()
{
    int weight = 500;
    int height = 700;
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(weight, height), "Good Game!");

    sf::Texture background, menu, play,records, gameover;
    background.loadFromFile("1.jpg");
    menu.loadFromFile("menu.png");
    play.loadFromFile("play1.png");
    records.loadFromFile("records1.png");
    sf::Sprite spriteBack(background), spriteMenu(menu), spritePlay(play), spriteRecords(records);
    spritePlay.setPosition(sf::Vector2f(150, 200));
    spriteRecords.setPosition(sf::Vector2f(150, 320));

    int FromMenuToPlay = 0;
    int rec = 0;
    int array = 10;

    Plat* plat = new Plat[array];
    PlatformPosition(plat, array, &window); 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(spriteMenu);
        window.draw(spritePlay);
        window.draw(spriteRecords);

        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (sf::IntRect(150, 200, 200, 100).contains(sf::Mouse::getPosition(window))))
        {
            FromMenuToPlay = FromMenuToPlay + 1;
        }

        if (FromMenuToPlay > 0)          
        {
            window.clear();
            window.draw(spriteBack);
            drawPlatform(plat, array, &window);
            Scroll(plat, array, &window);
            JumpOnPlatform(plat, array, &window);
            DrawMonster(plat, array, &window);
            MoveMonster(plat, array, &window);
        }

        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (sf::IntRect(150, 320, 200, 100).contains(sf::Mouse::getPosition(window))))
        {
            rec = rec + 1;
        }

        if (rec > 0)          
        {
            FromMenuToRecords(plat, &window);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
        {
            window.clear();
            FromMenuToPlay = 0;  
            rec = 0;      
        }
        window.display();
    }
    
    delete [] plat;
    return 0;
}
