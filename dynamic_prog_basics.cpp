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