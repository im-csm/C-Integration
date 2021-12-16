#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class enemy : public sf::Drawable
{
public:
	// LO1b / LO1c
	// enemy default sets the default hitpointCount, and radius.
	enemy() : hitpointCount(3), radius(20.f) {}
	// The overloaded constructor takes a new sf::Color, a float for the radius, and a new spawn position. 
	enemy(sf::Color newColor, float radius, sf::Vector2f spawnPos): color(newColor) , radius(radius), spawnPosition(spawnPos) {}


private:
	int hitpointCount {0} ;
	int score_multiplier {0} ;
	float radius {0.f};
	float size_multiplier {1.f} ;
	bool isDead {false} ;
	sf::Vector2f spawnPosition {} ;
	sf::Color color;
};

#endif
