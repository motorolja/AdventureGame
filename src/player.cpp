#include <iostream>
#include "player.h"
#include <algorithm>
#include <stdexcept>

Status::Status(eStatus status, unsigned short duration): m_status(status), m_duration(duration)
{}

Player::Player(int starting_health, Position starting_position)
: m_health(starting_health), m_position(starting_position)
{}

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
    //l�gg till koll om statusen redan finns
    m_statuses.push_back(status);
}

void Player::clearStatus()
{
    //ta bort hela status vektorn
    m_statuses.clear();    // "Status" inneh�ller inte pekare
}

std::vector<Status> Player::getStatuses() const
{
    return m_statuses;
}

void Player::setPosition(Position position)
{
    m_position = position;
}

Position Player::getPosition() const
{
    return m_position;
}

void Player::addItem(Item item)
{
    m_inventory.push_back(item);
}

void Player::removeItem(int index)
{
  if(index >= 0 && index < m_inventory.size())
      m_inventory.erase(m_inventory.begin()+index);
  else
      throw std::out_of_range("Player::removeItem: No item to remove");
  // kanske kasta ett exception om f�rem�let inte fanns
}

std::vector<Item> Player::getInventory() const
{
    return m_inventory;
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
	  if(m_health >= 1)
	    --m_health;
	  break;
	default:
	  break;
	}
    }

  for( int i = 0; i < m_statuses.size(); ++i )
      --m_statuses.at(i).m_duration;

  if( m_health != 0 )
    --m_health;
}
