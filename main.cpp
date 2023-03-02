#include <iostream>
#include "List.h"

int main()
{
  List *l = new List();
  l->insert(0, "Zero");
  l->insert(1, "One");
  l->insert(2, "Two");

  // testing new funcs
  std::cout << l->toString() << std::endl;

  std::cout << "At index 2 : " << l->get(2) << std::endl;

  std::cout << "Does \"Four\" exist in " << l->toString() << " " << l->contains("Four") << std::endl;

  std::cout << "Does \"Two\" exist in " << l->toString() << " " << l->contains("Two") << std::endl;

  std::cout << "removing at index 1" << std::endl;

  std::cout << "Before " << l->toString() << std::endl;
  l->remove(1);

  std::cout << "After " << l->toString() << std::endl;

  return 0;
}
