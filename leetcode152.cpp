class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int currMax = nums[0];
        int currMin = nums[0];
        int finalMax = nums[0];
        
        for(int i=1;i<nums.size();i++){
            int temp = currMax;
            
            currMax = max(max(currMax*nums[i],currMin*nums[i]),nums[i]);
            currMin = min(min(temp*nums[i],currMin*nums[i]),nums[i]);
            
            if(currMax > finalMax){
                finalMax = currMax;
            }
        }
        
        return finalMax;
    }
};