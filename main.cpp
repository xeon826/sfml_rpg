#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::RectangleShape player;
    player.setSize(sf::Vector2f(50, 50));
    player.setOutlineColor(sf::Color::Red);
    player.setOutlineThickness(5);
    player.setPosition(10,20);
    const int fast = 5, still = 0;
    float rotationAngle = 90;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            switch(event.type) {
                case sf::Event::KeyPressed:
                    switch(event.key.code) {
                        case sf::Keyboard::Right:player.move(fast,still);
                                                 break;
                        case sf::Keyboard::Left:player.move(-fast,still);
                                                break;
                        case sf::Keyboard::Up:player.move(still,-fast);
                                              break;
                        case sf::Keyboard::Down:player.move(still,fast);
                                                break;
                        case sf::Keyboard::Space:player.rotate(rotationAngle);
                                                 rotationAngle = - rotationAngle;
                                                 break;
                    }
                    break;

            }

            window.clear();
            window.draw(player);
            window.display();
        }
    }
    return 0;

}
