#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <string>
#include "position.h"
#include "item.h"

class Room
{
public:
	Room(std::string name = "The Void", std::string description = "this is wrong");
	void addItem(Item item);
	void removeItem(int index);
	void setName(std::string name);
	void setDescription(std::string description);
	std::string getName() const
	{
		return m_name;
	}
	std::string getDescription() const
	{
		return m_description;
	}
	std::vector<Item> getItems() const
	{
		return m_items;
	}
private:
	std::vector<Item> m_items;
	std::string		  m_name;
	std::string		  m_description;
};

#endif