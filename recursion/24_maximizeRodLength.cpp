#include <climits>
#include <iostream>
using namespace std;

// Given 3 lengths a, b, c: Maximize the number of pieces in which the rod can be cut;
// Each cut length should be either [a, b, c];
// Eg: n=23, a=11, b=9, c=12 => O/P: 2;
// Eg: n=9, a=2, b=2, c=2 => O/P: -1;

int maxi = -1;
int maxRodPieces(int n, int a, int b, int c, int ct) {
    
    if(n < 0) return -1;
    if(n == 0) {
        maxi = max(maxi, ct);
        return ct;
    }
    
    int countA = maxRodPieces(n-a, a, b, c, ct+1); 
    int countB = maxRodPieces(n-b, a, b, c, ct+1);
    int countC = maxRodPieces(n-c, a, b, c, ct+1);
    
    if(countA==-1 && countB==-1 && countC==-1) {
        return -1;
    }
    
    return max(countA, max(countB, countC));
}

int main() {
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    
    int ans = maxRodPieces(n, a, b, c, 0);
    cout<<ans;
    return 0;
}
