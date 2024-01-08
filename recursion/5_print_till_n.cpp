#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print_n(int n) {
    
    // When n = 0, return to prev. stack
    // -> starts printing from 1;
    if(n==0) return;
    
    print_n(n-1);
    cout<<n<<" ";
}

int main() {

    int n;
    
    cout<<"Enter N: ";
    cin>>n;
    
    print_n(n);

    return 0;
}
