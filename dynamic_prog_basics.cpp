#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

// TOP DOWN APPROACH : O(n)
int fibMemo(int n, int dp[]){
	if(n==0 or n==1){
		dp[n] = n;
		return n;
	}

	if(dp[n] != -1){
		return dp[n];
	}

	int fib1 = fibMemo(n-1,dp);
	int fib2 = fibMemo(n-2,dp);
	int fibn = fib1 + fib2;

	dp[n] = fibn;

	for (int i = 0; i <= 5; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "**************************" << endl;

	return fibn;
}

// BOTTOM UP APPROACH : O(n)
int fibPureDP(int n){
	int dp[n+1];

	dp[0] = 0;
	dp[1] = 1;

	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int reduceToOneMemo(int n, int dp[]){
	if(n==1){
		return 0;
	}

	if(dp[n] != -1){
		return dp[n];
	}

	int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

	count1 = reduceToOneMemo(n-1,dp) + 1;

	if(n%2==0){
		count2 = reduceToOneMemo(n/2,dp) + 1;
	}

	if(n%3==0){
		count3 = reduceToOneMemo(n/3,dp) + 1;
	}

	int ans = min(count1,min(count2,count3));

	dp[n] = ans;

	return ans;
}

int reduceToOnePureDP(int n){

	int dp[n+1];

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i=4;i<=n;i++){

		int count1 = INT_MAX , count2 = INT_MAX , count3 = INT_MAX;

		count1 = dp[i-1] + 1;

		if(i%2==0){
			count2 = dp[i/2] + 1;
		}

		if(i%3==0){
			count3 = dp[i/3] + 1;
		}

		int ans = min(count1,min(count2,count3));

		dp[i] = ans;
	}

	return dp[n];
}

int countBoardPathMemo(int start, int end, int dp[]){
	if(start == end){
		dp[start] = 1;
		return 1;
	}

	if(start > end){
		return 0;
	}

	if(dp[start] != -1){
		return dp[start];
	}

	int count = 0;
	for(int dice = 1;dice<=6; dice++){
		count += countBoardPathMemo(start + dice,end,dp);
	}

	dp[start] = count;

	for (int i = 0; i <= end; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "**************************" << endl;

	return count;
}

int countBoardPathPureDP(int start, int end){
	int dp[end+1];

	dp[end] = 1; // BASE CASE

	for(int i=end-1;i>=start;i--){
		int count = 0;
		for(int dice=1;dice<=6;dice++){
			if(i + dice > end){
				break;
			}
			count += dp[i+dice];
		}
		dp[i] = count;
	}
	return dp[0];
}

int helper(int n, vector<int>& dp){
    if(n==0){
        dp[n] = 0;
        return 0;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }
    
    int minSquares = INT_MAX;
    
    for(int i=1;i*i<=n;i++){
        int abhiTakKaAns = helper(n - i*i,dp) + 1;
        minSquares = min(minSquares,abhiTakKaAns);
    }
    
    dp[n] = minSquares;
    
    return minSquares;
}

int numSquares(int n) {
    vector<int> dp(n+1,-1);
    return helper(n,dp);
}

int numSquaresPureDP(int n) {
    int dp[n+1];
    
    dp[0] = 0;
    
    for(int i=1;i<=n;i++){
        
        int minVal = INT_MAX;
        
        for(int j=1;j*j<=i;j++){
            int abhiTakKaAns = dp[i-j*j] + 1;
            minVal = min(minVal,abhiTakKaAns);
        }
        dp[i] = minVal;
    }
    
    return dp[n];
}

int climbStairs(int n) {
    int dp[n+1];
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int HouseRobber(vector<int>& nums) {
    if(nums.size() == 0){
        return 0;
    }
    if(nums.size() == 1){
        return nums[0];
    }
    if(nums.size() == 2){
        return max(nums[0],nums[1]);
    }
    
    int n = nums.size() - 1;
    int dp[n+1];
    
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    
    for(int i=2;i<=n;i++){
        dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
    }
    
    return dp[n];
}

int maxSubArray(vector<int>& nums) {
    int currSum = nums[0];
    int maxSum = nums[0];
    
    for(int i=1;i<nums.size();i++){
        currSum = max(currSum + nums[i],nums[i]);
        
        maxSum = max(maxSum,currSum);
    }
    
    return maxSum;
}

int numTreesPureDP(int n) {
        
    int dp[n+1];
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2;i<=n;i++){
        
        int ans = 0;
        
        for(int j=1;j<=i;j++){
            int leftCount = dp[j - 1];
            int rightCount = dp[i - j];

            ans += leftCount*rightCount;    
        }
        
        dp[i] = ans;
    }
    
    return dp[n];
}

int minCostClimbingStairs(vector<int>& cost) {
        
    int n = cost.size();
    int dp[n];
    
    dp[0] = cost[0];
    dp[1] = cost[1];
    
    for(int i=2;i<n;i++){
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }
    
    return min(dp[n-1],dp[n-2]);
}

int minPathSum(vector<vector<int>>& grid) {
    if(grid.size() == 0){
        return 0;
    }
    
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> dp(m, vector<int> (n, 0));
    
    for(int i=0;i<m;i++){
        
        for(int j=0;j<n;j++){
            dp[i][j] += grid[i][j];
            
            if(i>0 and j>0){
                dp[i][j] += min(dp[i-1][j],dp[i][j-1]);
            }
            else if(i>0){
                dp[i][j] += dp[i-1][j];
            }
            else if(j>0){
                dp[i][j] += dp[i][j-1];
            }
        }
    }
    
    return dp[m-1][n-1];
}




int main(){

	// int n = 5;
	// int dp[n+1];
	// memset(dp,-1,sizeof(dp));
	// cout<<fibMemo(n,dp)<<endl;

	// int n = 5;
	// cout<<fibPureDP(n)<<endl;

	// int n = 10;
	// int dp[n+1];
	// memset(dp,-1,sizeof(dp));
	// cout<<reduceToOneMemo(n,dp)<<endl;

	// int n = 10;
	// cout<<reduceToOnePureDP(n)<<endl;

	// int start = 0;
	// int end = 10;
	// int dp[end + 1];
	// memset(dp,-1,sizeof(dp));
	// cout<<countBoardPathMemo(start,end,dp)<<endl;

	// cout<<countBoardPathPureDP(0,10)<<endl;



	return 0;
}