int perfectSum(int arr[], int n, int sum) {
    
    int dp[n+1][sum+1];
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }
    
    
    int mod = (pow(10, 9) + 7);
    
  
    /*if(sum == 0 && n==0) {
        return 1;
    }
    else if(n==0) {
        return 0;
    }*/
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(j < arr[i-1]) {
                dp[i][j] = dp[i-1][j] % mod;
            }   
            else {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-arr[i-1]]) % mod ;
            }
            
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    
    //ans = perfectSum(arr, n-1, sum-arr[n-1]) + perfectSum(arr, n-1, sum);
    
    //return ans;
    return dp[n][sum] % mod;
}
