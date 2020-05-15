#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class populate {


public: const vector<int> getVec(vector<int>& vec, int start_size, int end_size){

            for (int i=start_size; i<end_size; ++i)
                
                vec.push_back(i);
            
            return vec;
        }

        pair<int,int> getMult(vector<int>& vec, int mult){

            int mult_count = 0;
            int non_mult_count = 0;

            for (int i=0; i<vec.size(); i++){

                if (vec[i] % mult == 0){
                    mult_count++;
                }
                else
                {
                    non_mult_count++;
                }

                if (vec[i] == 0){
                    cout << "zero element identified" << "\n";
                    mult_count--;
                    non_mult_count--;
                }
            }

            return make_pair(mult_count, non_mult_count);
        }

private: 
};
            

int main(int argc, char **argv) {

    vector<int> a;
    
    //create object myvec pointing to class populate
    populate myvec;

    myvec.getVec(a,0,10);   //[1-9]
    myvec.getVec(a,10,20);  //[10-19]
    myvec.getVec(a,20,31);  //[20-30]

    a.push_back(40);
    a.push_back(50);
    a.push_back(100);

    //myvec.getVec(a,101,201);  //[101-200]

    //for (auto element : a) cout << a[element] << " ";
    cout << "Initial Vector\n";
    for (int i=0; i<a.size(); i++) cout << a[i] << " ";
    cout << "\n";

    //sort vector in greater order a>b>c>d>...>z
    sort(a.begin(), a.end(), std::greater<int>());

    cout << "Sorted (Greater-Order) Vector\n";
    for (int i=0; i<a.size(); i++) cout << a[i] << " ";
    cout << "\n";


    cout << "\n";
    cout << myvec.getMult(a,2).first << " multiples of 2" << "\n\n" 
         << myvec.getMult(a,2).second << " non-multiples of 2" << "\n"; //<< " " << myvec.getMult(a,3).second << "\n";
    cout << "\n";

    return 0;
}
