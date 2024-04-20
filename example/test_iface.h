/**
 * @file test_iface.h
 * @author Ryan Anderson <rdanderson521@gmail.com>
 * @date 20 Apr 2024
 * @copyright 2024 Ryan Anderson (AllSteady Ltd)
 * @brief <brief>
 */


#ifndef TEST_IFACE_H
#define TEST_IFACE_H


#include <memory>
#include <string>

#include "factory.h"

class TestIFace
{
public:
  struct Meta
  {
  public:
    using CreateUniquePtr = std::unique_ptr<TestIFace>(*)();
    using CreateSharedPtr = std::shared_ptr<TestIFace>(*)();

    CreateUniquePtr create;
    CreateSharedPtr createShared;
    std::string description;
  };

  TestIFace() = default;
  virtual ~TestIFace() = default;

  virtual void testFunc() =0;
};


using TestFactory = Factory<TestIFace, TestIFace::Meta>;


#endif // TEST_IFACE_H