
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    string ss = "cat";
    string zz = "dog";
    
    string sszz = zz.append(ss);
    cout << "\n" << sszz << "\n";

    string str = "apostolou";
    str.insert(9," petros");

    cout << "\n" << str << "\n";

return 0;
}
