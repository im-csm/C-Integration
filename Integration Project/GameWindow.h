#pragma once
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/** @GameWindow GameWindow.h
 *  @Creates the unique window for which the game is played in.
 *
 *  LO2. This GameWindow class utilizes subclassing to inherit from sf::RenderWindow.
 *  This allows me to use RenderWindow methods and return them for functions using a specific GameWindow Object
 *    - LO2a. The visibility in this class is public. This allows me to still access public and private members of
 	RenderObject.
 *
 *  @author Chance Mullen
 *  @bug No known bugs.
 */

class GameWindow : public sf::RenderWindow
{
private:
	//sf::RenderWindow window;
	sf::RenderWindow window{};
	sf::Vector2f mousePos {sf::Mouse::getPosition(window)};
	sf::Event gameEvent{};

public:
	GameWindow(); // Default constructor for a window
	bool winOpen();
	bool eventLoop(sf::Event ev);
	void update();
	sf::Vector2f mousePosition();
};

#endif
