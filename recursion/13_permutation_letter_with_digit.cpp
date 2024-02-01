#include <iostream>
using namespace std;

void permutationCaseChange(string str, string out) {
    
    if(str.length() == 0) {
        cout<<out<<" ";
        return;
    }
    
    string op1, op2;
    
    // If its a digit, just do 1 recursive call (instead of 2) to include the digit as it is;
    if(isdigit(str[0])) {
        out += str[0];
        str.erase(str.begin());
        permutationCaseChange(str, out);
    }
    else {
        char c = tolower(str[0]);
        op1 = out + c;
        c = toupper(str[0]);
        op2 = out + c;
        str.erase(str.begin());
        
        permutationCaseChange(str, op1);
        permutationCaseChange(str, op2);
    }
    
}


int main()
{
    string s = "a2b3";
    string out = "";
    
    permutationCaseChange(s, out);

    return 0;
}
