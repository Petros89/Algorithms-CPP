
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <array>

using namespace std;

template<typename T> void print_queue(T& myqueue) {
    while(!myqueue.empty()) {
        cout << " " << myqueue.top();
        myqueue.pop();
    }
    cout << '\n';

}

int main() {
    priority_queue<int> q1;
    int arr[] = {1,8,5,6,3,4,0,9,7,2};

    for(int n : arr){
        //insert the elements of arr in queue 1 by 1
        q1.push(n);
    }
    print_queue(q1);

    priority_queue<int, vector<int>, greater<int> > q2;

    for(int n : arr)
        q2.push(n);

    print_queue(q2);

 
    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    priority_queue<int, vector<int>, decltype(cmp) > q3(cmp);

    for(int n : arr)
        q3.push(n);

    print_queue(q3);

}
