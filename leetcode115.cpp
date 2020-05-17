class Solution {
public:
    int numDistinct(string s, string t) {
        int row = s.length() + 1;
        int col = t.length() + 1;
        
        vector<vector<long>> dp(row, vector<long> (col,0));
        
        for(int j=0;j<col;j++){
            dp[s.length()][j] = 0;
        }
        
        for(int i=0;i<row;i++){
            dp[i][t.length()] = 1;
        }
        
        for(int si=s.length()-1;si>=0;si--){
            for(int ti=t.length()-1;ti>=0;ti--){
                
                int count = 0;
                
                if(s[si] == t[ti]){
                    count += dp[si+1][ti+1];
                }
                
                count += dp[si+1][ti];
                
                dp[si][ti] = count;
            }
        }
        
        return dp[0][0];
    }
};