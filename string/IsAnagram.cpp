#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Anagram {

public: static bool IsAnagram(string a, string b){
            
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());

            return (a == b);
        }
};

#ifndef RunTests

int main(int arg, char* argv[]){

    if (arg < 3) {
        perror("Command-line usage: ./executable arg1 arg2");
        exit(1);
    }
    string a = argv[1];
    string b = argv[2];
    

    cout << "\n" << boolalpha << Anagram::IsAnagram(a,b) << "\n";


return 0;
}
#endif
