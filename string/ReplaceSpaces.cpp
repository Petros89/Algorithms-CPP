#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

string  ReplaceChar(string str, string tofind, string toreplace)
{
        size_t position = 0;
        for ( position = str.find(tofind); position != string::npos; position = str.find(tofind,position) )
        {
                str.replace(position ,1, toreplace);
        }
        return(str);
}


int main(){


    string initialString = "a string with spaces";
    cout << "\n" << "\n" << initialString;

    //after calling RmSpace function
    string replacedString = ReplaceChar(initialString, " ", "@");
    cout << "\n" << replacedString << "\n";


    return EXIT_SUCCESS;
}
