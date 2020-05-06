class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> freq;
        
        for(auto word:words){
            freq[word]++;
        }
        
        class Compare{
        public:
            bool operator()(pair<int,string> val1, pair<int,string> val2){
                if(val1.first == val2.first){
                    return val1.second < val2.second;
                }
                
                return val1.first > val2.first;
            }
        };
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, Compare > pq;
        
        for(auto val:freq){
            pq.push({val.second,val.first});
        }
        
        while(pq.size() > k){
            pq.pop();
        }
        
        vector<string> res;
        
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};