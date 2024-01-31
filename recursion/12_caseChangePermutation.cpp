#include <iostream>
using namespace std;

void permutationCaseChange(string str, string out) {
    
    if(str.length() == 0) {
        cout<<out<<" ";
        return;
    }
    
    
    // First adding lower str[0] to o/p;
    // Then adding upper str[0] to o/p;
    char c = tolower(str[0]);
    string op1 = out + c;
    c = toupper(str[0]);
    string op2 = out + c;
    
    str.erase(str.begin()+0);
    
    permutationCaseChange(str, op1);
    permutationCaseChange(str, op2);
    
}


int main()
{
    string s = "abc";
    string out = "";
    
    permutationCaseChange(s, out);

    return 0;
}
