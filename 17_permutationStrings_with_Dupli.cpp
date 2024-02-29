    void permutate(string inp, string out, vector<string>& ans) {
        if(inp.length() == 0) {
            ans.push_back(out);
            return;
        }
        
        unordered_set<char> us; 
        for(int i=0; i<inp.size(); i++) {
            if(us.find(inp[i]) == us.end()) {
                us.insert(inp[i]);
                
                string ip1 = inp.substr(0, i) + inp.substr(i+1);
                string op1 = out + inp[i];
                permutate(ip1, op1, ans);
            }
        }
    }

	vector<string>find_permutation(string S)
	{
	    vector<string> ans;
	    string out = "";
	    
	    permutate(S, out, ans);
	    
	    return ans;
	}
