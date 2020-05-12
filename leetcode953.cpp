class Solution {
public:
    // unordered_map<char,int> hp;
    int hp[256] = {0};
    
    bool isAlienSorted(vector<string>& words, string order) {
        
        int count = 1;
        for(char ch:order){
            hp[ch] = count;
            count++;
        }
        
        bool ans = true;
        
        for(int i=1;i<words.size();i++){
            if(!compare(words[i-1],words[i])){
                ans = false;
            }
        }
        
        return ans;
        
    }
    
    bool compare(string a, string b){

        if(a[0] != b[0]){
            return hp[a[0]] < hp[b[0]];
        }
        
        else{
            for(int i=1;i<max(a.length(),b.length());i++){
                if(a[i] != b[i]){
                    return hp[a[i]] < hp[b[i]];
                }
            }    
        }
        
        return true;        
    }
};