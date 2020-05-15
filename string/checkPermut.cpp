#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

bool CheckPerm(string s1, string s2){

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
 
  if (s1 == s2)
     return true;
  else
     return false;
}

int main(){


    string mystring1;  
    cout << "\n" << "Enter 1st string\n";
    cin >> mystring1;

    string mystring2;  
    cout << "\n" << "Enter 2nd string\n";
    cin >> mystring2;

    cout << "\n" << boolalpha << CheckPerm(mystring1,mystring2) << " <== [Permutation between string 1 and string 2 exists]" << "\n";


    return EXIT_SUCCESS;
}
