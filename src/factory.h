/**
 * @file factory.h
 * @author Ryan Anderson <rdanderson521@gmail.com>
 * @date 20 Apr 2024
 * @copyright 2024 Ryan Anderson (AllSteady Ltd)
 * @brief <brief>
 */


#ifndef BASIC_FACTORY_H
#define BASIC_FACTORY_H


#include <map>
#include <concepts>
#include <memory>
#include <type_traits>


template<class MetaType, class IFace>
concept BasicMetaClass = requires (MetaType meta)
{
  { meta.create() } ->  std::convertible_to<std::unique_ptr<IFace>>;
  { meta.createShared() } ->  std::convertible_to<std::shared_ptr<IFace>>;
};

template<class IFace, BasicMetaClass<IFace> MetaType>
class BasicFactory
{
public:
  using Meta = MetaType;

  static bool registerType(int id, const MetaType &meta);

  static int getNumTypes();

private:
  static std::map<int, MetaType> registeredFactories;
};

template<class IFace, BasicMetaClass<IFace> MetaType>
std::map<int, MetaType> BasicFactory<IFace, MetaType>::registeredFactories;

template<class IFace, BasicMetaClass<IFace> MetaType>
bool BasicFactory<IFace, MetaType>::registerType(int id, const MetaType &meta)
{
  if (BasicFactory::registeredFactories.contains(id))
  {
    return false;
  }

  BasicFactory::registeredFactories.insert_or_assign(id, meta);

  return true;
}

template<class IFace, BasicMetaClass<IFace> MetaType>
int BasicFactory<IFace, MetaType>::getNumTypes()
{
  return registeredFactories.size();
}


#endif // BASIC_FACTORY_H