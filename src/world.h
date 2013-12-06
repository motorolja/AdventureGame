#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <string>
#include <map>
#include "position.h"
#include "room.h"

class World
{
public:
	World();
	~World();
	
	void clear();
	void setRoom(Position position, Room *room);
	void removeRoom(Position position);
	std::vector<std::string> getRoomNames() const
	{
		std::vector<std::string> names;
		for(auto it = m_rooms.begin(); it != m_rooms.end(); it++)
		{
			names.push_back( it->second->getName() );
		}
		return names;
	}
	std::vector<Position> getRoomPositions() const
	{
		std::vector<Position> positions;
		for(auto it = m_rooms.begin(); it != m_rooms.end(); it++)
		{
			positions.push_back( it->first );
		}
		return positions;
	}
	Room* getRoom(Position position) const
	{
		return m_rooms[position];
	}
	bool hasRoom(Position position) const
	{
		auto it = m_rooms.find( position );
		if(it != m_rooms.end())
			return true;
		return false;
	}
private:
	std::map<Position, Room*> m_rooms;
};

#endif