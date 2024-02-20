// Diameter is the maximum (distance between any two nodes);

int ans=-1;  
  int solve(TreeNode* root) {
      if(root==nullptr) return 0;

      int lh = 1 + solve(root->left);
      int rh = 1 + solve(root->right);
      ans = max(lh-1 + rh-1, ans);
      return max(lh, rh);
  }

  int diameterOfBinaryTree(TreeNode* root) {

      if(root->left==nullptr && root->right==nullptr) return 0;

      solve(root);

      return ans;        
  }
