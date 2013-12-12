1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 150 151 152 153 154 155 156 157 158 159 160 161 162 163 164 165 166 167 168 169 170 171 172 173 174 175 176 177 178 179 180 181 182 183 184 185 186 187 188 189 190 191 192 193 194 195 196 197 198 199 200 201 202 203 204 205 206 207 208 209 210 211 212 213 214 215 216 217 218 219 220 221 222 223 224 225 226 227 228 229 230 231 232 233 234 235 	

#include "file_handler.h"
#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

bool FileHandler::savePlayer(const string& filename,const Player& player)
{
 stringstream ss;
 //ios_base::openmode mode = ((m_oldFile && m_oldFilename == filename) ? ios::trunc : ios::app);
 ios_base::openmode mode = ios::trunc;
 m_file.open(filename,ios::out | mode);

if(m_file.is_open())
{
     //Rad 1
     ss<<player.getPosition().x<<" "<<player.getPosition().y<<" "<<player.getHealth()<<"\n";

     //Rad 2 fram till items
     auto statuses = player.getStatuses();
     for(auto s : statuses)
        ss<<serializeStatus(s);
     ss<<"\n";

     //items
     auto items = player.getInventory();
        for(auto i:items)
        {
            ss<<serializeItem(i);
            ss<<"\n";
        }

     cout<<ss.str(); //För debug
     m_file<<ss.str();

     m_file.close();
     return true;
 }

 return false;
}

void FileHandler::loadPlayer(const string& filename,Player& player)
{
    stringstream ss;
    string line;
    int health;
    unsigned stat;
    unsigned duration;
    Position pos;
    //Player player;

    m_file.open(filename,ios::in );

    if(m_file.is_open())
    {
        //rad 1
        getline(m_file,line);
        ss<<line;
        ss>>pos.x>>pos.y>>health;
        player.setHealth(health);
        player.setPosition(pos);
        ss.clear();

        //rad 2
        getline(m_file,line);
        ss<<line;
        while(ss>>stat>>duration)
        {
            Status s(static_cast<eStatus>(stat),duration);
            player.addStatus(s);
        }
        ss.clear();

        //items
        while(getline(m_file,line))
        {
            //getline(m_file,line);
            ss<<line<<"\n";
            getline(m_file,line);
            ss<<line<<"\n";
            player.addItem(deserializeItem(ss));
            ss.clear();
        }

        m_file.close();
    }

 //return player;
}

bool FileHandler::saveWorld(const string& filename,const World& world)
{
 //ios_base::openmode mode = ((m_oldFile && m_oldFilename == filename) ? ios::trunc : ios::app);
 ios_base::openmode mode = ios::trunc;
 m_file.open(filename,ios::out | mode);

 stringstream ss;

 if(m_file.is_open())
 {
     vector<Position> positions = world.getRoomPositions();

     for(int i = 0; i<positions.size(); ++i)
     {
         Room* p_room = world.getRoom(positions.at(i));
         ss << serializeRoom(positions.at(i),p_room)<<"\n";

     }
     m_file<<ss.str();
     cout<<ss.str()<<"\n"; //debug
     m_file.close();
     return true;
 }
 return false;
}

void FileHandler::loadWorld(const string& filename, World& world)
{
    Position pos;
    //stringstream ss;
    string room_str;
    m_file.open(filename,ios::in );

    if(m_file.is_open())
    {
        while(m_file)
        {
         m_file>>pos.x>>pos.y>>ws;
         getline(m_file,room_str,';');
         stringstream ss(room_str);
         world.setRoom(pos,deserializeRoom(ss));
        }

        m_file.close();

    }

    else
    {
        world.setRoom(Position(0,0),new Room("Empty Room","This room is a reflection of the emptiness in your heart"));
    }

}


Item FileHandler::deserializeItem(stringstream& ss)
{

    string name;

    getline(ss,name);
    Item item(name);
    unsigned property;

    while(ss>>property)
    {
        //ss>>property;
        item.addProperty(static_cast<eProperty>(property));
    }
    ss.clear();

    return item;

}

/*Status FileHandler::deserializeStatus(stringstream& ss)
{
unsigned status;
unsigned short duration;

ss>>status>>duration;
Status s(static_cast<eStatus>(status),duration);
return s;
}*/

std::string FileHandler::serializeStatus(const Status& status)
{
    stringstream ss;
    ss<<static_cast<unsigned>(status.m_status)<<" "<<status.m_duration<<" ";
    return ss.str();
}

Room* FileHandler::deserializeRoom(std::stringstream& ss)
{
    stringstream item_ss;
    string name,description,line;
    getline(ss,name);
    getline(ss,description);
    Room* room = new Room(name,description);
    while(getline(ss,line))
    {
        item_ss<<line<<"\n";
        getline(ss,line);
        item_ss<<line<<"\n";
        room->addItem(deserializeItem(item_ss));
    }

    return room;
}

string FileHandler::serializeItem(const Item& item)
{
 stringstream ss;
 ss<<item.getName()<<"\n";
 vector<eProperty> properties = item.getProperties();
    for(auto p : properties)
        ss<<static_cast<unsigned>(p)<<" ";
    return ss.str();
}

string FileHandler::serializeRoom(Position& pos,Room const* const room)
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
