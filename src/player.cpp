#include <iostream>
#include "player.h"

Player::Player(int starting_health = 10, Position starting_position = 0)
: m_health(starting_health), m_position(starting_position)
{
    Item* leet = new Item(1337);
    addItem( leet );
}

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
    if(index > 0 && index < m_inventory.size())
    {
        delete m_inventory[index];
        m_inventory.erase(m_inventory.begin()+index);
    }
}

vector<Item*> Player::getInventory()
{
    vector<Item*> result;
    for(Item* it : m_inventory)
        result.push_back(it);
    return result;
}

void Player::update()
{
    //spelarens logik ligger här i
    if(m_health <= 0)
        std::cout << "You were killed unexpectedly :)\n"; // TEST
    else
    {
        //olika beteenden beroende på statusar här
        --m_health;
        if(m_health == 0)
            std::cout << "You are now dead, as expected :)\n"; // TEST
    }
}