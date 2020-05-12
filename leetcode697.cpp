class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> first_seen;
        
        int degree = 0;
        int minLen = 0;
        
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            if(!first_seen.count(nums[i])){
                first_seen[nums[i]] = i;
            }
            if(freq[nums[i]] > degree){
                degree = freq[nums[i]];
                minLen = i - first_seen[nums[i]] + 1;
            }
            else if(freq[nums[i]] == degree){
                minLen = min(minLen,i - first_seen[nums[i]] + 1);
            }
        }
        
        return minLen;
    }
};