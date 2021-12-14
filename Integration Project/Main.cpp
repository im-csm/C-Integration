#include <iostream>
#include <string>
#include <math.h>
#include <enemy.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

// Function Prototypes
//float calcTheta(float mouse_x, float mouse_y);

int main()
{
	// Create Window
	float window_w = 800.f, window_h = 600.f;
	sf::RenderWindow window(sf::VideoMode(window_w, window_h), "Circle Shooter");
	window.setMouseCursorVisible(true);
	window.setFramerateLimit(60);

	// Game clock started
	//sf::Clock game_time;

	// The hero of the adventure
	sf::CircleShape hero(25.f);
	hero.setFillColor(sf::Color::Cyan);
	hero.setOrigin(hero.getRadius(), hero.getRadius());				// Origin set to center of itself
	hero.setPosition(sf::Vector2f(window_w / 2.f, window_h / 2.f));	// Hero origin @ (400, 300)

	// Gun
	sf::RectangleShape gun(sf::Vector2f(7.f, 25.f));
	gun.setFillColor(sf::Color::White);
	gun.setOrigin(gun.getLocalBounds().width / 2, gun.getLocalBounds().height + 6);
	gun.setPosition(hero.getPosition().x, hero.getPosition().y);
	
	/*
	//Gun Tip
	sf::RectangleShape gunTip(sf::Vector2f(20.f, 50.f));
	//gunTip.setFillColor(sf::Color::Color(253, 177, 24));
	gunTip.setFillColor(sf::Color::White);
	gunTip.setPosition(window_w / 2, window_h / 2);
	//tip.setOrigin(tip.getSize().x / 2.f, tip.getSize().y /2 );
	//tip.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	*/

	// Enemy creation
	//srand(time(0));
	//int randomPosX = rand() % static_cast<int>(window_w);
	//int randomPosY = rand() % static_cast<int>(window_h);
	//sf::CircleShape enemy1(35.f);
	//enemy1.setFillColor(sf::Color::Red);
	//enemy1.setOrigin(enemy1.getRadius(), enemy1.getRadius());
	//enemy1.setPosition(randomPosX, randomPosY);

		
	// Event obect
	sf::Event ev;
	
	// Main loop
	while (window.isOpen())
	{
		// Gather time elapsed
		sf::Time elapsed = game_time.getElapsedTime();

		// Variables
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;
		
		// Gun Rotation Logic
		float rotation = 0;
		
		// Loop checks for an event
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			// window closed
			case sf::Event::Closed:
				window.close();
				break;
				
			case sf::Event::MouseButtonPressed:
				std::cout << "Mouse X pos: " << mouseX << "Mouse Y pos: " << mouseY << "\n";
				std::cout << "Current Rotation = " << rotation << "\n";
				std::cout << "Time elapsed since game started: " << elapsed.asSeconds() << "\n";
				//std::cout << "Theta = " << calcTheta(mouseX, mouseY) << "\n";
				std::cout << "\n";
				break;

			default:
				break;
			}
		}
		
		// Clears current frame
		window.clear();

		// Update Rotation of gun to point towards the mouse
		//rotation = calcTheta(mouseX, mouseY);
		//gun.setRotation(rotation);

		// Draw shapes to the screen for new frame
		window.draw(hero);
		window.draw(gun);
		//window.draw(enemy1);

		// Display new window frame
		window.display();
	}


	return 0;
}

// Function Defs

float calcTheta(float mouse_x, float mouse_y)
{
	float theta;
	// Quadrant 1
	if (mouse_x > 400 && mouse_y < 300)
		theta = atan((mouse_x - 400) / (300 - mouse_y) * (180 / 3.14));
	// Quadrant 2
	if (mouse_x > 400 && mouse_y > 300)
		theta = atan((mouse_y - 300) / (mouse_x - 400) * (180 / 3.14));
	// Quadrant 3
	if (mouse_x < 400 && mouse_y > 300)
		theta = atan((400 - mouse_x) / (mouse_y - 300) * (180 / 3.14));
	// Quadrant 4
	if (mouse_x < 400 && mouse_y < 300)
		theta = atan((300 - mouse_y) / (400 - mouse_x)) * (180 / 3.14);
	return theta;
}


/*
Automobile zoomies;
zoomies.setMake("Honda Accord");
zoomies.setWheels(4);
for (int x = 0; x < 60; x++)
{
	int ZeroTo60 = x;
	zoomies.Accelerate();
	cout << "Time since launch: " << ZeroTo60 << " seconds." << "\n";
	cout << "Current Speed: " << zoomies.getSpeed() << "\n";
}
*/
