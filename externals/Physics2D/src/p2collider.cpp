#include "..\include\p2collider.h"

bool p2Collider::IsSensor()
{
	return isSensor;
}

void * p2Collider::GetUserData()
{
	return userData;
}

p2Body * p2Collider::GetBody()
{
	return bodyAttached;;
}

p2Shape* p2Collider::GetShape()
{
	return shape;
}

p2Collider::p2Collider(p2ColliderDef* colliderDef,p2Body* body)
{
	
	restitution = colliderDef->restitution;
	shape = colliderDef->shape;
	isSensor = colliderDef->isSensor;
	bodyAttached = body;
	userData = colliderDef->userData;
}

p2Collider::~p2Collider()
{
	
}

