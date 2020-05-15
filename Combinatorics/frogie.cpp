#include <iostream>
#include <stdexcept>
//#include <unordered_map>

using namespace std;

class Frog
{
public:

   static int NumberOfDifferentWays(int n)
   {
      if (n == 1)
        return 1;

      else if (n == 2)
        return 2;
      else
      {
        return NumberOfDifferentWays(n - 1) + NumberOfDifferentWays(n - 2);
      }
   }

private:
};

#ifndef RunTests
int main(int argc, const char* argv[])
{
   cout << Frog::NumberOfDifferentWays(10) << "\n";

   return 0;
}
#endif
