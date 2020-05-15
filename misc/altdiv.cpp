#include <iostream>

using namespace std;
 
int divide(int a, int b) {

    int result = 0;
    int sum = b;

    while (sum <= a) {
        sum += b;
        result++;

    }

    return result; 
}

int main()
{
    
    cout << "\n" << "Result(a/b):" << divide(3454,3) << "\n";

    return 0;
}

