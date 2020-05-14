class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int> hp;
        stringstream ss;
        ss<<A<<" "<<B;
        string words;
        
        while(ss >> words){
            hp[words]++;
        }
        
        vector<string> res;
        
        for(auto val:hp){
            if(val.second == 1){
                res.push_back(val.first);
            }
        }
        
        return res;
    }
};