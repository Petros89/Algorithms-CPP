// Petros April/22/2020


#include <iostream>
#include <cstdlib>  
#include <cstdio>  
#include <string>
#include <algorithm>    
#include <iterator>

using namespace std;



// find min and max example

int main () {

  using std::begin;
  using std::end;

  //checking numbers
  cout << "min(1,2) == " << min(1,2) << '\n';
  cout << "max(2,1) == " << max(1,2) << '\n';
  
  cout << "\n";

  //checking characters
  cout << "min(a,z) == " << min("a","z") << '\n';
  cout << "max(a,z) == " << max("a","z") << '\n';

  int n = 10; 
  int *a = new int[sizeof(n)];
  
  for (int i : a) cout << a[i] << endl;

  return 0;
}
