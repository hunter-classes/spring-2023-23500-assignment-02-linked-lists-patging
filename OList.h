#pragma once
#include <iostream>
#include "Node.h"

class OList{
 private:
  Node *head = new Node;
  void sort();
  int len = 0;
 public:
  OList();
  ~OList();

  // getters setters
  void insert(std::string data);
  void insert(int loc, std::string data); //0 indexed
  std::string get(int loc);

  int length();

  std::string toString();// for testing purposes

  void remove(int loc);
  bool contains(std::string item);

  void reverse();
  
};
