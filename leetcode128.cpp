class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,bool> hp;
        
        for(auto num:nums){
            hp[num] = true;
        }
        
        int n = nums.size();
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            
            if(hp.count(nums[i] - 1)){
                continue;
            }
            else{ // LEFT BOUNDARY
                int count = 0;
                int x = nums[i];
                while(hp.count(x)){
                    count++;
                    x++;
                }
                ans = max(ans,count);
            }
        }
        
        return ans;
    }
};