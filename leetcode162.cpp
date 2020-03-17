class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        return findPeak(nums,start,end);
    }
    
    int findPeak(vector<int>&nums, int start, int end){
        int mid = (start+end)/2;
        
        if((mid==0 or nums[mid]>nums[mid-1]) and (mid==nums.size()-1 or nums[mid]>nums[mid+1])){
            return mid;
        }
        
        else if(nums[mid] > nums[mid+1]){
            return findPeak(nums,start,mid-1);
        }
        
        else{
            return findPeak(nums,mid+1,end);
        }
    }
};