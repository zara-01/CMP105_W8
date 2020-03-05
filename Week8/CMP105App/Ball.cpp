#include "Ball.h"
#include "Framework/Vector.h"

Ball::Ball()
{

	scale = 200.0f;
	speed = 10.0f;


	direction = sf::Vector2f();
	scale = 21;

}

Ball::~Ball() {}



void Ball::handleInput(float dt)
{

	//move up
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		move(0, -50 * dt);
	}

	//move down
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		move(0, 50 * dt);
	}

	//move left
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		move(-50 * dt, 0);
	}

	//move right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		move(50 * dt, 0);
	}

}

void Ball::update(float dt)
{

	move(speed * dt, speed * dt);

	pointA = sf::Vector2f(getPosition().x, getPosition().y);
	pointB = sf::Vector2f(input->getMouseX(), input->getMouseY());

	speed += 2 * dt;

	direction = pointB - pointA;
	direction = Vector::normalise(direction);
	if (!collided && temp > 120) 
	{
		velocity = (direction * speed) * scale;
	}
	setPosition(getPosition() + (velocity * dt));
	collided = false;
	temp += 1;
	

	move(velocity * dt);

	if (Vector::magnitude(pointB - getPosition()) <= 2.f)
	{
		setPosition(pointB);
		speed = 0;
	}


}


void Ball::collisionResponse(GameObject* Collider)
{

	velocity = -velocity;
	collided = true;
	temp = 0;

}
