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

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    
    if(n == 0){
        return 0;
    }
    
    vector<int> dp(n,1);
    
    int maxValue = 1;
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        maxValue = max(maxValue,dp[i]);
    }
    
    return maxValue;
}

int longestCommonSubsequencePureDP(string s1, string s2) {
    int row = s1.length() + 1;
    int col = s2.length() + 1;
    
    vector<vector<int>> dp(row,vector<int> (col,0));
    
    for(int i=0;i<row;i++){
        dp[i][s2.length()] = 0;
    }
    
    for(int j=0;j<col;j++){
        dp[s1.length()][j] = 0;
    }
    
    int result;
    
    for(int i=s1.length()-1;i>=0;i--){
        for(int j=s2.length()-1;j>=0;j--){
            
            if(s1[i] == s2[j]){
                result = 1 + dp[i+1][j+1];
            }
            
            else{
                int first = dp[i+1][j];
                int second = dp[i][j+1];
                
                result = max(first,second);
            }
            
            dp[i][j] = result;
        }
    }
    
    return dp[0][0];
}

int numDistinctSubsequencesPureDP(string s, string t) {
    int row = s.length() + 1;
    int col = t.length() + 1;
    
    vector<vector<long>> dp(row, vector<long> (col,0));
    
    for(int j=0;j<col;j++){
        dp[s.length()][j] = 0;
    }
    
    for(int i=0;i<row;i++){
        dp[i][t.length()] = 1;
    }
    
    for(int si=s.length()-1;si>=0;si--){
        for(int ti=t.length()-1;ti>=0;ti--){
            
            int count = 0;
            
            if(s[si] == t[ti]){
                count += dp[si+1][ti+1];
            }
            
            count += dp[si+1][ti];
            
            dp[si][ti] = count;
        }
    }
    
    return dp[0][0];
}

int longestPalindromeSubseqPureDP(string s) {
    if(s.length() == 0){
        return 0;
    }
    
    int row = s.length();
    int col = s.length();
    
    vector<vector<long>> dp(row, vector<long> (col,0));
    
    for(int i=0;i<row;i++){
        dp[i][i] = 1;
    }
    
    for(int right=1;right<=row-1;right++){
        
        for(int left=right-1;left>=0;left--){
            
            int result;
            
            if(s[left] == s[right]){
                result = dp[left+1][right-1] + 2;
            }
            else{
                int first = dp[left+1][right];
                int second = dp[left][right-1];
                
                result = max(first,second);
            }
            
            dp[left][right] = result;

            for (int x = 0; x < s.length(); x++) {

				for (int y = 0; y < s.length(); y++) {
					cout << dp[x][y] << "\t";
				}
				cout << endl;
			}
			cout << "************************************" << endl;
        }
	}
    
    return dp[0][s.length()-1];
}

int helper(string &s, int left, int right, vector<vector<int> > &dp) {
	//BASE CASE
	if (left == right) {
		return 1;
	}

	if (left > right) {
		return 0;
	}

	if (dp[left][right] != -1) {
		return dp[left][right];
	}

	// RECURSIVE
	int result;

	if (s[left] == s[right]) {
		result = helper(s, left + 1, right - 1, dp) + 2;
	} else {
		int first = helper(s, left + 1, right, dp);
		int second = helper(s, left, right - 1, dp);

		result = max(first, second);
	}

	dp[left][right] = result;

	return result;
}

int longestPalindromeSubseq(string s) {
	int n = s.length();

	vector<vector<int> > dp(n, vector<int> (n, -1));

	return helper(s, 0, n - 1, dp);
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
        
    int n = envelopes.size();
    
    if(n == 0){
        return 0;
    }
    
    sort(envelopes.begin(),envelopes.end());
    
    vector<int> dp(n,1);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            
            if(envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1]){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(),dp.end());
}

