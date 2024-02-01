  /*int isSubsetSum(int arr[], int n, int sum) {
      if(sum==0) return 1;
      if(n==0) return 0;
      
      if(arr[n-1] <= sum) {
          return (isSubsetSum(arr, n-1, sum) || isSubsetSum(arr, n-1, sum-arr[n-1]) );
      }
      else {
          return isSubsetSum(arr, n-1, sum);
      }
  }*/

int minDifference(int arr[], int n)  {
    
    int tSum = 0;
    int ans;
    for(int i=0; i<n; i++) {
        tSum += arr[i];
    }
    
    int sum = (tSum/2);
    int dp[n+1][sum+1] = {-1};
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            if(arr[i-1] <= j) dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    for(int j=sum; j>=0; j--){
        if(dp[n][j] == 1) {
            ans = tSum - (2*j);
            break;
        }
    }
    
    
    /*for(int i=tSum/2; i>=0; i--) {
        if(isSubsetSum(arr, n, i)) {
            ans = tSum - (2*i);
            break;
        }
    }*/
    
    /*for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    return ans;
} 
