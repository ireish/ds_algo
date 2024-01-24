#include <iostream>

using namespace std;

//Based on recursive-tree diagram; ip/op method;
void print_subset(string str, string out) {
    if(str.length() == 0) {
        cout<<out<<" ";
        return;
    }
    
    string out1 = out;
    string out2 = out + str[0];
    str.erase(str.begin());
    
    print_subset(str, out1);
    print_subset(str, out2);
    
    return; //optional; works w/o return at the end;
}


int main()
{
    string s = "abc";
    string out = "";
    
    print_subset(s, out);

    return 0;
}
