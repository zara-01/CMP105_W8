#include "Level.h"
#include "Framework/Collision.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	ballOne.setSize(sf::Vector2f(200, 200));
	ballTwo.setSize(sf::Vector2f(200, 200));

	ballOne.setPosition(100, 100);
	ballTwo.setPosition(800, 100);

	ballOne.setTexture(&ballTexture);
	ballTwo.setTexture(&ballTexture);

	ballOne.setInput(input);
	ballTwo.setInput(input);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ballOne.handleInput(dt);
	ballTwo.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ballOne.update(dt);
	ballTwo.update(dt);

	if (Collision::checkBoundingCircle(&ballOne, &ballTwo))
	{

		ballOne.collisionResponse(NULL);
		ballTwo.collisionResponse(NULL);

	}
	

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ballOne);
	window->draw(ballTwo);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}