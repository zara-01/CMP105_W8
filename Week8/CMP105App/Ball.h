#pragma once
#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"

class Ball : public GameObject
{

public:

	Ball();
	~Ball();

	void handleInput(float dt);
	void update(float dt) override;
	void collisionResponse(GameObject* Collider);

protected:

	float acceleration;

	sf::Vector2f direction;

	float speed;

	float scale;

	sf::Vector2f pointB;
	sf::Vector2f pointA;

	bool collided;
	short temp;

};

