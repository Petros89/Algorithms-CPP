
#include <stdexcept>
#include <iostream>
#include <deque>

class TrainComposition
{
public:

   void attachWagonFromLeft(int wagonId)
   {
      train_.push_front(wagonId);  //add element on front == left
   }

   void attachWagonFromRight(int wagonId)
   {
      train_.push_back(wagonId);   //add element on back == right
   }

   int detachWagonFromLeft()
   {
      int result = train_.front(); // acess 1st element on the left
      train_.pop_front();          //delete first element on the left
      return result;
   }

   int detachWagonFromRight()
   {
      int result = train_.back(); //access 1st element on the right
      train_.pop_back();          //delete 1st element on the right
      return result;
   }

private:

    std::deque<int> train_;
};

#ifndef RunTests
int main()
{
    TrainComposition tree;
    tree.attachWagonFromLeft(7);
    tree.attachWagonFromLeft(13);
    std::cout << tree.detachWagonFromRight() << "\n"; // 7
    std::cout << tree.detachWagonFromLeft(); // 13
}
#endif
