/**
 * @file factory.h
 * @author Ryan Anderson <rdanderson521@gmail.com>
 * @date 20 Apr 2024
 * @copyright 2024 Ryan Anderson (AllSteady Ltd)
 * @brief <brief>
 */


#ifndef FACTORY_H
#define FACTORY_H


#include <map>
#include <string>
#include <concepts>
#include <type_traits>
#include <iostream>


template<class MetaType, class IFace>
concept MetaClass = requires (MetaType meta)
{
  { meta.create() } ->  std::convertible_to<std::unique_ptr<IFace>>;
  { meta.createShared() } ->  std::convertible_to<std::shared_ptr<IFace>>;
  { meta.description } ->  std::convertible_to<std::string>;
};

template<class IFace, MetaClass<IFace> MetaType>
class Factory
{
public:
  static bool registerType(int id, const MetaType &meta);

  static int getNumTypes();

private:
  static std::map<int, MetaType> registeredFactories;
};

template<class IFace, MetaClass<IFace> MetaType>
std::map<int, MetaType> Factory<IFace,MetaType>::registeredFactories;

template<class IFace, MetaClass<IFace> MetaType>
bool Factory<IFace,MetaType>::registerType(int id, const MetaType &meta)
{
  if (Factory::registeredFactories.contains(id))
  {
    std::cout << "id: " << id << " already registered" << std::endl;
    return false;
  }

  std::cout << "id: " << id << " metaDesc: " << meta.description << std::endl;
  Factory::registeredFactories.insert_or_assign(id, meta);

  return true;
}

template<class IFace, MetaClass<IFace> MetaType>
int Factory<IFace,MetaType>::getNumTypes()
{
  std::cout << "size: " << registeredFactories.size() << std::endl;
  return registeredFactories.size();
}


#endif // FACTORY_H