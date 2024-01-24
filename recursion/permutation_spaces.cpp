#include <iostream>

using namespace std;

//Based on recursive-tree diagram; ip/op method;
void permutation_spaces(string str, string out) {
    if(str.length() == 0) {
        cout<<out<<" ";
        return;
    }
    
    //Always add 1st element in output as there's no space required before a;
    if(out.empty()){
        out = str[0];
        str.erase(str.begin());
    }
    
    string op1 = out + str[0];
    string op2 = out + "_" + str[0];
    str.erase(str.begin());
    
    permutation_spaces(str, op1);
    permutation_spaces(str, op2);
}


int main()
{
    string s = "abc";
    string out = "";
    
    permutation_spaces(s, out);

    return 0;
}
