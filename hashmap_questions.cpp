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

bool subArrayWithSumZero(int arr[], int n){

	unordered_map<int,int> hp;

	int sum = 0;
	hp[sum] = sum;

	for(int i=0;i<n;i++){
		sum += arr[i];

		if(hp.count(sum)){
			return true;
		}
		else{
			hp[sum] = i;
		}
	}

	return false;
}

bool subArrayWithSumK(int arr[], int n, int k){

	unordered_map<int,bool> hp;

	int sum = 0;
	hp[sum] = true;

	for(int i=0;i<n;i++){
		sum += arr[i];

		if(hp.count(sum - k)){
			return true;
		}
		else{
			hp[sum] = true;
		}
	}

	return false;
}

int longestSubArraySumZero(int arr[], int n){

	unordered_map<int,int> hp;

	int sum = 0;
	hp[sum] = -1;
	int maxLen;

	for(int i=0;i<n;i++){
		sum += arr[i];

		if(hp.count(sum)){
			int currLen = i - hp[sum];
			maxLen = max(maxLen,currLen);
		}
		else{
			hp[sum] = i;
		}
	}
	return maxLen;
}

int longestSubarraySumK(int arr[], int n, int k) {
	
	unordered_map<int,int> hp;

	int sum = 0;
	hp[sum] = -1;
	int maxLen;

	for(int i=0;i<n;i++){
		sum += arr[i];

		if(hp.count(sum - k)){
			int currLen = i - hp[sum];
			maxLen = max(maxLen,currLen);
		}
		else{
			hp[sum] = i;
		}
	}

	return maxLen;
}

int lengthOfLongestSubstring(string s) {
        
    int left = 0;
    int right = 0;
    
    unordered_map<char,int> hp;
    int maxLen = 0;
    
    while(right < s.length()){
        
        char ch = s[right];
        if(hp[ch] == 0){
            hp[ch]++;
            right++;
            int currLen = right - left;
            maxLen = max(maxLen,currLen);
        }
        else{
            char ch = s[left];
            hp[ch]--;
            left++;
        }
    }
    
    return maxLen;
}

int main(){

	// int arr[] = {1,2,3,-3,4,5,4};
	// int n = 7;
	// cout<<subArrayWithSumZero(arr,n)<<endl;

	// int arr[] = {1, 2, 3, 4, 2, 1, 7};
	// int n = 7;
	// int k = 7;

	// cout << subarraySumK(arr, n, k) << endl;

	// int arr[] = {10, 5, 2, 7, 1, 9};
	// int n = 6;
	// cout<<longestSubarraySumK(arr,n,15)<<endl;

	return 0;
}