class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        int ans=-1;
    
	while(start <= end){
        
        if(start==end){
            return arr[start];
        }

		int mid = start + (end-start)/2;

		if(arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1]){
			ans = arr[mid];
			break;
		}

		if(mid%2==0){
			if(arr[mid] == arr[mid-1]){
				end = mid - 2;
			}
			else{
				start = mid + 2;
			}
		}

		else{
			if(arr[mid] == arr[mid-1]){
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}
		}
	}
	return ans;
    }
};