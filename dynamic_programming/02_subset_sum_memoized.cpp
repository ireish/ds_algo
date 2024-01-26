bool isSubsetSum(vector<int>arr, int sum){
	
	if(sum == 0) return 1;
	if(arr.size() == 0) return 0;
	
	if(dp[sum] != -1) return dp[sum];
	
	int t = arr.back();
	arr.pop_back();
	
	if(sum - t >= 0) {
		
		dp[sum] = ( isSubsetSum(arr, sum-t) || isSubsetSum(arr, sum) );
		
	}
	else {
		dp[sum] = isSubsetSum(arr, sum);
	}
	
	return dp[sum];
}