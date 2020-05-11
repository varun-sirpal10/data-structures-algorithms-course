class Solution {
public:
    
    class Compare{
    public:
        bool operator()(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2){
            return p1.first > p2.first;
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        
        if(nums1.size() == 0 or nums2.size() == 0){
            return res;
        }
        
        if(k > nums1.size()*nums2.size()){
            k = nums1.size()*nums2.size();
        }
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, Compare > pq;
        
        for(int num1:nums1){
            for(int num2:nums2){
                pq.push({num1+num2,{num1,num2}});
            }
        }
        
        while(k--){
            auto val = pq.top();
            pq.pop();
            vector<int> topEle;
            topEle.push_back(val.second.first);
            topEle.push_back(val.second.second);
            res.push_back(topEle);
        }
        
        return res;
    }
};