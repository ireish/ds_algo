#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void insert_elem(vector<int> &vec, int elem) {
    if(vec.size() == 0 || elem >= vec.back()) {
        vec.push_back(elem); 
        return;
    }
    
    int val = vec.back();
    vec.pop_back();
    
    insert_elem(vec, elem);
    
    vec.push_back(val);
}

void sort_rec(vector<int> &vec) {
    // Base condition (smallest input);
    if(vec.size() <= 1) return;
    
    int elem = vec.back();
    vec.pop_back();

    // Calling this func. recursively
    // with one element (last) less
    sort_rec(vec);
    
    //recursive func. to insert last
    //element in its correct position
    insert_elem(vec, elem);
}
    


int main() {

    int n;
    
    cout<<"Enter Size of Array: ";
    cin>>n;
    
    vector<int> vec;
    vec.resize(n);
    
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0; i<n; i++) cin>>vec[i];
    
    sort_rec(vec);
    
    for(int i=0; i<n; i++) {
        cout<<vec[i]<<" ";
    }
    
    return 0;
}
