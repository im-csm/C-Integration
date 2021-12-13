#include <iostream>
#include <string>
#include "Automobile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

float calculateTheta(float x_diff, float y_diff) 
{
	int theta;
	return theta;
}

int main()
{
	// Create Window
	int window_h = 800, window_w = 600;
	sf::RenderWindow window(sf::VideoMode(window_h, window_w), "Integration Project");
	window.setMouseCursorVisible(true);
	window.setFramerateLimit(60);


	// The hero of the adventure. A cyan circle standing in the middle of the apocalypse.
	// Defend your glory or perish.
	sf::CircleShape hero(25.f);
	hero.setFillColor(sf::Color::Cyan);
	hero.setOrigin(hero.getRadius(), hero.getRadius());
	hero.setPosition(sf::Vector2f(window_h / 2.f, window_w / 2.f));
	auto heroBounds = hero.getTextureRect();

	
	// Gun

	sf::RectangleShape gun(sf::Vector2f(7.f, 25.f));
	gun.setFillColor(sf::Color::White);
	gun.setOrigin(gun.getLocalBounds().width / 2, gun.getLocalBounds().height + 6);
	gun.setPosition(hero.getPosition().x, hero.getPosition().y);
	gun.setRotation(90);
	
	//Gun Tip ** COMING BACK TO THIS **
	/*
	sf::RectangleShape tip(sf::Vector2f(5.f, 2.f));
	tip.setFillColor(sf::Color::Color(253, 177, 24));
	tip.setRotation(gun.getRotation());
	tip.setOrigin(2.5, 1.f);
	tip.setPosition(gun.getPosition().x, gun.getPosition().y - 31 );
	//tip.setPosition(window_h / 2.f, window_w / 2.f);
	*/

	// Main loop
	while (window.isOpen())
	{
		
		// Variables
		auto mouseX = sf::Mouse::getPosition(window).x;
		auto mouseY = sf::Mouse::getPosition(window).y;
		//float *heroX = &hero_x;
		//float *heroY = &hero_y;
		//float heroEdgeX = *heroX + hero.getRadius();
		//float heroEdgeY = *heroY + hero.getRadius();
		//hero.setPosition( sf::Vector2f(window_h / 2.f, window_w / 2.f) );
		//hero.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

		// Event obect
		sf::Event ev;
		
		// Loop checks for an event
		while (window.pollEvent(ev))
		{
			// Top right X clicked to close the window
			if (ev.type == sf::Event::Closed)
				window.close();
			if (ev.type == sf::Event::MouseButtonPressed)
			{
				std::cout << "Mouse X pos: " << mouseX << "Mouse Y pos: " << mouseY << "\n";
				std::cout << "x: " << gun.getPosition().x << " y: " << gun.getPosition().y << "\n";
				//std::cout << "Hero x: " << tip.getPosition().x << " Hero y: " << tip.getPosition().y << "\n";
			}
		}
		
		// Clears current frame
		window.clear();

		// Draw shapes to the screen for new frame
		window.draw(hero);
		window.draw(gun);
		//window.draw(tip);


		// Display new window frame
		window.display();
	}


	return 0;
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