int minFallingPathSum(vector<vector<int>>& A) {
    int m = A.size();

    vector<vector<int>>dp(m, vector<int>(m, 0));
    
    for (int i = 0; i < m; i++)
        dp[0][i] = A[0][i];
    
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0)
                dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
            else if (j == m-1)
                dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
            else
                dp[i][j] = A[i][j] + min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]));
        }
    }
    
    return *min_element(dp[m-1].begin(),dp[m-1].end());
}

int knapSackPureDP(int weight[], int value[], int capacity, int n){
    vector<vector<int>> dp(n+1,vector<int> (capacity+1,0));

    //BASE CASE
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }

    for(int j=0;j<=capacity;j++){
        dp[0][j] = 0;
    }

    //RECURSIVE CASE
    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){

            int include = INT_MIN;
            int exclude = INT_MIN;

            if(j >= weight[i - 1]){
                include = value[i - 1] + dp[i - 1][j - weight[i - 1]];
            }

            exclude = dp[i-1][j];

            dp[i][j] = max(include,exclude);
        }
    }

    return dp[n][capacity];
}

int CoinChange2Memo(int amount, vector<int>& coins) {
    int n = coins.size();
    
    if(amount == 0){
        return 1;
    }
    
    if(n == 0){
        return 0;
    }
    
    vector<vector<int>> dp(n+1, vector<int> (amount+1,-1));
    
    return helper(0,amount,coins,dp);
}

int helper(int si, int amount, vector<int> &coins, vector<vector<int>> &dp){
    if(si == coins.size()){
        return 0;
    }
    
    if(amount == 0){
        return 1;
    }
    
    
    if(dp[si][amount] != -1){
        return dp[si][amount];
    }
    
    //RECURSIVE CASE
    int count = 0;
    
    if(amount >= coins[si]){
        count += helper(si,amount - coins[si], coins, dp);
    }
    
    count += helper(si+1,amount,coins,dp);
    
    dp[si][amount] = count;
    
    return count;
}

int CoinChangePureDP(int amount, vector<int>& coins) {
    
    if(amount == 0){
        return 1;
    }
    
    if(coins.size() == 0){
        return 0;
    }
    
    int row = coins.size() + 1;
    int col = amount + 1;
    
    vector<vector<int>> dp(row,vector<int> (col,0));
    
    //BASE CASE
    for(int j=0;j<=amount;j++){
        dp[coins.size()][j] = 0;
    }
    
    for(int i=0;i<=coins.size();i++){
        dp[i][0] = 1;
    }
    
    //RECURSIVE CASE
    for(int j=1;j<=amount;j++){
        for(int i=coins.size()-1;i>=0;i--){
            
            if(j >= coins[i]){
                dp[i][j] += dp[i][j-coins[i]];
            }
            
            dp[i][j] += dp[i+1][j];                
        }
    }
    
    return dp[0][amount];
}

int coinChange(vector<int>& coins, int amount) {
        
    vector<int> dp(amount+1,0);
    
    //BASE CASE
    dp[0] = 0;
    
    //RECURSIVE CASE
    for(int i=1;i<=amount;i++){
        
        int count = amount+1;
        
        for(int j=0;j<coins.size();j++){

            if(coins[j] <= i){
                count = min(count,dp[i-coins[j]] + 1);   
            }
        }
        
        dp[i] = count;
    }
    
    return dp[amount] > amount ? -1 : dp[amount];
}

int combinationSum4(vector<int>& nums, int target) {
        
    if(nums.size() == 0){
        return 0;
    }
    
    vector<unsigned int> dp(target + 1,0);
    
    sort(nums.begin(),nums.end());
    
    dp[0] = 1;
    
    for(int i=1;i<=target;i++){
        
        for(int j=0;j<nums.size();j++){
            
            if(i < nums[j]) break;
            
            dp[i] += dp[i - nums[j]]; 
        }
    }
    
    return dp[target];
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


	// cout<<longestPalindromeSubseqPureDP("bbbab")<<endl;

    int value[] = {50, 40, 70, 40};
    int weight[] = {5, 4, 6, 3};
    int capacity = 8;
    int n = 4;

    cout<<knapSackPureDP(weight,value,capacity,n)<<endl;

	return 0;
}