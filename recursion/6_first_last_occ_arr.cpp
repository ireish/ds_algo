#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Try solving this first; i = 0 (starting idx);
int last_occ(vector<int> arr, int n, int key, int i) {
    if(i == n) return -1;
    
    int last_idx = last_occ(arr, n, key, i+1);
    if(last_idx != -1) {
        return last_idx;
    }
    
    if(arr[i] == key) return i;
    
    return -1;
}

int first_occ(vector<int> arr, int n, int key, int i) {
    if(i == n) return -1;
    if(arr[i] == key) return i;
    
    return first_occ(arr, n, key, i+1);
}

int main() {

    int n;
    
    cout<<"Enter Size of Array: ";
    cin>>n;
    
    vector<int> vec(n);
    
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0; i<n; i++) cin>>vec[i];
    
    int f = first_occ(vec, n, 4, 0);
    int l = last_occ(vec, n, 4, 0);
    
    cout<<"\nIndex of First Occurrence: "<<f;
    cout<<"\nIndex of Last Occurrence: "<<l;
    
    return 0;
}
