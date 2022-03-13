#include <iostream>
#include <liba.h>
#include <libb.h>

int main()
{
  std::cout << "Calling foo" << std::endl;
  foo();
  std::cout << "Called foo" << std::endl;

  std::cout << "Calling bar" << std::endl;
  bar();
  std::cout << "Called bar" << std::endl;
  return 0;
}
