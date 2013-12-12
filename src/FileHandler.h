#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED

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

    Player loadPlayer(const std::string&);
    bool savePlayer(const std::string&,const Player&);

    World loadWorld(const std::string&);
    bool saveWorld(const std::string&,const World&);

    bool isLastLoadSucccessful() const {return m_oldFile;}
private:
    std::string serializeItem(const Item&); //save
    Item deserializeItem(std::stringstream&);  //load
    std::string serializeStatus(const Status&); //save
    Status deserializeStatus(std::stringstream&); //load (används inte just nu)
    std::string serializeRoom(Position& ,Room const* const); //save
    Room* deserializeRoom(std::stringstream&);  //load

    std::fstream m_file;
    std::string m_oldFilename;
    bool m_oldFile;
};


#endif // FILEHANDLER_H_INCLUDED
