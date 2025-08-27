// ** Checks if an array is sorted in INCREASING ORDER or not;
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool is_array_sorted(int n, vector<int> A) {

    // If array size is 0 or 1, its already sorted;    
    if(n==0 || n==1) return 1;

    // Starting from (n-1)th index, check if current value
    // is greater than its previous or not;
    if(A[n-1] < A[n-2]) return false;
    
    return is_array_sorted(n-1, A);
}

int main() {

    int n;
    vector<int> arr;
    int elem;
    
    cout<<"Enter Size of Array: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    
    for(int i=0; i<n; i++) {
        cin>>elem;
        arr.push_back(elem);
    }
    
    bool ans = is_array_sorted(n, arr);
    
    if(ans==true) cout<<"Yes";
    else cout<<"No";

    return 0;
}
