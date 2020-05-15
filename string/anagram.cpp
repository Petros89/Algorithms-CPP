#include <vector>
#include <string>
#include <stdexcept>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class AllAnagrams
{
public:
   static vector<string> getAllAnagrams(string str)
   {

      unordered_set<string> anagram_set;

      sort(str.begin(), str.end());

      //loop over permutations
      do
      {
         anagram_set.insert(str);
      }
      while(next_permutation(str.begin(), str.end()));

      vector<string> result;
      copy(anagram_set.begin(),anagram_set.end(),back_inserter(result));

      return result;
   }
};


#ifndef RunTests
int main(int argc, const char* argv[])
{

   string mystring;
   cout << "\n" << "Enter a String" << "\n";
   cin >> mystring;

   int count = 0;

   vector<string> anagrams = AllAnagrams::getAllAnagrams(mystring);

   for (vector<string>::iterator it = anagrams.begin(); it != anagrams.end(); ++it)
   {
      cout << *it << '\n';
      count++;
   }

   cout << "\n" << "Total Anagrams:" << count << "\n";

   return 0;
}
#endif
