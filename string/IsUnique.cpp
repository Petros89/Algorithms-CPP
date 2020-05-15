#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

bool Unique(string s){
     
   int n = s.length();
   char c[n];

   //sort the characters of a string
   sort(s.begin(), s.end());

   //copy string to charray elements
   strcpy(c, s.c_str());

   //cout << "\n" << s << "\n"; 
   int letters = 0;    
   for (int i=0; i<n; i++){

       if (c[i] != c[i+1]){
           
          letters++;
       
          //cout << "\n" << c[i] << "\n";
          cout << "\n" << "character [" << c[i] << "]" << " is unique" << "\n";
       }
       else
       {
           cout << "\n" << "Non-unique characters identified!" << "\n";
           break;
       }
   }

   cout << "\n";

   if (letters == n){
       
      return true;
   }
   
   else return false;
}


int main(){


    string mystring;  
    cout << "\n" << "Enter a string\n";
    cin >> mystring;

    cout << boolalpha << Unique(mystring) << " <== [IsUnique]" << "\n";


    return EXIT_SUCCESS;
}
