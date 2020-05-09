class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        
        if(len1 < len2){
            return "";
        }
        
        // unordered_map<char,int> hp1;
        // unordered_map<char,int> hp2;
        
        int hp1[256] = {0};
        int hp2[256] = {0};
        
        for(auto ch:t){
            hp2[ch]++;
        }
        
        int start = 0;
        int start_index = -1;
        int min_len = INT_MAX;
        int count = 0;
        
        for(int j=0; j<len1; j++){
            hp1[s[j]]++;
            
            if(hp2[s[j]] !=0 and hp1[s[j]] <= hp2[s[j]]){
                count++;
            }
            
            if(count == len2){
                while(hp1[s[start]] > hp2[s[start]] or hp2[s[start]] == 0){
                    if(hp1[s[start]] > hp2[s[start]]){
                        hp1[s[start]]--;
                    }
                    start++;
                }
                    
                int len_window = j - start + 1;
                if(min_len > len_window){
                    min_len = len_window;
                    start_index = start;
                }
            }
        }
        
        if(start_index == -1){
            return "";
        }
        
        string ans = s.substr(start_index,min_len);
        return ans;
    }
};