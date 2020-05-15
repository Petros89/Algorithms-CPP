#include <algorithm>
#include <string>
#include <iostream>
#include <algorithm>    // std::reverse
#include <vector>
#include <cstdio>      /* printf, fgets */
#include <cstdlib>
#include <sstream>
#include <iterator>

using namespace std;

 
int main () {

  string s;
  cout << "\n" << "Enter a string " << s << "\n";
  cin >> s;
    
  //reverse the string
  reverse(s.begin(), s.end());
  cout << "\n" << "The reverted string is: " << s << "\n";

  //reverse again string
  reverse(s.begin(), s.end());
  cout << "\n" << "The re-reverted string is: " << s << "\n";

  //convert string to integer
  int str2int = stoi(s);
  cout << "\n" << "The converted string is the intenger: " << str2int << "\n";

  //convert string to integer
  string str = to_string(str2int); 
  cout << "\n" << "The converted integer back to string is: " << str << "\n";

  int n = str.size();
  char split_str[n];
  //copy characters of the string to character array
  for (int i=0; i<=str.length(); i++){

    split_str[i] = str[n-i];

    cout << "\n" << split_str[i] << "\n";
  }


  return 0;
}

