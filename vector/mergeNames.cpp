#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>




using namespace std;

vector<string> unique_names(const vector<string>& names1, const vector<string>& names2)
{

  //define the result vector
  vector<string> mergedVector;


  //populate the vector with the elements of already existed other vectors
  mergedVector.insert(mergedVector.begin(), names1.begin(), names1.end());
  mergedVector.insert(mergedVector.end(), names2.begin(), names2.end());

  //sort the vector by names
  sort(mergedVector.begin(), mergedVector.end());

  //get a new vector that removes duplicates but not the last one
  auto uniqueNames = unique(mergedVector.begin(), mergedVector.end());
  unique(mergedVector.begin(), mergedVector.end());

  //delete the last element
  mergedVector.erase(uniqueNames, mergedVector.end());

  return mergedVector;

}

int main()
{
    vector<string> names1 = {"Theia", "Kira", "Ginaika", "Gomena"};
    vector<string> names2 = {"Kira","Gomena", "Theia", "Tasia"};

    vector<string> result = unique_names(names1, names2);
    for(auto element : result)
    {
       cout << element << ' '; // should print Ava Emma Olivia Sophia 
    }
}
