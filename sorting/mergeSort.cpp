/* 
Title: Merge Sort
Last Updated: 06/08/23
Author: Ireish P.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int mergeSort(vector<int> arr, int l, int r)
{
    
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> A;
    int t;

    cout<<"Enter "<<n<<" elements: \n";
    for(int i=0; i<n; i++)
    {
        cin>>t;
        A.push_back(t);
    }    

    for(int i=0; i<n; i++)
    cout<<A[i]<<" ";

    mergeSort(A, 0, n-1);

    return 0;
}
