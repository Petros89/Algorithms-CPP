
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int countNumbers_1(const std::vector<int>& sortedVector, int lessThan)
{
    int count = 0;
    for (int n=0; n<size(sortedVector); ++n) {
        if (sortedVector[n] < lessThan){
            count++;
        }

    }
    return count;
}


int countNumbers_2(const vector<int>& sortedVector, int lessThan)
{
    return distance(sortedVector.begin(), lower_bound(sortedVector.begin(), sortedVector.end(), lessThan));

}

#ifndef RunTests
int main()
{
    vector<int> v { 1, 3, 5, 7 };
    cout <<"\n" << countNumbers_1(v, 4) << "\n";
    cout <<"\n" << countNumbers_2(v, 4) << "\n";

}
#endif
