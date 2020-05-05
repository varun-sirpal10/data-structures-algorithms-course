class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left = 0;
        int right = 0;
        
        unordered_map<char,int> hp;
        int maxLen = 0;
        
        while(right < s.length()){
            
            char ch = s[right];
            if(hp[ch] == 0){
                hp[ch]++;
                right++;
                int currLen = right - left;
                maxLen = max(maxLen,currLen);
            }
            else{
                char ch = s[left];
                hp[ch]--;
                left++;
            }
        }
        
        return maxLen;
    }
};