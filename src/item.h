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
  Item( std::string name = "no item");

  void addProperty(eProperty);
  void removeProperty(eProperty);
  void clearProperties();
  std::vector<eProperty> getProperties() const;
  std::string getName() const;
  void setName(std::string&);

 private:
  std::string m_name;
  std::vector<eProperty> m_properties;
};

#endif
