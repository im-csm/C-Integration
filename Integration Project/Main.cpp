#include <iostream>
#include <string>
#include <math.h>
#include "Automobile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

float calculateTheta(float x_diff, float y_diff);

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

		// Gun Rotation Logic
		float x_diff_left  = hero.getPosition().x - mouseX;
		float x_diff_right = mouseX - hero.getPosition().x;
		float y_diff_above = hero.getPosition().y - mouseY;
		float y_diff_below = mouseY - hero.getPosition().y;
		float rotation = 0;
		/*
		// Quadrant 1
		if (sf::Mouse::getPosition(window).x > 400 && sf::Mouse::getPosition(window).y < 300)
		{
			oldRotation = rotation;
			rotation_diff = calculateTheta(x_diff_right, y_diff_above) - oldRotation;
			rotation += rotation_diff;
		}
		// Quadrant 2
		if (sf::Mouse::getPosition(window).x > 400 && sf::Mouse::getPosition(window).y > 300)
		{
			oldRotation = rotation;
			rotation = calculateTheta(x_diff_right, y_diff_below) - oldRotation;
			rotation += rotation_diff;
		}
		// Quadrant 3
		if (sf::Mouse::getPosition(window).x < 400 && sf::Mouse::getPosition(window).y > 300)
		{
			oldRotation = rotation;
			rotation = calculateTheta(x_diff_left, y_diff_below) - oldRotation;
			rotation += rotation_diff;
		}
		// Quadrant 4
		if (sf::Mouse::getPosition(window).x < 400 && sf::Mouse::getPosition(window).y < 300)
		{
			oldRotation = rotation;
			rotation = calculateTheta(x_diff_left, y_diff_above) - oldRotation;
			rotation += rotation_diff;
		}
		*/
		
		// Quadrant 1
		if (mouseX > 400 && mouseY < 300) 
		{
			rotation = calculateTheta(x_diff_right, y_diff_above);
		}
		// Quadrant 2
		if (mouseX > 400 && mouseY > 300)
		{
			rotation = calculateTheta(x_diff_right, y_diff_below);
		}
		// Quadrant 3
		if (mouseX < 400 && mouseY > 300)
		{
			rotation = calculateTheta(x_diff_left, y_diff_below);
		}
		// Quadrant 4
		if (mouseX < 400 && mouseY < 300)
		{
			rotation = calculateTheta(x_diff_left, y_diff_above);
		}

		// Event obect
		sf::Event ev;
		
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
				//std::cout << "x: " << gun.getPosition().x << " y: " << gun.getPosition().y << "\n";
				std::cout << "Hero x: " << hero.getPosition().x << " Hero y: " << hero.getPosition().y << "\n";
				std::cout << "X diff left: " << x_diff_left << " X diff right: " << x_diff_right << "\n" << "Y diff below = " << y_diff_below << " Y diff aboe = " << y_diff_above << "\n";
				std::cout << "Rotation change = " << rotation << "\n";
				std::cout << "\n";
				std::cout << "Theta Q1: " << rotation << "\n";
				std::cout << "Theta Q2: " << rotation << "\n";
				std::cout << "Theta Q3: " << rotation << "\n";
				std::cout << "Theta Q4: " << rotation << "\n";
				break;

			default:
				break;
			}
		}
		
		
		// Clears current frame
		window.clear();

		gun.setRotation(rotation);
		//std::cout << "Rotation Angle: " << gun.getRotation() << "\n";

		// Draw shapes to the screen for new frame
		window.draw(hero);
		window.draw(gun);
		//window.draw(tip);


		// Display new window frame
		window.display();
	}


	return 0;
}

float calculateTheta(float x_diff, float y_diff)
{
	float theta;
	float TOA = y_diff / x_diff;
	theta = atan(TOA) * (180 / 3.14159265);
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
