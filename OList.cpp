#include <iostream>
#include "Node.h"
#include "OList.h"

/*
    OList.cpp

    A Linked List that, upon, insertion will sort the set
    
    - constructor
    - destructor 
    - get / set
    - contains
    - remove and reverse
*/

OList::OList(){
  head = nullptr;
}

//destructor
OList::~OList() {
  Node * trailer = nullptr;
  Node * head = this->head;

  while(head != nullptr) {
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
  head = new Node;

  this->len = 0;
}

// insert at the "front" (head)
void OList::insert(std::string data){
  Node *tmp = new Node(data);
  tmp->setNext(head);
  head = tmp;

  this->sort(); // calling internal sort
  this->len += 1;
}

/*
  insert at loc
  We need a pointer to the node BEFORE
  the location where we want to insert 

  Piggybacking 
 */
void OList::insert(int loc, std::string data){
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc>0 && walker != nullptr){
    loc=loc-1;

    /* trailer will always be one node
       behind walker */
    trailer=walker;
    walker = walker->getNext();
    
  }

  // At this point, trailer points to the Node
  // BEFORE where we want to insert


  // test to see if we're trying to
  // insert past the end 
  if (loc > 0){
    // do something to indicate this is invalid
    throw std::out_of_range("Our insert is out of range");
  }

  Node *newNode = new Node(data);
  // Inserting at true location 0
  // will have trailer == nullptr
  // - we have to treat that as a special case
  if (trailer == nullptr){
    newNode->setNext(head);
    head = newNode;
  } else {
    // do the regular case 
    newNode->setNext(walker);
    trailer->setNext(newNode);
  }

  this->sort(); // calling internal sort
  this->len += 1;

}

/*
  Alternate solution:
    make a private variable to store the length
    and just return it here.

    Change all the insert/delete/remove type
    routines to upate that variable 
 */
int OList::length(){
  return this->len;
}

// to string method
std::string OList::toString(){
  Node *tmp = this->head;
  std::string result = "head --> ";
  while (tmp != nullptr){
    result = result + tmp->getData();
    result = result + " --> ";
    tmp = tmp->getNext();
  }
  result = result + "nullptr";
  return result;
}

/*
  Returns whether or not item is in the list
*/
bool OList::contains(std::string item) {
  Node* n = this->head;

  do {
    if (n->getData() == item){
       return true;
      }
    n = n->getNext();
  } while(n != nullptr);

  return false;
}

/* 
  Removes the loc th item in the linked list
*/
void OList::remove(int loc) {
  int count = 0;

  // if we want to remove the 0th item
  if (loc == 0) {
    Node* newHead= this->head->getNext();
    delete this->head;
    this->head = newHead;
    this->len -=1;
    return;
  }

  // getting to the loc - 1 item;
  Node* n = this->head;
  while(count != loc - 1) {
    n = n->getNext();
    count++;
    if (n == nullptr) {
      throw std::out_of_range("Error Out of bounds");
      return;
    } 
  }

  // get rid of the item and relink
  Node * nthItem = n->getNext();
  n->setNext(nthItem->getNext());

  delete nthItem; // deleting it once we have the list linked


  this->len -= 1;
  this->sort(); // calling internal sort
  return;
}

/* 
  gets the nth item in the linked arr
*/

std::string OList::get(int loc) {
  Node* n = this->head;
  int count = 0;
  while(n != nullptr) {
    if (count == loc) {
      return n->getData();
    }
    n = n->getNext();
    count++;
  }
  throw std::out_of_range(" Error: Gett Out of range");
}

/*
  Will reverse the list iterively.
 
  trailer -> c -> header
*/
void OList::reverse() {

  if(this->length() < 2) {
    return; // method won't work on list of one or zero
  }

  Node * trailer = nullptr ; 
  Node * c = this->head; // first item
  Node * header = c->getNext(); // second item

  while(header != nullptr) {
    c->setNext(trailer);
    trailer = c;
    c = header;
    header = header->getNext();
  }
  // when it breaks, it means header is the last item in the list
  c->setNext(trailer);
  this->head = c;

  return;
}

/*
    Internally sorts the array in ascending order

    uses the insertion sort

    eg of sorted array

    1 , 2 , 3, 4, 5 , nullptr
*/
void OList::sort() {
  int j;
  std::string val;
  for(int i=1; i <= this->length(); i++) {
      // for each item in the list
      val = this->get(i);
      j = i - 1;

      while (j >= 0 && val < this->get(j)) {
        // if the left item is greter we'll move it down until it isnt
        this->remove(i);
        this->insert(j, val);
        j -= 1;
      }
  }
  return;
}
