void gP(vector<string>& ans, int opn, int cln, string out) {
  
  if(opn == 0 && cln==0) {
      ans.push_back(out);
      return;
  }

  if(opn != 0) {
      string out1 = out + "(";
      gP(ans, opn-1, cln, out1);
  }

  if(cln > opn) {
      string out2 = out + ")";
      gP(ans, opn, cln-1, out2);
  }
}

vector<string> generateParenthesis(int n) {

  vector<string> ans;
  string out = "(";

  gP(ans, n-1, n, out);

  return ans;
}
