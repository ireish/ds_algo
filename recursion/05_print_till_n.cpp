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

void print_till_one(int n) {
    if(n == 0) return;
    
    cout<<n<<" ";
    print_till_one(n-1);
}

int main() {

    int n;
    
    cout<<"Enter N: ";
    cin>>n;
    
    print_n(n);
    cout<<"\n";
    print_till_one(n);

    return 0;
}
