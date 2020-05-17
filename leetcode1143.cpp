class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int row = s1.length() + 1;
        int col = s2.length() + 1;
        
        vector<vector<int>> dp(row,vector<int> (col,0));
        
        for(int i=0;i<s1.length();i++){
            dp[i][s2.length()] = 0;
        }
        
        for(int j=0;j<s2.length();j++){
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
};