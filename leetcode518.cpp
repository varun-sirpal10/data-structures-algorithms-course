class Solution {
public:
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
};