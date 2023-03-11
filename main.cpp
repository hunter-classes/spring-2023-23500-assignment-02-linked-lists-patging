#include <iostream>
#include "OList.h"

int main()
{
  OList *l = new OList();
  l->insert("e");
  l->insert("d");
  l->insert("c");
  l->insert("b");  
  l->insert("a");

  std::cout << "Inserting e,d,c,b,a" << std::endl;
  std::cout << l->toString() << std::endl;

  std::cout << "Length of array" << std::endl;
  std::cout << l->length() << std::endl;

  std::cout << "Getting value at 1" << std::endl;
  std::cout << l->get(1) << std::endl;

  std::cout << "Removing value at 1" << std::endl;
  l->remove(1);
  std::cout << l->toString() << std::endl;  
  
  std::cout << "Does the array have P?" << std::endl;
  std::cout << (l->contains("P") ? "true" : "false") << std::endl; 

  std::cout << "Reversing the array" << std::endl;
  l->reverse();
  std::cout << l->toString() << std::endl;  

  std::cout << "Clearing the array" << std::endl;
  delete l;


  return 0;
}
