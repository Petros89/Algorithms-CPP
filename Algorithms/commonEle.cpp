#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iterator>
#include <string>
#include <cstdio>
#include <cstdlib>


using namespace std;

class Common
{
public:

   static int MostCommon(const vector<int>& vec, int k)
   {
      if (k > static_cast<int>(vec.size()) || k <= 0)
         return -1;

      unordered_map<int,int> m;

      for (auto i : vec)
      {
         m[i]++;
         cout << m[i];
      }

      //check element uniqeness
      int count_unique = 0;

      for (auto i : vec){
        if (m[i] == 1) count_unique++;
      }

      if (count_unique == vec.size()) cout << "Vector contains only unique instances";

      vector<pair<int,int>> n(m.size());

      copy(m.begin(),m.end(),n.begin());

      nth_element(n.begin(),n.begin() + (k - 1), n.end(), [](auto x, auto y){ return y.second < x.second; });

      return (n.begin() + (k - 1))->first;
      //check element uniqueness
      //for (auto i : a)
      //{
      //  if (m[i]=1){
      //   throw::logic_error("Vector contains only unique instances");
      //   return 0;
      //  }
      //}
   }
};


#ifndef RunTests
int main(int argc, const char* argv[])
{
   vector<int> myvec;

   //reset random gen seet
   srand (time(NULL));

   /* generate secret number between 1 and 10: */
   //int irand = rand() % 10 + 1;

   //populate vector with random numbers in [0-9]
   for (int i=0; i<10; i++) myvec.push_back( rand() % 10+1 );

   //call Common class
   int x = Common::MostCommon(myvec, 1);


   //print out all elements of myvec vector
   cout << "\n";
   cout << "vector:: myvec [ ";
   for(int i=0; i < myvec.size(); i++)
      cout << myvec.at(i) << " ";
   cout << "]";
   cout << "\n";
   cout << "\n";

   cout <<"The most frequent element of the vector is: " << x << "\n";
   cout << "\n";

   return 0;
}
#endif
