class Solution {
public:
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
};