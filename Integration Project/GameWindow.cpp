#include <GameWindow.h>	

// Default window constructor
GameWindow::GameWindow()
{
	this->window.create(sf::VideoMode(800.f, 600.f), "Circle Shooter");
	this->window.setMouseCursorVisible(true);
	this->window.setFramerateLimit(60);
}

bool GameWindow::eventLoop(sf::Event ev) { return this->window.pollEvent(ev); }

void GameWindow::update() { this->window.clear(sf::Color::White); }

sf::Vector2f GameWindow::mousePosition() { return this->mousePos; }
