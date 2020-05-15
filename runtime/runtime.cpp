// Petros April/22/2020


#include <iostream>
#include <cstdlib>  
#include <cstdio>  
#include <string>
#include <algorithm>    
#include <array>

//typedef double number;

using namespace std;

int runtime(int *array) {
    int sum = 0;
    int product = 1;
    for (int i=1; i<=size(array); i++) {
    array[i] += i;
    sum += array[i];
    }

    for (int i=1; i<=size(array); i++) {
    array[i] += i;
    product *= array[i] ;
    }
    cout << "sum =  "<< sum << "\n";
    cout << "poduct = " << product << "\n";
} 

int main () {

  int n = 1000000;
  int array[n]; 


  runtime(array);

  return 0;
}
