#include <string>
#include <iostream>
#include <stdexcept>
#include <deque>

using namespace std;

class Tollgate
{
public:

   void enter(string licensePlate)
   {
      l.push_back(licensePlate);
   }

   string exit()
   {
      if (l.size() == 0)
         throw logic_error("Tollgate is empty!");

      string r = l.front();

      l.pop_front();

      return r;
   }

private:

   deque<string> l;
};

#ifndef RunTests
int main(int argc, const char* argv[])
{
   Tollgate tollgate;
   tollgate.enter("New York");
   tollgate.enter("LA");
   cout << tollgate.exit() << '\n';
   cout << tollgate.exit() << '\n';

   return EXIT_SUCCESS;
}
#endif
