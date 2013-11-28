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
	World()
	{
		//
	}
	~World()
	{
		//
	}
	
	void clear();
	void setRoom(Position position, Room room);
	void removeRoom(Position position);
	std::vector<std::string> getRoomNames() const
	{
		//
	}
	std::vector<Position> getRoomPositions() const
	{
		//
	}
	Room getRoom(Position position) const
	{
		return m_rooms[position];
	}
	bool hasRoom(Position) const
	{
		//
	}
private:
	std::map<Position, Room> m_rooms;
};

#endif