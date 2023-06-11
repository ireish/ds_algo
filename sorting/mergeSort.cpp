/* 
Title: Merge Sort
Last Updated: 06/11/23
Author: Ireish P.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Note: Vector is passed by reference so that the changes are reflected back
void merge(vector<int> &arr, int l, int m, int r)
{
    int p1= 0, p2= 0;
    int p = l;

    // Temporary vectors to store 2 arrays (to be merge)
    vector<int> t_a, t_b;

    for(int i=l; i<=m; i++)
        t_a.push_back(arr[i]);

    for(int i=m+1; i<=r; i++)
        t_b.push_back(arr[i]);

    // Comparing and merging
    while(p1<=(m-l) && p2<=(r-m-1))
    {
        if(t_a[p1] <= t_b[p2])
        {
            arr[p++] = t_a[p1]; ++p1;
        }
        else
        {
            arr[p++] = t_b[p2]; ++p2;
        }
    }

    // To copy remaining elements
    while(p1 <= (m-l)){
        arr[p++] = t_a[p1++];
    }

    while(p2 <= (r-m-1)){
        arr[p++] = t_b[p2++];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;    

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
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

    mergeSort(A, 0, n-1);

    cout<<"Sorted Elements: ";
    for(int i=0; i<n; i++)
    cout<<A[i]<<" ";

    return 0;
}