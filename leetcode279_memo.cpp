class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
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
};