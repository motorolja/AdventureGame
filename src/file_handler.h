1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 	

#ifndef FILE_HANDLER_H_INCLUDED
#define FILE_HANDLER_H_INCLUDED

#include <fstream>
#include <sstream>
#include <vector>
#include "player.h"
#include "world.h"


class FileHandler
{
public:
    ~FileHandler() = default;
    FileHandler(const std::string& filename) : m_file(),m_oldFilename(filename),m_oldFile(false){}

    void loadPlayer(const std::string&,Player&);
    bool savePlayer(const std::string&,const Player&);

    void loadWorld(const std::string&,World&);
    bool saveWorld(const std::string&,const World&);

private:
    std::string serializeItem(const Item&); //save
    Item deserializeItem(std::stringstream&); //load
    std::string serializeStatus(const Status&); //save
    //Status deserializeStatus(std::stringstream&); //load (används inte just nu)
    std::string serializeRoom(Position& ,Room const* const); //save
    Room* deserializeRoom(std::stringstream&); //load

    std::fstream m_file;
    std::string m_oldFilename;
    //const std::string player_extension = ".Player";
    //const std::string world_extension= ".World";
    bool m_oldFile;
};


#endif // FILE_HANDLER_H_INCLUDED
