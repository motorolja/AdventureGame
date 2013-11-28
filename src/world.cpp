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
	m_rooms.clear();
}

void World::setRoom(Position position, Room room)
{
	m_rooms[position] = room;
}

void World::removeRoom(Position position)
{
	m_rooms.erase( position );
}