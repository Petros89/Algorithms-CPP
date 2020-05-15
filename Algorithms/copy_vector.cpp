// C++ code to demonstrate copy of vector 
// by assign() and copy(). 
#include<iostream> 
#include<vector> // for vector 
#include<algorithm> // for copy() and assign() 
#include<iterator> // for back_inserter 

using namespace std; 

int main() 
{ 
	// Initializing vector with values 
	vector<int> vect1{1, 2, 3, 4}; 

	// Declaring new vector 
	vector<int> vect2{5, 6, 7, 8}; 

    //append vec1 after vec2
	//copy(vect1.begin(), vect1.end(), back_inserter(vect2)); 

    //copy vec1 to vec2
	copy(vect1.begin(), vect1.end(), vect2.begin()); 

    //sort from greater to the lower
	//sort(vect1.begin(), vect1.end(), greater<int>()); 
    
	//Copying vector by copy function 
	//copy(vect1.begin(), vect1.end(), vect2.begin()+2); 

    // Copying vector by assign function 
    //vect2.assign(vect1.begin(), vect1.end()); 

	cout << "vec1 vector elements are : "; 
	for (int i=0; i<vect1.size(); i++) 
		cout << vect1[i] << " ";
        cout << "\n"; 

	cout << "vec2 vector elements are : "; 
	for (int i=0; i<vect2.size(); i++) 
		cout << vect2[i] << " ";
          cout  << "\n"; 


	return 0; 
} 

