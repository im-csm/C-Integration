#include <iostream>
#include <string>
#include <math.h>
#include "Automobile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

// Function Prototypes
float calcTheta(float mouse_x, float mouse_y, float &theta);

int main()
{
	// Create Window
	float window_w = 800.f, window_h = 600.f;
	sf::RenderWindow window(sf::VideoMode(window_w, window_h), "Circle Shooter");
	window.setMouseCursorVisible(true);
	window.setFramerateLimit(60);

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
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		// Gun Rotation Logic
		float rotation = 0;
		float* theta = &rotation;
		

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
				//std::cout << "Hero x: " << hero.getPosition().x << " Hero y: " << hero.getPosition().y << "\n";
				std::cout << "Mouse X pos: " << mouseX << "Mouse Y pos: " << mouseY << "\n";
				std::cout << "Current Rotation = " << rotation << "\n";
				std::cout << "Theta = " << calcTheta(mouseX, mouseY, *theta) << "\n";
				std::cout << "\n";
				//std::cout << "Theta Q1: " << rotation << "\n";
				//std::cout << "Theta Q2: " << rotation << "\n";
				//std::cout << "Theta Q3: " << rotation << "\n";
				//std::cout << "Theta Q4: " << rotation << "\n";
				break;

			default:
				break;
			}
		}
		
		
		// Clears current frame
		window.clear();

		// Update Rotation of gun to point towards the mouse
		// Quadrant 1
		if (mouseX == 400 && mouseY < 300)
			gun.setRotation(0);
		if (mouseX > 400 && mouseY < 300)
		{
			rotation = calcTheta(mouseX, mouseY, *theta);
			gun.setRotation(rotation);
		}

		// Quadrant 2
		if (mouseX > 400 && mouseY == 300)
			gun.setRotation(90);
		if (mouseX > 400 && mouseY > 300)
		{
			rotation = 90 + calcTheta(mouseX, mouseY, *theta);
			gun.setRotation(rotation);
		}
		
		// Quadrant 3
		if (mouseX == 400 && mouseY > 300)
			gun.setRotation(180);
		if (mouseX < 400 && mouseY > 300)
		{
			rotation = 180 + calcTheta(mouseX, mouseY, *theta);
			gun.setRotation(rotation);
		}
		
		// Quadrant 4
		if (mouseX < 400 && mouseY == 300)
			gun.setRotation(270);
		if (mouseX < 400 && mouseY < 300)
		{
			rotation = 270 + calcTheta(mouseX, mouseY, *theta);
			gun.setRotation(rotation);
		}

		// Draw shapes to the screen for new frame
		window.draw(hero);
		window.draw(gun);
		//window.draw(tip);


		// Display new window frame
		window.display();
	}


	return 0;
}

// Function Defs

float calcTheta(float mouse_x, float mouse_y, float &theta)
{
	float new_theta = theta;
	// Quadrant 1
	if (mouse_x > 400 && mouse_y < 300)
	{
		new_theta = atan((mouse_x - 400) / (300 - mouse_y));
		new_theta *= (180 / 3.14);
	}

	// Quadrant 2
	if (mouse_x > 400 && mouse_y > 300)
	{
		new_theta = atan((mouse_y - 300) / (mouse_x - 400));
		new_theta *= (180 / 3.14);
	}

	// Quadrant 3
	if (mouse_x < 400 && mouse_y > 300)
	{
		new_theta = atan((400 - mouse_x) / (mouse_y - 300));
		new_theta *= (180 / 3.14);
	}

	// Quadrant 4
	if (mouse_x < 400 && mouse_y < 300)
	{
		new_theta = atan((300 - mouse_y) / (400 - mouse_x));
		new_theta *= (180 / 3.14);
	}
	return new_theta;
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
