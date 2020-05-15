// Petros April/22/2020


#include <iostream>
#include <cstdlib>  
#include <cstdio>  
#include <string>
#include <algorithm>    
#include <sys/time.h>

//typedef double number;

using namespace std;

double get_time()
{
  struct timeval timeval_time;
  gettimeofday(&timeval_time,NULL);
  return (double)timeval_time.tv_sec + (double)timeval_time.tv_usec*1e-6;
}

int fib_default(unsigned long long int n) 
{ 
  unsigned long long int a = 0, b = 1, c; 
  if( n == 0) 
    return a; 
  for (int i = 2; i <= n; i++) 
  { 
     c = a + b; 
     a = b; 
     b = c; 
  } 
  return b; 
} 

int fib_recursive(unsigned long long int n){

    if (n<=1) return n;
    
    return fib_recursive(n-1) + fib_recursive(n-2);
}

// find min and max example

int main () {

  unsigned long long int number = 50; 

  double t = get_time();

  cout << "The Fibonacci sum is " << fib_default(number) << "\n";
  printf("Wall Time (default): %g s\n",get_time()-t);

  cout << "The Fibonacci sum is " << fib_recursive(number) << "\n";
  printf("Wall Time (recursive): %g s\n",get_time()-t);


  return 0;
}
