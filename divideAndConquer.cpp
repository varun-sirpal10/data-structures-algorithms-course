#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

int binarySearch(int arr[], int start, int end, int data){

	while(start<=end){

		int mid = (start + end)/2;

		if(arr[mid] == data){
			return mid;
		}
		else if(data > arr[mid]){
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	return -1;
}

int lowerBound(int arr[],int n,int data){
	int start = 0;
	int end = n-1;
	int ans = -1;

	while(start<=end){

		int mid = (start+end)/2;

		if(data == arr[mid]){
			ans = mid;
			end = mid -1;
		}
		else if(data > arr[mid]){
			start = mid+1;
		}
		else{
			end = mid - 1;
		}
	}
	return ans;
}

int upperBound(int arr[],int n,int data){
	int start = 0;
	int end = n-1;
	int ans = -1;

	while(start<=end){

		int mid = (start+end)/2;

		if(data == arr[mid]){
			ans = mid;
			start = mid + 1;
		}
		else if(data < arr[mid]){
			end = mid - 1;
		}
		else{
			start = mid+1;
		}
	}
	return ans;
}

int searchRotatedArray(int arr[], int start, int end, int data){
	if(start > end){
		return -1;
	}

	int mid = (start+end)/2;

	if(data == arr[mid]){
		return mid;
	}

	if(arr[mid] <= arr[end]){
		if(data > arr[mid] and data <= arr[end]){
			return searchRotatedArray(arr,mid+1,end,data);
		}
		else{
			return searchRotatedArray(arr,start,end-1,data);
		}
	}
	else{
		if(data < arr[mid] and data >= arr[start]){
			return searchRotatedArray(arr,start,mid-1,data);
		}
		else{
			return searchRotatedArray(arr,mid+1,end,data);
		}
	}
}

bool isPossible(int arr[],int n, int k, int time){
	int painter = 1;
	int painterTime = 0;

	for(int i=0;i<n;i++){
		painterTime += arr[i];

		if(painterTime > time){
			painter++;
			painterTime = arr[i];

			if (arr[i]>time){return false;}

			if (painter > k){
				return false;
			}
		}
	}

	return true;
}

int painterProblem(int arr[], int n, int k){

	int minTime = INT_MIN;
	int maxTime = 0;

	int ans=-1;

	for(int i=0;i<n;i++){
		minTime = max(minTime,arr[i]);
		maxTime += arr[i];
	}

	int start = minTime;
	int end = maxTime;

	while(start<=end){
		int mid = (start+end)/2;

		if(isPossible(arr,n,k,mid)){
			ans = mid;
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}

	return ans;
}

bool ispossible(int nums[], int m, int n, int sum){
        int num_subarr = 1;
        int subarr_sum=0;
        
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
int splitArray(int nums[], int m) {
        int minSum = nums[0];
        int maxSum = 0;
        int n = 4;
        int ans=-1;
        
        for(int i=1;i<n;i++){
            maxSum += nums[i];
        }
        
        int start = minSum;
        int end = maxSum;
        
        while(start<=end){
            int mid = (start+end)/2;
            
            if(ispossible(nums,m,n,mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }

bool canWePlace(int arr[], int n, int cows, int minDist){

	int no_cows = 1;
	int cur_dist = arr[0];

	for(int i=1;i<n;i++){
		int dist = arr[i] - cur_dist;

		if(dist >= minDist){
			no_cows++;
			cur_dist = arr[i];
			
			if(no_cows == cows){
				return true;
			}
		}
	}
	return false;
}


int aggressiveCows(int arr[], int n, int cows){

	sort(arr,arr+n);
	int start = 0;
	int end = arr[n-1] - arr[0];

	int ans;
	while(start<=end){

		int mid = (start+end)/2;
		if(canWePlace(arr,n,cows,mid)){
			ans = mid;
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	return ans;

}

void merge(int arr[], int start, int end){

	int mid = (start+end)/2;
	int i = start;
	int j = mid + 1;
	int temp[end-start+1];

	int k = 0;

	while(i<=mid and j<=end){
		if(arr[i] <= arr[j]){
			temp[k] = arr[i];
			k++;
			i++;
		}
		else{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}

	while(j<=end){
		temp[k] = arr[j];
		k++;
		j++;
	}	

	while(i<=end){
		temp[k] = arr[i];
		k++;
		i++;
	}

	int p = 0;
	for(int x=start;x<=end;x++){
		arr[x] = temp[p];
		p++;
	}
}


void mergeSort(int arr[], int start, int end){
	if(start==end){
		return;
	}

	int mid = (start+end)/2;

	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);

	merge(arr,start,end);	
}

int mergeInversion(int arr[], int start, int end){

	int count = 0;
	int temp[end-start+1];
	int mid = start + (end-start)/2;

	int i=start, j=mid+1, k=0;
	while(i<=mid and j<=end){
		if(arr[i]>arr[j]){
			temp[k] = arr[j];
			k++;
			j++;
			count += (mid-i+1);
		}
		else{
			temp[k] = arr[i];
			k++;
			i++;
		}
	}
	while(i<=mid){
		temp[k] = arr[i];
		k++;
		i++;
	}

	while(j<=end){
		temp[k] = arr[j];
		k++;
		j++;
	}

	for(int x=start;x<=end;x++){
		arr[x] = temp[x-start];
	}

	return count;
}

int inversionCount(int arr[], int start, int end){
	if(start>=end){
		return 0;
	}

	int count = 0;
	int mid = start + (end-start)/2;

	int leftCount = inversionCount(arr,start,mid);
	int rightCount = inversionCount(arr,mid+1,end);

	int concat = mergeInversion(arr,start,end);
	int total = concat + rightCount + leftCount;

	return total;
}

void quickSort(int arr[], int start, int end){

	if(start >= end){
		return;
	}
	
	int left = start;
	int right = end;
	int mid = start + (end-start)/2;

	int pivot = arr[mid];
	
	while(left<=right){

		while(arr[left] < pivot){
			left++;
		}

		while(arr[right] > pivot){
			right--;
		}

		if(left<=right){
			swap(arr[left],arr[right]);
			left++;
			right--;
		}
	}

	quickSort(arr,start,right);
	quickSort(arr,left,end);
}


int main(){

	// int arr[] = {1,3,7,8,10,12,17};
	// int start = 0;
	// int end = 7;
	// int data = 12;

	// cout<<binarySearch(arr,start,end,data)<<endl;

	// int arr[] = {1,2,2,2,6,6,6,7,9};
	// int data = 6;

	// cout<<upperBound(arr,9,data)<<endl;

	// int arr[] = {6,7,1,2,3,4,5};
	// int data = 1;

	// cout<<searchRotatedArray(arr,0,6,data)<<endl;

	// int board[] = {10,20,30,40};

	// cout<<painterProblem(board,4,2)<<endl;

	// int nums[] = {10,20,30,40};

	// cout<<splitArray(nums,2);

	// int arr[] = {1,2,8,4,9};
	// cout<<aggressiveCows(arr,5,3)<<endl;

	// int arr[] = {6,7,2,4,9,3,1,5};
	// int n = 8;
	// mergeSort(arr,0,n-1);

	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	// int arr[] = {9,1,4,3,2,5};
	// int n = 6;

	// cout<<inversionCount(arr,0,n-1);

	int arr[] = {1,6,5,4,2,3,8};
	int n = 7;
	quickSort(arr,0,n-1);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}