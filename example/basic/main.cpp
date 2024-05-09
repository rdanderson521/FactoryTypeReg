
#include <iostream>

#include "test_iface.h"

int main()
{
  std::cout << "num registered types: " << TestFactory::getNumTypes() << std::endl;
  return 0;
}