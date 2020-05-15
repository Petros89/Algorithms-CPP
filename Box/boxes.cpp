#include <stdexcept>
#include <iostream>


using namespace std;


class Boxes
{
public:
   static int Nbox(int products, int Lb, int Sb)
   {
      if (products < 5)
         return products;

      if ((products - (5 * Lb + Sb)) > 0)
         return -1;

      int rl = products / 5;

      if (rl > Lb)
        rl = Lb;

      return rl + (products - 5 * rl);
   }
};


#ifndef RunTests
int main(int argc, const char* argv[])
{
   cout << "Number of Total Boxes = " << Boxes::Nbox(16, 3, 3) << " (" << 16/5 << " Large + " << (16%5) << " Small)\n";

   return 0;
}
#endif
