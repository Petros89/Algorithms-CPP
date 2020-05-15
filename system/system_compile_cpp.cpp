// A C++ program that compiles and runs another C++  
// program 
#include <bits/stdc++.h> 
using namespace std; 
int main () 
{ 
    char filename[100]; 
    cout << "\n Enter file name to compile \n"; 
    cin.getline(filename, 100); 
  
    // Build command to execute.  For example if the input 
    // file name is a.cpp, then str holds "gcc -o a.out a.cpp"  
    // Here -o is used to specify executable file name 
    string compiler = "g++"; 
    //string input = "test.cpp";
    string output = "test.out";
    string input = filename;

    string compile = compiler + " " + input + " -o" + output; 
    string execute = "./" + output; 
  
    // Convert string to const char * as system requires 
    // parameter of type const char * 
    const char *command = compile.c_str(); 
    const char *comm_run = execute.c_str(); 
  
    cout << "Compiling file using " << command << endl; 
    system(command); 
  
    cout << "\nRunning file "; 
    system(comm_run); 
  
    return 0; 
} 
