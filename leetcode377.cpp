class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        if(nums.size() == 0){
            return 0;
        }
        
        vector<unsigned int> dp(target + 1,0);
        
        sort(nums.begin(),nums.end());
        
        dp[0] = 1;
        
        for(int i=1;i<=target;i++){
            
            for(int j=0;j<nums.size();j++){
                
                if(i < nums[j]) break;
                
                dp[i] += dp[i - nums[j]]; 
            }
        }
        
        return dp[target];
    }
};