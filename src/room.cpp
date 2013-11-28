#include "room.h"

using std::string;
using std::vector;

Room::Room(string name, string description)
 : m_name(name), m_description(description)
{
}

void Room::addItem(Item item)
{
	m_items.push_back(item);
}

void Room::removeItem(int index)
{
	if(index >= 0 && index < m_items.size())
		m_items.erase(m_items.begin() + index);
	//else throw exception?
}

void Room::setName(string name)
{
	m_name = name;
}

void Room::setDescription(string description)
{
	m_description = description;
}