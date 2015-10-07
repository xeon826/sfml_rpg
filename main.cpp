#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define set setSize(sf::Vector2f(2.5,2.5))
#define setPos setPosition
#define windowY 1000
#define windowX 500

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "SFML works!");
    sf::RectangleShape star[100];

    srand(time(NULL));
    for(int index=0;index<100;index++) {
        star[index].set;
        star[index].setPos((rand()+windowX)%windowX,(rand()+windowY)%windowY);
    }
    int starSpeed[100];
    for(int index=0;index<100;index++) {
        starSpeed[index]=((rand()%20)+10);
    }

    sf::Texture texture;
    texture.loadFromFile("images/ship.png");
    sf::Sprite player;
    player.setTexture(texture);
    player.setPosition(350,350);
    const int fast = 5, still = 0;
    float rotationAngle = 90;
    sf::Vector2f pos;
    sf::Time t1 = sf::microseconds(800000);
    float sec = t1.asSeconds();

    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type=sf::Event::KeyPressed)
                switch(event.key.code) {
                    case sf::Keyboard::Right:player.move(fast,still);
                                             break;
                    case sf::Keyboard::Left:player.move(-fast,still);
                                            break;
                    case sf::Keyboard::Up:player.move(still,-fast);
                                          break;
                    case sf::Keyboard::Down:player.move(still,fast);
                                            break;
                }
        }
        for(int index=0;index<100;index++){
            pos=star[index].getPosition();
            star[index].move(still,.1);
            window.draw(star[index]);
            if (pos.y>=windowY)
                star[index].setPos((rand()+500)%500,0);
        }
             
        window.draw(player);
        window.display();
    }
    return 0;

}
