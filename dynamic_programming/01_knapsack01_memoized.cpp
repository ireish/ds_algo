class Solution
{
    public:
    int dp[1001][1001];
    
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    {
        if(n==0 || W==0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        if(W >= wt[n-1]) {
            dp[n][W] = max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
        }
        else {
            dp[n][W] = knapSack(W, wt, val, n-1);
        }
        
        return dp[n][W];
    }
    
};