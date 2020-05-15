#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

template <class Container>
void split_vec(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}


int main()
{
    char str[] = "The quick brown fox jumps over the lazy dog";
    vector<string> words;
    split_vec(str, words);
    copy(words.begin(), words.end(),
         ostream_iterator<string>(cout, "\n"));

    //count total vector characters and words
    int strSize   = size(str);
    int wordSize  = size(words);
    
    cout << "\n" << "Total number of characters: "<< strSize << "\n";
    cout << "\n" << "Total number of words: "<< wordSize << "\n";

    for (int i=wordSize; i>=0; i--)

        if (words[i]=="brown")

            //erase elemet if matches "brown"
            words.erase (words.begin() + i);
        

    for (int i=wordSize; i>=0; i--)

        //print words elements reversely
        cout << "\n" << words[i] << "\n";

   return 0; 
}
