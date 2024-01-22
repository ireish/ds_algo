#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void remove_middle(stack<int> &st, int ct) {
    
    // when ct=1, that means we have reached the middle element;
    if(ct == 1) {
        st.pop();
        return;
    }
    
    int elem = st.top();
    st.pop();
    remove_middle(st, ct-1);
    st.push(elem);
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
    st.push(2); st.push(3); st.push(5); st.push(8); //st.push(2);
    
    // ct stores index of the element to be deleted;
    int ct = st.size()/2 + 1;
    
    print_stack(st);
    
    remove_middle(st, ct);
    
    print_stack(st);
    
    return 0;
}
