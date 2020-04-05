class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return targetSum(0,nums,0,S);
    }
    
    int targetSum(int si, vector<int>& nums, int sum, int S){
        if(si == nums.size()){
            if(sum == S){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        int positive = targetSum(si+1,nums,sum+nums[si],S);
        int negative = targetSum(si+1,nums,sum-nums[si],S);
        
        return positive+negative;
    }
};