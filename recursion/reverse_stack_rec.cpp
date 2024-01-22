#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Induction for `reverse_stack` function;
void insert_end(stack<int> &st, int elem) {
    
    // BC: To push first element of original stack to the end;
    if(st.empty()) {
        st.push(elem);
        return;
    }
    
    int val = st.top();
    st.pop();
    insert_end(st, elem);
    st.push(val);
}

void reverse_stack(stack<int> &st) {
    if(st.empty()) {
        return;
    }
    
    int elem = st.top();
    st.pop();
    reverse_stack(st);
    
    insert_end(st, elem);
}

void print_stack(stack<int> st) {
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}


int main()
{
    stack<int> st;
    st.push(2); st.push(3); st.push(5); st.push(8); st.push(6);
    
    print_stack(st);
    
    reverse_stack(st);
    
    print_stack(st);
    
    return 0;
}
