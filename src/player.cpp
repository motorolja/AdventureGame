#include <iostream>
#include "player.h"
#include <algorithm>
#include <stdexcept>

Status::Status(eStatus status, unsigned short duration): m_status(status), m_duration(duration)
{}

Player::Player(int starting_health, Position starting_position)
: m_health(starting_health), m_position(starting_position)
{}

Player::~Player()
{
    //ta bort vektorer
    for(auto it = m_inventory.begin(); it != m_inventory.end(); it++)
    {
        delete *it;
    } 
    m_inventory.clear();
}

int Player::getHealth() const
{
    return m_health;
}

void Player::setHealth(int health)
{
    m_health = health;
}

void Player::addStatus(Status status)
{
    //lägg till koll om statusen redan finns
    m_statuses.push_back(status);
}

void Player::clearStatus()
{
    //ta bort hela status vektorn
    m_statuses.clear();    // "Status" innehåller inte pekare
}

void Player::setPosition(Position position)
{
    m_position = position;
}

Position Player::getPosition() const
{
    return m_position;
}

void Player::addItem(Item* item)
{
    m_inventory.push_back(item);
}

void Player::removeItem(int index)
{
  if(index >= 0 && index < m_inventory.size())
    {
      delete m_inventory.at(index);
      m_inventory.erase(m_inventory.begin()+index);
    }
  else
      throw std::out_of_range("Player::removeItem: No item to remove");
  // kanske kasta ett exception om föremålet inte fanns
}

std::vector<Item*> Player::getInventory()
{
    std::vector<Item*> result;
    for(Item* it : m_inventory)
        result.push_back(it);
    return result;
}

void Player::update()
{
  // tar bort de element som har m_duration == 0
  m_statuses.erase( std::remove_if(m_statuses.begin(), m_statuses.end(),
				   [](Status s) -> bool{return s.m_duration == 0;} )
		    , m_statuses.end() );
  
  for( int i = 0; i < m_statuses.size(); i++ )
    {
      switch ( m_statuses.at(i).m_status )
	{
	case poisoned:
	  --m_health;
	  break;
	default:
	  break;
	}
    }

  for( int i = 0; i < m_statuses.size(); ++i )
      --m_statuses.at(i).m_duration;

  --m_health;
}
