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

#include <p2contact.h>
#include <iostream>

p2Collider * p2Contact::GetColliderA()
{
	return colliderA;
}

p2Collider * p2Contact::GetColliderB()
{
	return colliderB;
}

void p2Contact::SetTouching(bool touch)
{
	touching = touch;
	
}


p2Contact::p2Contact(p2Collider * colA, p2Collider * colB):colliderA(colA),colliderB(colB)
{
}

p2Contact::~p2Contact()
{
}


bool p2Contact::isTouching()
{
	return touching;
}

bool Collision(p2AABB box1, p2AABB box2)
{
	if ((box2.bottomLeft.x >= box1.bottomLeft.x + box1.size.x)      // trop à droite
		|| (box2.bottomLeft.x + box2.size.x <= box1.bottomLeft.x) // trop à gauche
		|| (box2.topRight.y >= box1.topRight.y + box1.size.y) // trop en bas
		|| (box2.topRight.y + box2.size.y <= box1.topRight.y))  // trop en haut
		return false;
	else
		return true;
}



//Verifie si les AABB touchent et change le boolean du contact
void p2ContactManager::touch(p2Contact* contact)
{
	p2CircleShape* circle;
	p2RectShape* rectangle;
	p2Collider* colliderA = contact->GetColliderA();
	p2Collider* colliderB = contact->GetColliderB();
	if (colliderA->GetShape()->GetType() == p2Shape::shapeType::RECTANGLE)
	{
		 circle = dynamic_cast<p2CircleShape*>(colliderB->GetShape());
		 rectangle = dynamic_cast<p2RectShape*>(colliderA->GetShape());
		

	}
	else
	{
		if (colliderA->GetShape()->GetType() == p2Shape::shapeType::CIRCLE)
		{
			circle = dynamic_cast<p2CircleShape*>(colliderA->GetShape());
			rectangle = dynamic_cast<p2RectShape*>(colliderB->GetShape());
			


		}

	}
	
		bool touching = Collision(*colliderA->GetBody()->GetAABB(), *colliderB->GetBody()->GetAABB());
		contact->SetTouching(touching);
	
}

void p2ContactListener::BeginContact(p2Contact* contact)
{
	
}

void p2ContactListener::EndContact(p2Contact* contact)
{
}


