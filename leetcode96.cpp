class Solution {
public:
    int numTrees(int n) {
        
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
};