#pragma once
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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