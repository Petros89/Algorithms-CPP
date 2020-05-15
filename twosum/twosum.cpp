#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class TwoSum
{
public:
   static pair<int, int> findTwoSum(const vector<int>&vector_input, int target)
   {
      unordered_map<int,int> set;

        
          for (size_t i = 0; i < vector_input.size(); ++i)
          { 
            auto search = set.find(target - vector_input[i]);
            
            if (search != set.end())
                return make_pair(i,search->second);

            set[vector_input[i]] = i;
            
          } 
          return make_pair(-1, -1);
  }
};

#ifndef RunTests
int main(int argc, const char* argv[])
{
   vector<int> myvec;
   myvec.push_back(1);
   myvec.push_back(5);
   myvec.push_back(1);
   myvec.push_back(8);
   myvec.push_back(4);

   sort(myvec.begin(),myvec.end());
  
   //play with vector
   reverse(myvec.begin(),myvec.end());
   auto last = unique(myvec.begin(),myvec.end());
   myvec.erase(last,myvec.end());

   for (vector<int>::iterator it=myvec.begin(); it!=myvec.end(); ++it)
    cout << ' ' << *it;
    cout << '\n';


   int target = 8;

   pair<int, int> position;

   position = TwoSum::findTwoSum(myvec, target);
   cout << position.first << " " << position.second << "\n";

   return 0;
}
#endif
