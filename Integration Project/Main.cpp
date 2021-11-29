#include <iostream>
#include <string>
#include "Automobile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

int main()
{
	//sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::RenderWindow window(sf::VideoMode(800, 600), "Integration Project");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(shape);
			window.display();
		}
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

	return 0;
}

