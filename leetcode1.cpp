class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> hp;
        
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            
            if(hp.count(target - nums[i])){
                res.push_back(hp[target-nums[i]]);
                res.push_back(i);
                break;
            }
            else{
                hp[nums[i]] = i;
            } 
        }
        return res;
    }
};