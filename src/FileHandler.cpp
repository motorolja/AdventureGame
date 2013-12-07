#include "FileHandler.h"
#include <iostream>
#include <sstream>

using namespace std;

void FileHandler::savePlayer(const string& filename, Player player)
{
 stringstream ss;
 ios_base::openmode mode = ((m_oldFile && m_oldFilename == filename) ? ios::trunc : ios::app);
 //ios_base::openmode mode = ios::trunc;
 m_file.open(filename,ios::out | mode);

if(m_file.is_open())
{
     //Rad 1
     ss<<player.getPosition().x<<" "<<player.getPosition().y<<" "<<player.getHealth()<<"\n";

     //Rad 2 fram till items
     auto statuses = player.getStatuses(); //Vi behöver lägga till en sån funktion
     for(auto s : statuses)
        //ska dessa vara på enskilda rader?
        ss<<" "<<static_cast<unsigned>(s.m_status)<<" "<<s.m_duration;
     ss<<"\n";

     //items
     auto items = player.getInventory();
        for(auto i:items)
        {
            ss<<i.getName();
            vector<eProperty> properties = i.getProperties();
                for(auto p : properties)
                    ss<<" "<<static_cast<unsigned>(p);
            ss<<"\n";
        }

     cout<<ss.str(); //För debug
     m_file<<ss.str();

     m_file.close();
 }

}

Player FileHandler::loadPlayer(const string& filename)
{
    stringstream ss;
    string line;
    int health;
    Position pos;
    Player player;

    m_file.open(filename,ios::in );

    if(m_file.is_open())
    {
        //rad 1
        m_file>>pos.x>>pos.y>>health;
        player.setHealth(health);
        player.setPosition(pos);

        //rad 2
        getline(m_file,line);
        ss<<line;
        while(ss)
        {
            player.addStatus(deserializeStatus(ss));
        }
        ss.clear();

        //items
        while(getline(m_file,line))
        {
            ss<<line;
            player.addItem(deserializeItem(ss));
        }

        m_file.close();
    }

 return player;
}

void FileHandler::saveWorld(const string& filename, World world)
{
 ios_base::openmode mode = ((m_oldFile && m_oldFilename == filename) ? ios::trunc : ios::app);
 m_file.open(filename,ios::out | mode);

 if(m_file.is_open())
 {
     vector<Position> positions = world.getRoomPositions();

     for(int i = 0; i<positions.size(); ++i)
     {
         Room* p_room = world.getRoom(positions.at(i));
         m_file << serializeRoom(positions.at(i),p_room)<<"\n";

     }
     m_file.close();
 }
}

World FileHandler::loadWorld(const string& filename)
{
    //om m_file.load inte lyckas så returnera ett default rum på pos (0,0)
    World world;
    Position pos;
    stringstream ss;
    string room_str;
    m_file.open(filename,ios::in );

    if(m_file.is_open())
    {
        while(m_file)
        {
         m_file>>pos.x>>pos.y;
         getline(m_file,room_str,';');
         ss<<room_str;
         world.setRoom(pos,deserializeRoom(ss));
        }

        m_file.close();
        return world;
    }

    else
    {
        world.setRoom(Position(0,0),new Room("Empty Room","This room is a reflection of the emptiness in your heart"));
        return world;
    }

}


Item FileHandler::deserializeItem(stringstream& ss)
{

    string name;

    //Fungerar endast korrekt då namnet bara är ett ord
    ss>>name;
    Item item(name);
    unsigned property;

    while(ss>>property)
    {
        //ss>>property;
        item.addProperty(static_cast<eProperty>(property));
    }

    return item;

}

Status FileHandler::deserializeStatus(stringstream& ss)
{
    unsigned status;
    unsigned short duration;

    ss>>status>>duration;
    Status s(static_cast<eStatus>(status),duration);
    return s;
}

Room* FileHandler::deserializeRoom(std::stringstream& ss)
{
    stringstream oneline_ss;
    string name,description,line;
    getline(ss,name);
    getline(ss,description);
    Room* room = new Room(name,description);
    while(getline(ss,line))
    {
        oneline_ss<<line;
        room->addItem(deserializeItem(oneline_ss));
    }

    return room;
}

string FileHandler::serializeItem(const Item& item)
{
 stringstream ss;
 ss<<item.getName();
 vector<eProperty> properties = item.getProperties();
    for(auto p : properties)
        ss<<" "<<static_cast<unsigned>(p);
    return ss.str();
}

string FileHandler::serializeRoom(Position& pos,Room const* room)
{
    stringstream ss;
    //position
    ss<<pos.x<<" "<<pos.y<<"\n";

    //namn
    ss<<room->getName()<<"\n";

    //beskrivning
    ss<<room->getDescription()<<"\n";

    //items
    vector<Item> items = room->getItems();
    for(auto i : items)
    {
        ss<<serializeItem(i)<<"\n";
    }
    //avsluta rum
    ss<<";";

    return ss.str();
}
