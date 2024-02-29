void solve(int n, vector<string>& ans, string out, int c0, int c1) {
    // if(c1 < c0) return;
    if(n==0) {
        ans.push_back(out);
        // cout<<c0<<" "<<c1<<endl;
        // if(c1 >= c0) {
        //     ans.push_back(out);
        // }
        return;
    }
    
    string op2 = out + "1";
    solve(n-1, ans, op2, c0, c1+1);
    
    string op1 = out + "0";
    if(c1 > c0) {
        solve(n-1, ans, op1, c0+1, c1);
    }

}

vector<string> NBitBinary(int n)
{
  vector<string> ans;
  if(n==1) {
      ans.push_back("1"); 
      return ans;
  }
  
  string out = "";
  
  solve(n, ans, out, 0, 0);
  
 // sort(ans.begin(), ans.end(), greater<int>());
  
  return ans;
}
