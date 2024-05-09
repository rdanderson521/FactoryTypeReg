/**
 * @file test.cpp
 * @author Ryan Anderson <rdanderson521@gmail.com>
 * @date 20 Apr 2024
 * @copyright 2024 Ryan Anderson (AllSteady Ltd)
 * @brief <brief>
 */


#include "test.h"

#include <iostream>


bool Test::isRegistered = TestFactory::registerType(1,
  TestIFace::Meta({
    &Test::create,
    &Test::createShared
  }));

void Test::testFunc()
{
  std::cout << "Test::testFunc" << std::endl;
}