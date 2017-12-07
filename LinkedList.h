#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListInterface.h"
#include "node.h"
#include <string>

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of List items

    Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
   LinkedList();
   LinkedList(const LinkedList<ItemType>& aList); // Copy constructor
   virtual ~LinkedList();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   std::vector<ItemType> toVector() const;
   std::string toString() const;
}; // end LinkedList

#endif // LINKEDLIST_H
