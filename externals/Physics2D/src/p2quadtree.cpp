#include "..\include\p2quadtree.h"
#include "SFML\Graphics.hpp"

p2QuadTree::p2QuadTree(int nodeLevel, p2AABB bounds):m_NodeLevel(nodeLevel),m_Bounds(bounds)
{
	
}

p2QuadTree::~p2QuadTree()
{
}

void p2QuadTree::Clear()
{
	
	for each (p2Body* object in m_Objects)
	{
		delete(object);
	}

	m_Objects.clear();
}

void p2QuadTree::Split()
{

		for (int i = 0; i <4; i++)
		{
			p2AABB bounds;
			if (i == 0)
			{
				bounds = p2AABB(m_Bounds.GetCenter() / 2.f, m_Bounds.GetSize() / 2.f);
			}
			else
			{
				if (i == 1)
				{
					bounds = p2AABB(m_Bounds.GetCenter() + m_Bounds.GetCenter() / 2.f, m_Bounds.GetSize() / 2.f);
				}
				else
				{
					if (i == 2)
					{
						bounds = p2AABB(p2Vec2(m_Bounds.GetCenter().x / 2.f, m_Bounds.GetCenter().y/2.f + m_Bounds.GetCenter().y / 2.f), m_Bounds.GetSize() / 2.f);
					}
					else
					{
						if (i == 3)
						{
							bounds = p2AABB(p2Vec2(m_Bounds.GetCenter().x / 2.f + m_Bounds.GetCenter().x / 2.f, m_Bounds.GetCenter().y / 2.f + m_Bounds.GetCenter().y / 2.f), m_Bounds.GetSize() / 2.f);
						}
					}
				}
			}
			
				nodes[i] = new p2QuadTree(m_NodeLevel,bounds);
				
		}

	m_NodeLevel++;
}

int p2QuadTree::GetIndex(p2Body * rect)
{
	return m_NodeLevel;
}

void p2QuadTree::Insert(p2Body * obj)
{
	m_Objects.push_back(obj);
}

std::list<p2Body*> p2QuadTree::Retrieve()
{
	return m_Objects;
}

void p2QuadTree::Update(float dt)
{
	
	if (m_Objects.size() > MAX_OBJECTS)
	{
		Split();
	}
	

}
