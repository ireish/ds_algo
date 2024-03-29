//Similar to recursively sorting an array/vector;
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void insert(stack<int> &st, int elem) {
    if(st.size()==0 || st.top() <= elem) {
        st.push(elem);
        return;
    }
    
    int val = st.top();
    st.pop();
    
    insert(st, elem);
    st.push(val);
}

void sort_stack(stack<int> &st) {
    if(st.size()<=1) return;
    
    int elem = st.top(); 
    st.pop();
    sort_stack(st);
    
    insert(st, elem);
}


int main()
{
    stack<int> st;
    st.push(1); st.push(3); st.push(4); st.push(5); st.push(2);
    
    sort_stack(st);
    
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}
