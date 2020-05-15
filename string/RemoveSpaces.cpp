#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

string RmSpace(string mystring){
     
   
    mystring.erase(remove(mystring.begin(), mystring.end(), ' '), mystring.end());
    reverse(s2.begin(), s2.end());

    return mystring;

}



int main(){


    string mystring = "a string with spaces";
    cout << "\n" << "\n" << mystring;

    //after calling RmSpace function
    cout << "\n" << RmSpace(mystring) << "\n";


    return EXIT_SUCCESS;
}
