#ifndef DEF_STRINGS_H
#define DEF_STRINGS_H

#include <string>
#include <unordered_map>
#include "message.h"

/**
unordered_multimap för att lagra standardsträngarna för varje kommandon.
Vissa kommandon kommer att ha 2 olika standardsträngarna(om kommandot
lyckades eller inte).

ännu inte färdig
**/
 std::unordered_multimap<int,std::string> defaultstrings{
{EngineMessage::help,"Player Commands: _list, go, eat, _throw, take, save Create World: makeroom, make, _delete, destroy, jump, rooms"},
{EngineMessage::_list,"Your inventory: "}, //specialfall
{EngineMessage::go,"You go <arg1>"}, // <arg1> är argumentet som ska kompletteras, ex: You go west
{EngineMessage::go,"You can´t go that direction!"},
{EngineMessage::eat,"You´re eating <arg1>"},
{EngineMessage::eat,"You can´t eat That! You crazy?"},
{EngineMessage::_throw,"You threw <arg1>"},
{EngineMessage::_throw,"You can´t throw that item!"},
{EngineMessage::take,"You got this item: <arg1>"},
{EngineMessage::take,"You can´t take this item!"},
{EngineMessage::unknown,"Invalid command"}// Default Message string
//{EngineMessage::none,"testing2"}
};

#endif
