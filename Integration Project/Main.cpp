#include <iostream>
#include <string>
#include <math.h>
#include <hero.h>
#include <enemy.h>
#include <GameWindow.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

// Function Prototypes
float calcTheta(sf::Vector2f Mouse_Position);
void moveEnemy(sf::CircleShape* Hero, sf::CircleShape* enemy);

int main()
{
	/* Game Initialization*/

	// Create Window
	GameWindow gameWindow;
	sf::RenderWindow* window = &gameWindow;
	sf::Event gameEvent; // Game event obect
	//sf::Clock game_time; // Game clock started
	//sf::Time elapsed = game_time.getElapsedTime(); // Gather time elapsed


	/* Object initialization*/
	//hero Rambo(&window);
	// The hero of the adventure
	//hero Rambo(window_w, window_h);

	// Bullet
	//float bulletToTarget;
	//sf::RectangleShape bullet(sf::Vector2f(1.f, bulletToTarget));


	// Enemy creation
	//srand(time(0));
	//int randomPosX = rand() % static_cast<int>(window_w);
	//int randomPosY = rand() % static_cast<int>(window_h);
	//sf::CircleShape enemy1(35.f);
	//enemy1.setFillColor(sf::Color::Red);
	//enemy1.setOrigin(enemy1.getRadius(), enemy1.getRadius());
	//enemy1.setPosition(randomPosX, randomPosY);

	
	// Main loop
	while (gameWindow.isOpen()) //!window->isOpen()
	{
		
		// Loop checks for an event
		while (gameWindow.pollEvent()) //window->pollEvent(gameEvent)
		{
			switch (sf::Event::EventType())
			{
			// window closed
			case sf::Event::Closed:
				gameWindow.close();
				break; 
			case sf::Event::MouseButtonPressed:
				//std::cout << "Mouse X: " << window.mousePosition().x << " Mouse Y: " << window.mousePosition().y << "\n";
				//std::cout << "Enemy X: " << enemy1.getPosition().x << "Enemy X: " << enemy1.getPosition().y << "\n";
				//std::cout << "Time elapsed since game started: " << elapsed.asSeconds() << "\n";
				//std::cout << "Theta = " << calcTheta(window.mousePosition()) << "\n";
				//std::cout << "\n";
				break;

			default:
				break;
			}
		}
		
		gameWindow.update(); // Clear current frame and makes background white

		// Update Rotation of gun to point towards the mouse
		//rotation = calcTheta(window.mousePosition());
		//gun.setRotation(rotation);

		// Move enemy towards Hero
		//moveEnemy(&hero, &enemy1);

		// Draw shapes to the screen for new frame
		//Rambo.draw(window);
		//window.draw(hero);
		//window.draw(gun);
		//window.draw(enemy1);
		//window.draw(heroBounds);

		// Display new window frame
		gameWindow.showGame();
	}

	return 0;
}

// Function Defs

// Moves enemy towards player
void moveEnemy(sf::CircleShape* Hero, sf::CircleShape* enemy)
{
	sf::Vector2f hero_XY = Hero->getPosition();
	sf::Vector2f enemy_XY = enemy->getPosition();
	// Enemy in Q1 (Right)
	if (enemy_XY.x > hero_XY.x && enemy_XY.y < hero_XY.y)
		enemy->move(-1.f, 1.f);
	
	// Enemy in Q2 (Right)
	if (enemy_XY.x > hero_XY.x && enemy_XY.y > hero_XY.y)
		enemy->move(-1.f, -1.f);
	
	// Enemy in Q3 (Left)
	if (enemy_XY.x < hero_XY.x && enemy_XY.y > hero_XY.y)
		enemy->move(1.f, -1.f);
	
	// Enemy in Q4 (Left)
	if (enemy_XY.x < hero_XY.x && enemy_XY.y < hero_XY.y)
		enemy->move(1.f, 1.f);

	// straight above
	if (enemy_XY.x == hero_XY.x && enemy_XY.y < hero_XY.y)
		enemy->move(0.f, 1.f);

	// Straight below
	if (enemy_XY.x == hero_XY.x && enemy_XY.y > hero_XY.y)
		enemy->move(0.f, -1.f);
	
	// Straight left
	if (enemy_XY.x < hero_XY.x && enemy_XY.y == hero_XY.y)
		enemy->move(1.f, 0.f);

	// Straight right
	if (enemy_XY.x > hero_XY.x && enemy_XY.y == hero_XY.y)
		enemy->move(-1.f, 0.f);
}

// Calculates rotational angle for gun relative to mouse
float calcTheta(sf::Vector2f Mouse_Position)
{
	double theta;
	// Quadrant 1
	if (Mouse_Position.x > 400 && Mouse_Position.y < 300)
		return static_cast<float>(theta = atan((Mouse_Position.x - 400) / (300 - Mouse_Position.y)) * (180 / 3.14));
	// Quadrant 2
	if (Mouse_Position.x > 400 && Mouse_Position.y > 300)
		return static_cast<float>(theta = 90 + atan((Mouse_Position.y - 300) / (Mouse_Position.x - 400)) * (180 / 3.14));
	// Quadrant 3
	if (Mouse_Position.x < 400 && Mouse_Position.y> 300)
		return static_cast<float>(theta = 180 + atan((400 - Mouse_Position.x) / (Mouse_Position.y - 300)) * (180 / 3.14));
	// Quadrant 4
	if (Mouse_Position.x < 400 && Mouse_Position.y < 300)
		return static_cast<float>(theta = 270 + atan((300 - Mouse_Position.y) / (400 - Mouse_Position.x)) * (180 / 3.14));
}
