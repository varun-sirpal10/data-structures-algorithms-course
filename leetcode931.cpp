class Solution {
public:
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
        
        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[m-1][j]);
        }
        
        return ans;
    }
};