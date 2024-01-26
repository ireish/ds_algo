bool isSubsetSum(vector<int>arr, int sum){
	
	if(sum == 0) {
		ans = 1;
		return 1;
	}
	
	if(arr.size() == 0) return 0;
	
	
	int t = arr.back();
	arr.pop_back();
	
	if(sum - t >= 0) {
		
		return ( isSubsetSum(arr, sum-t) || isSubsetSum(arr, sum) );
		
	}
	else {
		return isSubsetSum(arr, sum);
	}
}