    // int solve(vector<int> nums, int n) {
    //     if(n==0) return nums[n];
    //     if(n < 0) return 0;

    //     return max( nums[n] + solve(nums, n-2), solve(nums, n-1) );
    // }

    int rob(vector<int>& nums) {

        int n = nums.size();
        //vector<int> dp(n+1);
        int prev2 = 0, curr;
        int prev = nums[0];

        for(int i=1; i<n; i++) {
            curr = max(nums[i] + prev2, prev); 
            //dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
            prev2 = prev;
            prev = curr;
        }

        //return solve(nums, n-1);
        return prev;
    }
