/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <p2world.h>
#include <ctime>
#include <cmath>
#include <SFML\Graphics.hpp>
#include <iostream>

p2World::p2World(p2Vec2 gravity): m_Gravity(gravity)
{

}

p2World::~p2World()
{
	for (p2Contact* contact : contacts)
	{
		delete(contact);
	}
	for (p2Body* body : bodies)
	{
		delete(body);
	}
	contacts.empty();
	bodies.empty();

}


void p2World::Step(float dt)
{
	//test_contact(dt);
	
		
	
}

p2Body * p2World::CreateBody(p2BodyDef* bodyDef)
{
	p2Body* body = new p2Body(bodyDef);
	bodies.push_back(body);
	return body;
}

void p2World::SetContactListener(p2ContactListener * contactListener)
{
	listener=contactListener;
}


void p2World::test_contact(float dt)
{
	p2Body* circle = nullptr;
	p2Body* rectangle = nullptr;
	//Move bodies
	int i = 0;
	while (i < bodies.size())
	{
		if (bodies[i]->GetType() == p2BodyType::DYNAMIC)
		{

			circle = bodies[i];


		}
		else
		{
			if (bodies[i]->GetType() == p2BodyType::STATIC)
			{

				rectangle = bodies[i];
			}
		}

		i++;
	}

	if (circle != nullptr&&rectangle != nullptr)
	{

		for (p2Collider* collider : circle->GetColliders())
		{
			for (p2Collider* collider2 : rectangle->GetColliders())
			{
				p2Contact* contact = new p2Contact(collider, collider2);
				p2ContactManager* contactManager = new p2ContactManager;
				contactManager->touch(contact);

				if (contact->isTouching())
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						// left key is pressed: move our character
						circle->SetPosition(p2Vec2(circle->GetLinearVelocity()*dt) + circle->GetPosition());
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						circle->SetPosition(p2Vec2(circle->GetLinearVelocity()*dt) + circle->GetPosition());
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						circle->SetPosition(p2Vec2(circle->GetLinearVelocity()*dt) + circle->GetPosition());
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						circle->SetPosition(p2Vec2(circle->GetLinearVelocity()*dt) + circle->GetPosition());
					}

					if (!enter)
					{
						listener->BeginContact(contact);
						enter = true;
						exit = false;
					}

				}
				else
				{

					if (enter && !exit)
					{
						listener->EndContact(contact);
						enter = false;
						exit = true;
					}
					//Gravity: 
					//circle->SetPosition(p2Vec2(circle->GetLinearVelocity().x, circle->GetLinearVelocity().y + dt) + circle->GetPosition());
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						// left key is pressed: move our character
						circle->SetPosition(p2Vec2(circle->GetLinearVelocity()*dt) + circle->GetPosition());
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						circle->SetPosition(p2Vec2(circle->GetLinearVelocity()*dt) + circle->GetPosition());
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						circle->SetPosition(p2Vec2(circle->GetLinearVelocity()*dt) + circle->GetPosition());
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						circle->SetPosition(p2Vec2(circle->GetLinearVelocity()*dt) + circle->GetPosition());
					}

				}
				delete(contact);
				delete(contactManager);
			}
		}

	}
}


