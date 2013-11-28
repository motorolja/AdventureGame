#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <string>

enum eProperty
  {
    junk,
    edible,
    poisonous
  };

class Item
{
 public:
  Item(std::string);

  void addProperty(eProperty);
  void removeProperty(eProperty);
  void clearProperties();
  std::vector<eProperty> getProperties();
  std::string getName();
  void setName(std::string&);

 private:
  std::string m_name;
  std::vector<eProperty> m_properties;
};

#endif
