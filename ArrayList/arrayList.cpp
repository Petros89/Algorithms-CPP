#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

class PrecondViolatedExcept : public std::logic_error
{
public:
   PrecondViolatedExcept(const std::string& message = "");
}; // end PrecondViolatedExcept

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
                       : std::logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

template<class ItemType>
class ArrayList
{
private:
   static const int DEFAULT_CAPACITY = 100; // Default capacity of the list
   ItemType items[DEFAULT_CAPACITY + 1];    // Array of list items (ignore items[0]
   int itemCount;                           // Current count of list items
   int maxItems;                            // Maximum capacity of the list

public:
   ArrayList();
   // Copy constructor and destructor are supplied by compiler

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool remove(int position);
   void clear();

   /** @throw  PrecondViolatedExcept if position < 1 or position > getLength(). */
   ItemType getEntry(int position) const throw(PrecondViolatedExcept);

   /** @throw  PrecondViolatedExcept if position < 1 or position > getLength(). */
   void setEntry(int position, const ItemType& newEntry)
                               throw(PrecondViolatedExcept);

   ItemType replace(int position, const ItemType& newEntry)
                              throw(PrecondViolatedExcept);

}; // end ArrayList


template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int ArrayList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
      return items[position];
   else
   {
      std::string message = "getEntry() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcept(message));
   }  // end if
}  // end getEntry

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1)
                       && (itemCount < maxItems);
   if (ableToInsert)
   {
      // Make room for new entry by shifting all entries at
      // positions from itemCount down to newPosition
      // (no shift if newPosition == itemCount + 1)
      for (int pos = itemCount; pos >= newPosition; pos--)
         items[pos] = items[pos - 1];

      // Insert new entry
      items[newPosition] = newEntry;
      itemCount++;  // Increase count of entries
   }  // end if

   return ableToInsert;
}  // end insert

template<class ItemType>
bool ArrayList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      // Remove entry by shifting all entries after the one at
      // position toward the beginning of the array
      // (no shift if position == itemCount)
      for (int pos = position; pos < itemCount; pos++)
         items[pos] = items[pos + 1];

      itemCount--;  // Decrease count of entries
   }  // end if

   return ableToRemove;
}  // end remove


template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry)
                              throw(PrecondViolatedExcept)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      ItemType oldEntry = items[position];
      items[position] = newEntry;
      return oldEntry;
   }
   else
   {
      std::string message = "replace() called with an empty list or ";
      message = message + "invalid position.";
      throw(PrecondViolatedExcept(message));
   } // end if
}  // end replace

template<class ItemType>
void ArrayList<ItemType>::clear()
{
   itemCount = 0;
}  // end clear

int main()
{
    ArrayList<string> a;
    a.insert(1,"hi");
    a.insert(2,"how are you");
    try
    {
        cout << "Discussion 1: " << a.getEntry(1) << ", " << a.getEntry(2) << endl;
    }
    catch (std::logic_error except)
    {
        cout << "Failed to get entry at location 1" << endl;
    }
    return 0;
}

