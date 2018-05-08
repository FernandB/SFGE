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

//Verifie si les AABB touchent et change le boolean du contact
void p2ContactManager::touch(p2Contact* contact)
{
	p2Collider* colliderA = contact->GetColliderA();
	p2Collider* colliderB = contact->GetColliderB();
	if (colliderA->GetShape()->GetType() == p2Shape::shapeType::RECTANGLE)
	{
		p2CircleShape* circle = dynamic_cast<p2CircleShape*>(colliderB->GetShape());
		
		float x = fmax(colliderA->GetBody()->GetAABB().bottomLeft.x, fmin(colliderB->GetBody()->GetAABB().GetCenter().x, colliderA->GetBody()->GetAABB().topRight.x));
		float y = fmax(colliderA->GetBody()->GetAABB().bottomLeft.y, fmin(colliderB->GetBody()->GetAABB().GetCenter().y, colliderA->GetBody()->GetAABB().topRight.y));

		float distance = sqrt((x - colliderB->GetBody()->GetAABB().GetCenter().x) * (x - colliderB->GetBody()->GetAABB().GetCenter().x) +
			(y - colliderB->GetBody()->GetAABB().GetCenter().y) * (y - colliderB->GetBody()->GetAABB().GetCenter().y));

		bool touching = distance < circle->GetRadius();
		contact->SetTouching(touching);
	}
	else
	{
		if (colliderA->GetShape()->GetType() == p2Shape::shapeType::CIRCLE)
		{
			p2CircleShape* circle = dynamic_cast<p2CircleShape*>(colliderA->GetShape());
			float x = fmax(colliderB->GetBody()->GetAABB().bottomLeft.x, fmin(colliderA->GetBody()->GetAABB().GetCenter().x, colliderB->GetBody()->GetAABB().topRight.x));
			float y = fmax(colliderB->GetBody()->GetAABB().bottomLeft.y, fmin(colliderA->GetBody()->GetAABB().GetCenter().y, colliderB->GetBody()->GetAABB().topRight.y));

			float distance = sqrt((x - colliderA->GetBody()->GetAABB().GetCenter().x) * (x - colliderA->GetBody()->GetAABB().GetCenter().x) +
				(y - colliderA->GetBody()->GetAABB().GetCenter().y) * (y - colliderA->GetBody()->GetAABB().GetCenter().y));


			bool touching = distance < circle->GetRadius();
			contact->SetTouching(touching);
		}

	}
	
}

void p2ContactListener::BeginContact(p2Contact* contact)
{
	
}

void p2ContactListener::EndContact(p2Contact* contact)
{
}


