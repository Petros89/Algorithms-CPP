// Petros April/22/2020


#include <iostream>
#include <cstdlib>  
#include <cstdio>  
#include <string>
#include <algorithm>    
#include <array>
#include <iterator>

//typedef double number;

using namespace std;

int reverse(int *arr, int n) {

    for (int i=0; i<0.5*n; i++) {
        int other = n - i - 1;
        int temp = arr[i];
        arr[i] = arr[other];
        arr[other] = temp;
    }
}


int main () {

  int n = 10;
  int *myarr = new int[n]; 


  for (int i=0; i<n; i++) myarr[i] += i;

  reverse(myarr,n);
  for (int i=0; i<n; i++) cout << myarr[i] << "\n";

  cout << "\nArray Size: "<< n << "\n";

  delete[] myarr;

  return 0;
}
