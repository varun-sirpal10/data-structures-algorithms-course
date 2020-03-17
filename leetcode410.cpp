class {
public:
    int splitArray(vector<int>& nums, int m) {
        long long int minSum = nums[0];
        long long int maxSum = 0;
        int n = nums.size();
        long long int ans=-1;
        
        for(int i=0;i<n;i++){
            maxSum += nums[i];
        }
        
        long long int start = minSum;
        long long int end = maxSum;
        
        while(start<=end){
            long long int mid= (start+end)/2;
            
            if(isPossible(nums,m,n,mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
    
    bool isPossible(vector<int>&nums, int m, int n, int sum){
        int num_subarr = 1;
        long long int subarr_sum=0;
        
        for(int i=0;i<n;i++){
            subarr_sum += nums[i];
            
            if (subarr_sum > sum){
                num_subarr++;
                subarr_sum = nums[i];
                
                if(nums[i]>sum){return false;}
                
                if(num_subarr > m){
                    return false;
                }
            }
        }
        return true;
    }
};