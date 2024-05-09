/**
 * @file overloaded_factory.h
 * @author Ryan Anderson <rdanderson521@gmail.com>
 * @date 09 May 2024
 * @copyright 2024 Ryan Anderson (AllSteady Ltd)
 * @brief <brief>
 */


#ifndef OVERLOADD_FACTORY_H
#define OVERLOADD_FACTORY_H


#include <concepts>
#include <type_traits>
#include <memory>
#include <string>

#include "factory.h"


template<class MetaType, class IFace>
concept OverloadedMetaClass = requires (MetaType meta)
{
  { meta.description } -> std::convertible_to<std::string>;

  requires BasicMetaClass<MetaType, IFace>;
};

template<class IFace, OverloadedMetaClass<IFace> MetaType>
using OverloadedFactory = BasicFactory<IFace, MetaType>;


#endif // OVERLOADD_FACTORY_H