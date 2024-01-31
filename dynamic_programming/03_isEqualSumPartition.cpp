// subsetSum Code (REC);
int isSubsetSum(int arr[], int N, int sum) {
    if(sum == 0) return 1;
    if(N==0) return 0;    
    
    if(arr[N-1] <= sum) {
        return ( isSubsetSum(arr, N-1, sum-arr[N-1]) || isSubsetSum(arr, N-1, sum) );
    }
    else {
        return isSubsetSum(arr, N-1, sum);
    }
}

int isEqualSumPartition(int N, int arr[])
{
    int64_t sum = 0;
    for(int i=0; i<N; i++) {
        sum += arr[i];
    }
    
    // If total sum of array is odd, it cannot be partitioned into two equal sums;
    if(sum%2 != 0) return 0;
    
    // Sum of both sides in partition should be equal to the same number i.e. (sum/2);
    int ans = isSubsetSum(arr, N, sum/2);
    
    return ans;
}
