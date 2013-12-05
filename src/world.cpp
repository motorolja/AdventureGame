#include "world.h"

using namespace std;

World::World()
{}

World::~World()
{
	clear();
}

void World::clear()
{
	for(auto it = m_rooms.begin();it != m_rooms.end();++it)
	{
		delete it->second;
	}
	m_rooms.clear();
}

void World::setRoom(Position position, Room room)
{
	if(m_rooms[position] != nullptr)
		delete m_rooms[position];
	m_rooms[position] = room;
}

void World::removeRoom(Position position)
{
	delete m_rooms[position];
	m_rooms.erase( position );
}