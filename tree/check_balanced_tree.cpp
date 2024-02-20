  int solve(Node *root) {
      if(root==nullptr) return 0;
      
      int lh = solve(root->left);
      int rh = solve(root->right);
      
      if(lh==-1 || rh==-1) return -1;
      if(abs(lh-rh) > 1) return -1;
      
      return 1 + max(lh, rh);
  }

  //Function to check whether a binary tree is balanced or not.
  bool isBalanced(Node *root)
  {
      if(root == nullptr) return 0;

      // returns -1 if tree is not balanced   
      int val = solve(root);
      
      return (val==-1) ? false : true;
  }
