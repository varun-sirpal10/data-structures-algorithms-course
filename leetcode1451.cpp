class Solution {
public:
    string arrangeWords(string text) {
        
        vector<vector<string>> v(pow(10,5));
        
        text[0] = tolower(text[0]);
        
        stringstream ss(text);
        
        string word,res;
        
        while(ss >> word){
            v[word.size()].push_back(word);
        }
        
        for(auto x:v){
            for(auto y:x){
                res += y + " ";
            }
        }
        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
        
    }
};