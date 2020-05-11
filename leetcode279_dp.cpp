class Solution {
public:
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
};