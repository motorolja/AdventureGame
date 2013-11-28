#include "item.h"
#include <algorithm>

Item::Item( std::string name ) : m_name(name)
{}

void Item::addProperty(eProperty property)
{
  if( find(m_properties.begin(), m_properties.end(), property) == m_properties.end() )
    m_properties.push_back( property );
}

void Item::removeProperty(eProperty property)
{
  auto it = find(m_properties.begin(), m_properties.end(), property);
  if( it != m_properties.end() )
    m_properties.erase( it );
}

void Item::clearProperties()
{
  m_properties.clear();
}

std::vector<eProperty> Item::getProperties()
{
  return m_properties;
}

std::string Item::getName()
{
  return m_name;
}

void Item::setName(std::string& name)
{
  m_name = name;
}
