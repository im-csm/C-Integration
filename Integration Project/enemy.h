#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/*	LO1.
	This is my enemy class. This class is what the other enemy types inherit from.
	This class also inherits from the drawable class from SFML
*/

class enemy : public sf::Drawable
{
public:
	enemy(int health, float radius, bool isDead)
	{
		this->hitpointCount = health;
		this->radius = radius;
		this->isDead = isDead;
	}
	


private:
	int hitpointCount;
	int score_multiplier;
	float radius;
	float size_multiplier;
	bool isDead;
	sf::FloatRect hitbox = this->
};

#endif