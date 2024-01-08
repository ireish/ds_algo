// Note: Works only for positive powers;

#include <iostream>
using namespace std;

int npow(int n, int p) {
    if(p == 0) return 1;
    if(p == 1) return n;
    
    return n * npow(n, p-1);
}

int main() {

    int n, p;
    while(n != -1) {
        cout<<"Enter n and p (to get n^p): ";
        cin>>n>>p;
    
        int exp = npow(n, p);
    
        cout<<exp<<"\n";
    }

    return 0;
}
