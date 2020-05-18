class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.length() == 0){
            return 0;
        }
        
        int row = s.length();
        int col = s.length();
        
        vector<vector<long>> dp(row, vector<long> (col,0));
        
        for(int i=0;i<row;i++){
            dp[i][i] = 1;
        }
        
        for(int right=1;right<=row-1;right++){
            
            for(int left=right-1;left>=0;left--){
                
                int result;
                
                if(s[left] == s[right]){
                    result = dp[left+1][right-1] + 2;
                }
                else{
                    int first = dp[left+1][right];
                    int second = dp[left][right-1];
                    
                    result = max(first,second);
                }
                
                dp[left][right] = result;
            }
        }
        
        return dp[0][s.length()-1];
    }
};