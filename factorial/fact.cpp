#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

unsigned long long Factorial(unsigned long long y){
    if (y<0){
        cout << "\n" << "-1 , Enter a positive integer" << "\n";
        EXIT_FAILURE;
    }
    else if (y==1){
        return 1;
    }
    else{
        return y * Factorial(y-1);
    }
}

#ifndef RunTests
int main()
{

  unsigned long long y;
  cout << "\n" << "Enter an integer" << "\n";
  cin >> y;

  //Compute factorial of integer
  cout << "\n" << "Factorial of number is:" << Factorial(y) << "\n";
  
  return 0;
}
#endif
