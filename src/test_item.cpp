#include <iostream>
#include "item.h"

int main()
{
  eProperty ed = edible;
  eProperty ju = junk;
  Item i;
  Item p("blingThing");
  std::cout << i.getName() << std::endl;
  std::vector<eProperty> v;
  p.addProperty(ed);
  std::cout << "Lägger till: edible" << std::endl;
  v = p.getProperties();
  for(int i = 0; i < v.size(); ++i)
    std::cout << v.at(i) << std::endl;

  std::cout << "Lägger till: edible, inget ska hända" << std::endl;
  p.addProperty(ed);
  v = p.getProperties();
  for(int i = 0; i < v.size(); ++i)
    std::cout << v.at(i) << std::endl;

  std::cout << "Lägger till: junk" << std::endl;
  p.addProperty(ju);
  v = p.getProperties();
  for(int i = 0; i < v.size(); ++i)
    std::cout << v.at(i) << std::endl;

  std::cout << "Tar bort edible" << std::endl;
  p.removeProperty(ed);
  v = p.getProperties();
  for(int i = 0; i < v.size(); ++i)
    std::cout << v.at(i) << std::endl;

  std::cout << "Tömmer" << std::endl;
  p.clearProperties();
  v = p.getProperties();
  for(int i = 0; i < v.size(); ++i)
    std::cout << v.at(i) << std::endl;

  std::cout << "Hämtar blingThing" << std::endl;
  std::cout << p.getName() << std::endl;

  std::string s = "ofc my horse";
  std::cout << "sätter name till: " << s << std::endl;
  p.setName( s );
  std::cout << p.getName() << std::endl;

  return 0;
}
