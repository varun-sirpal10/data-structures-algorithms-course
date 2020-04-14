class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> q;
        
        vector<int> result;
        
        for(int i=0;i<k;i++){
            
            while(!q.empty() and nums[q.back()] <= nums[i]){
                q.pop_back();
            }
            
            q.push_back(i);
        }
        
        for(int i=k;i<nums.size();i++){
            result.push_back(nums[q.front()]);
            
            if(!q.empty() and q.front() <= i-k){
                q.pop_front();
            }
            
             while(!q.empty() and nums[q.back()] <= nums[i]){
                q.pop_back();
            }
            
            q.push_back(i);
        }
        
        result.push_back(nums[q.front()]);
        
        return result;
    }
};