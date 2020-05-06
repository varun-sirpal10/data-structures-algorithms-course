class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;
        
        unordered_map<string,vector<string>> hp;
        
        for(auto str:strs){
            string str1 = str;
            sort(str1.begin(),str1.end());
            hp[str1].push_back(str);
        }
        
        for(auto val:hp){
            res.push_back(val.second);
        }
        
        return res;
    }
};