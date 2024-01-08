#include <iostream>
using namespace std;

int nfac(int n) {
    if(n==1) return 1;
    
    return n * nfac(n-1);
}

int main() {

    int n, p;
    while(n != -1) {
        cout<<"Enter n: ";
        cin>>n;
    
        int fac = nfac(n);
    
        cout<<fac<<"\n";
    }

    return 0;
}
