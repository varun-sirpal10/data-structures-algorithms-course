class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> hp;
        
        int sum = 0;
        hp[sum] = 1;
        int count = 0;
        
        for(int num:nums){
            sum += num;
            
            if(hp.count(sum - k)){
                count += hp[sum - k];
            }
            
            hp[sum]++;
        }
        
        return count;
    }
};