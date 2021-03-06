#pragma once
#ifndef HERO_H
#define HERO_H
#include <GameWindow.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/** @hero hero.h
 *  @brief Hero class .h file
 *  LO1. Design and implement a class
 *    - LO1a. There are other classes that utilize .h and .cpp files as well.
 *  
 *
 *  @author Chance Mullen
 *  @bug No known bugs.
 */

class hero
{
private:
	/* Hero attributes */
	
	float radius{25.f};
	float windowX {}, windowY {};
	float gunRotation;
	sf::Vector2f windowPos{ windowX / 2, windowY / 2 };
	sf::RenderWindow* hero_ptr{};
	sf::Color color = sf::Color::Cyan;
	sf::CircleShape 
		body{this->radius},
		hitBox{ this->radius + 10 };
	sf::RectangleShape gun { sf::Vector2f(9.f, 25.f) };

public:
	hero(GameWindow* window); // Constructor
	virtual void draw(GameWindow* target); // Draw Hero to screen
	void initHero(); // Initialize hero attributes (Hero, Hero hitbox, and Hero gun.)
	void setColor(sf::Color newColor); // Change Hero color
	sf::Vector2f rotateGun(GameWindow* window); // Calculate the rotation of the gun based upon where the mouse is on the screen
};

#endif
