/**
 * @file test.h
 * @author Ryan Anderson <rdanderson521@gmail.com>
 * @date 20 Apr 2024
 * @copyright 2024 Ryan Anderson (AllSteady Ltd)
 * @brief <brief>
 */

#ifndef TEST_H
#define TEST_H


#include "test_iface.h"

#include <memory>

class Test: public TestIFace
{
public:
  static std::unique_ptr<TestIFace> create() { return std::make_unique<Test>(); };
  static std::shared_ptr<TestIFace> createShared() { return std::make_shared<Test>(); };

  void testFunc() final;
  private:

  static bool isRegistered;
};


#endif // TEST_H