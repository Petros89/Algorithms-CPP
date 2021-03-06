/* Program to implement a stack using 
two queue */
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <array>
#include <cstdlib>


using namespace std; 

class Stack { 
	// Two inbuilt queues 
	queue<int> q1, q2; 

	// To maintain current number of 
	// elements 
	int curr_size; 

public: 
	Stack() 
	{ 
		curr_size = 0; 
	} 

	void push(int x) 
	{ 
		curr_size++; 

		// Push x first in empty q2 
		q2.push(x); 

		// Push all the remaining 
		// elements in q1 to q2. 
		while (!q1.empty()) { 
			q2.push(q1.front()); 
			q1.pop(); 
		} 

		// swap the names of two queues 
		queue<int> q = q1; 
		q1 = q2; 
		q2 = q; 
	} 

	void pop() 
	{ 

		// if no elements are there in q1 
		if (q1.empty()) 
			return; 
		q1.pop(); 
		curr_size--; 
	} 

	int top() 
	{ 
		if (q1.empty()) 
			return -1; 
		return q1.front(); 
	} 

	int size() 
	{ 
		return curr_size; 
	} 
}; 

// Driver code 
int main() 
{ 
	Stack s; 
    for (int n=5; n>0; n--)
    	s.push(n); 
    

    while ( s.size() != 0 ){ 
	//cout << s.top() << endl; 
	cout << "[current size size after s.top()] " << s.size() << " " << s.top() << " " << endl; 

	//cout << "after top size: " << s.top() << endl; 
	s.pop();
    }


	return 0; 
} 
// This code is contributed by Chhavi 

