#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

/* function to check whether characters of a string can form
a palindrome */
bool IsPalindrome(string str)
{

    string help = str;

    reverse(help.begin(),help.end());

    if (str == help){
        cout << "\n" << str << "\n";
        return true;
    }
    else
    {
       return false;
    }
    reverse(help.begin(),help.end());
}

bool CheckPermutation(string s){ 

    int count = 0;
    int count_perms = 0;

    do {

    count_perms++;
    //cout << "\n" << "New permutation check: " << s << '\n';

    if (IsPalindrome(s) == true) count++;
    
    //IsPalindrome(s)? cout << "Yes\n": cout << "No\n";

    } 

    while(next_permutation(s.begin(), s.end()));
    return (count,count_perms);
}


/* Driver program*/
int main()
{
    string s = "tact cao";

    //sort string
    sort(s.begin(),s.end());
    
    //remove space
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    

    CheckPermutation(s); 

    cout << "\n" << "Number of total anagrams (permutations):" << count_perms << "\n";
    cout << "\n" << "Number of identified palindromes:" << count << "\n";
    


return 0;
}

