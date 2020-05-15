// A C++ program that compiles and runs another C++  
// program 
#include <bits/stdc++.h> 
using namespace std; 
int main () 
{ 
  
    string filename = "hello.sh";
    
    string execute = "./" + filename; 
  
    // Convert string to const char * as system requires 
    // parameter of type const char * 
    const char *command = execute.c_str(); 
  
    cout << "\n" << "Running file::< " << filename << " >" <<"\n"; 
    system(command); 
  
    return 0; 
} 
