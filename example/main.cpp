
#include <iostream>

#include "test_iface.h"

int main()
{
  std::cout << "main" << std::endl;

  TestFactory::getNumTypes();
  return 0;
}