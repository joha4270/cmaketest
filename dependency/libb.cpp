//
// Created by joha on 13/03/2022.
//

#include <iostream>

#include "liba.h"
#include "libb.h"

void bar()
{
  std::cout << "In bar" << std::endl;
  foo();
}