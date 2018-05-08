#include "..\include\p2quadtree.h"
#include "SFML\Graphics.hpp"

p2QuadTree::p2QuadTree(int nodeLevel, p2AABB bounds):m_NodeLevel(nodeLevel),m_Bounds(bounds)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	sf::Vertex line[4];
	line[0].position = sf::Vector2f(m_Bounds.bottomLeft.x, m_Bounds.bottomLeft.y);
	line[0].color = sf::Color::Blue;
	line[1].position = sf::Vector2f(m_Bounds.bottomLeft.x, m_Bounds.topRight.y);
	line[1].color = sf::Color::Blue;
	line[2].position = sf::Vector2f(m_Bounds.topRight.x, m_Bounds.topRight.y);
	line[2].color = sf::Color::Blue;
	line[3].position = sf::Vector2f(m_Bounds.topRight.x, m_Bounds.bottomLeft.y);
	line[3].color = sf::Color::Blue;
	
	window.draw(line, 4, sf::Lines);
}

p2QuadTree::~p2QuadTree()
{
}

void p2QuadTree::Clear()
{
}

void p2QuadTree::Split()
{
}

int p2QuadTree::GetIndex(p2Body * rect)
{
	return 0;
}

void p2QuadTree::Insert(p2Body * obj)
{
}

std::list<p2Body*> p2QuadTree::Retrieve()
{
	return m_Objects;
}
