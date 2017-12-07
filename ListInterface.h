#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H


//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing 1-1.
    @file ListInterface.h */
#include <vector>

template<class ItemType>
class ListInterface
{
public:
   /** Gets the current number of entries in this List.
    @return The integer number of entries currently in the List. */
   virtual int getCurrentSize() const = 0;

   /** Sees whether this List is empty.
    @return True if the List is empty, or false if not. */
   virtual bool isEmpty() const = 0;

   /** Adds a new entry to this List.
    @post  If successful, newEntry is stored in the List and
       the count of items in the List has increased by 1.
    @param newEntry  The object to be added as a new entry.
    @return  True if addition was successful, or false if not. */
   virtual bool add(const ItemType& newEntry) = 0;

   /** Removes one occurrence of a given entry from this List,
       if possible.
    @post  If successful, anEntry has been removed from the List
       and the count of items in the List has decreased by 1.
    @param anEntry  The entry to be removed.
    @return  True if removal was successful, or false if not. */
   virtual bool remove(const ItemType& anEntry) = 0;

   /** Removes all entries from this List.
    @post  List contains no items, and the count of items is 0. */
   virtual void clear() = 0;

   /** Counts the number of times a given entry appears in List.
    @param anEntry  The entry to be counted.
    @return  The number of times anEntry appears in the List. */
   virtual int getFrequencyOf(const ItemType& anEntry) const = 0;

   /** Tests whether this List contains a given entry.
    @param anEntry  The entry to locate.
    @return  True if List contains anEntry, or false otherwise. */
   virtual bool contains(const ItemType& anEntry) const = 0;

   /** Empties and then fills a given vector with all entries that
       are in this List.
    @return  A vector containing all the entries in the List. */
   virtual std::vector<ItemType> toVector() const = 0;

   /** Destroys object and frees memory allocated by object.
    (See C++ Interlude 2) */
   virtual ~ListInterface () { }

};

#endif // LISTINTERFACE_H
