#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class enemy : public sf::Drawable
{
public:
	enemy() : hitpointCount(3), radius(20) {}
	enemy(sf::Color newColor, float radius, sf::Vector2f spawnPos): color(newColor) {}


private:
	int hitpointCount;
	int score_multiplier;
	float radius;
	float size_multiplier;
	bool isDead;
	sf::Color color;
};

#endif
