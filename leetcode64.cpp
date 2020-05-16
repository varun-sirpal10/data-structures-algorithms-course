class Solution {
public:
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
};