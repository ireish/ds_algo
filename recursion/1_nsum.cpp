
#include <iostream>
using namespace std;

int nsum(int n) {
    if(n == 0) return 0;
    
    return n + nsum(n-1);
}

int main() {

    int n;
    cin>>n;
    
    int sum = nsum(n);
    
    cout<<sum;

    return 0;
}
