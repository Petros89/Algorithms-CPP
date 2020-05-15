#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

bool Prime(int y){

    for (int i=2; i*i<=y; i++){
    
        if (y%i == 0){
            cout << "\n" << "Number is not prime" << "\n";
            return false;
        }

        cout << "\n" << "Number is prime" << "\n";
        return true;
    } 
}


#ifndef RunTests
int main()
{

  int x;
  cout << "\n" << "Enter an integer" << "\n";
  cin >> x;

  //Check if integer is prime
  Prime(x);

}
#endif
