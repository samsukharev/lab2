#include "LinkedList.h"
#include "node.h"
#include "node.cpp"
#include "ListInterface.h"
#include <cstddef>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
	itemCount = aList.itemCount;
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original List is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());

      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer

      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();

         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);

         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while

      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedList<ItemType>::add(const ItemType& newEntry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(headPtr);  // New node points to chain

   headPtr = nextNodePtr;          // New node is now first node
   itemCount++;

}  // end add



template<class ItemType>
std::vector<ItemType> LinkedList<ItemType>::toVector() const
{
   std::vector<ItemType> ListContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		ListContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }

   return ListContents;
}
template<class ItemType>
std::string LinkedList<ItemType>::toString() const
{
   std::string ListContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		ListContents+=(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }

   return ListContents;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());

      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;

      itemCount--;
   } // end if

	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;

      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr

	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedList<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int index = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr)||counter<itemCount)
   {
      if (anEntry == curPtr->getItem())
      {
        index = counter+1;
         return index;

      } // end if

      counter++;
      curPtr = curPtr->getNext();
   } // end while


}  // end getFrequencyOf

template<class ItemType>
bool LinkedList<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}


template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;

   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while

   return curPtr;
} // end getPointerTo
