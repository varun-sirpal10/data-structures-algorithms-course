class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> hp;
        
        for(int num:nums){
            hp[num]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for(auto num:hp){
            pq.push({num.second,num.first});
        }
        
        while(pq.size() > k){
            pq.pop();
        }
        
        vector<int> res;
        
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};