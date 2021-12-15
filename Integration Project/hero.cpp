#include "hero.h"
#include <GameWindow.h>

// Constructor
hero::hero(GameWindow* window) 
{
	this->windowX = window->getDimensions().x;
	this->windowY = window->getDimensions().y;
	this->hero_ptr = window->Pointer();
}

// Draw Hero to screen
void hero::draw(GameWindow* target) { this->draw(target); }

// Setup Hero attributes
void hero::initHero()
{
	// Hero Attributes
	this->body.setFillColor(this->color);
	this->body.setOrigin(this->radius, this->radius);				
	this->body.setPosition(this->windowPos);	
	
	// Hitbox setup
	this->hitBox.setFillColor(sf::Color::Blue);
	this->hitBox.setOutlineColor(sf::Color::Blue);
	this->hitBox.setOutlineThickness(3.f);
	this->hitBox.setOrigin(this->hitBox.getRadius(), this->hitBox.getRadius());
	this->hitBox.setPosition(this->windowPos);

	// Gun Setup
	this->gun.setFillColor(sf::Color::Black);
	this->gun.setOrigin(this->gun.getLocalBounds().width / 2 - 11, this->gun.getLocalBounds().height + 6);
	this->gun.setPosition(this->windowPos);
}

// Change Hero color
void hero::setColor(sf::Color newColor)
{
	this->color == newColor;
}
