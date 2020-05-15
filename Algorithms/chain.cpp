#include <stdexcept>
#include <iostream>
#include <unordered_set>

using namespace std;

enum Side { NONE, LEFT, RIGHT };

class Link
{
public:

   Link* getLeft() const
   {
      return this->left;
   }

   Link* getRight() const
   {
      return this->right;
   }

   void append(Link* rightPart)
   {
      if (this->right != NULL)
         throw logic_error("Link is already connected.");

      this->right = rightPart;
      rightPart->left = this;
   }

private:

   Link* left;
   Link* right;
};

class Chain
{
public:

   static Side whichSideIsLonger(const Link& link)
   {
      int l = 0;
      int r = 0;

      unordered_set<const Link*> s;

      {
         const Link* x = &link;

         while (x->getRight())
         {
           s.insert(x);
           x = x->getRight();

           if (s.find(x) != s.end())
            return NONE;

           r++;
         }
      }

      {
         const Link* x = &link;

         while (x->getLeft())
         {
           s.insert(x);
           x = x->getLeft();

           if (s.find(x) != s.end())
            return NONE;

           l++;
         }
      }

      if (r > l)
         return RIGHT;
      else if (l > r)
         return LEFT;
      else
         return NONE;
   }
};


#ifndef RunTests
int main(int argc, const char* argv[])
{
   Link* left = new Link();
   Link* middle = new Link();
   Link* right = new Link();
   left->append(middle);
   middle->append(right);

   cout << "The Longer chain is " << Chain::whichSideIsLonger(*right) << "\n";
}
#endif
