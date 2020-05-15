#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
 
void Perm(string s){
    int count = 0;
    sort(s.begin(), s.end());
    do {
        cout << s << '\n';
        count++;
    } while(next_permutation(s.begin(), s.end()));


    cout << "\n" << "Number of permutations:" << count << "\n";
}

int main()
{
    string mystring;
    cout << "\n" << "Enter a string" << "\n";
    cin >> mystring;

    //calculate and count string permutations
    Perm(mystring);

    cout << "\n" << "Length of string:" << mystring.length() << "\n";
    cout << "\n" << "Size of string:" << mystring.size() << "\n";

    return 0;
}

