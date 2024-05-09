/**
 * @file factory_registration.h
 * @author Ryan Anderson <rdanderson521@gmail.com>
 * @date 09 May 2024
 * @copyright 2024 Ryan Anderson (AllSteady Ltd)
 * @brief <brief>
 */


#ifndef FACTORY_REGISTRATION_H
#define FACTORY_REGISTRATION_H


#include <concepts>
#include <memory>
#include <type_traits>



template<class FactoryType>
concept FactoryClass = requires (FactoryType factory)
{
  { FactoryType::registerType(int(), typename FactoryType::Meta()) } -> std::convertible_to<bool>;
};


template<FactoryClass FactoryType>
class FactoryRegistration
{
public:
  FactoryRegistration(int id, const typename FactoryType::Meta &meta);

  bool sucessful() const;

private:
  bool sucess = false;
};


template<FactoryClass FactoryType>
FactoryRegistration<FactoryType>::FactoryRegistration(int id, const typename FactoryType::Meta &meta)
{
  this->sucess = FactoryType::registerType(id, meta);
}



#endif // FACTORY_REGISTRATION_H