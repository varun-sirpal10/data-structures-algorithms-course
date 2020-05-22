class Solution {
public:
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
};