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

vector<string> topKFrequent(vector<string>& words, int k) {
        
    unordered_map<string,int> freq;
    
    for(auto word:words){
        freq[word]++;
    }
    
    class Compare{
    public:
        bool operator()(pair<int,string> val1, pair<int,string> val2){
            if(val1.first == val2.first){
                return val1.second < val2.second;
            }
            
            return val1.first > val2.first;
        }
    };
    
    priority_queue<pair<int,string>, vector<pair<int,string>>, Compare > pq;
    
    for(auto val:freq){
        pq.push({val.second,val.first});
    }
    
    while(pq.size() > k){
        pq.pop();
    }
    
    vector<string> res;
    
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    
    reverse(res.begin(),res.end());
    return res;
}

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

int longestConsecutive(vector<int>& nums) {
        
    unordered_map<int,bool> hp;
    
    for(auto num:nums){
        hp[num] = true;
    }
    
    int n = nums.size();
    
    int ans = 0;
    
    for(int i=0;i<n;i++){
        
        if(hp.count(nums[i] - 1)){
            continue;
        }
        else{ // LEFT BOUNDARY
            int count = 0;
            int x = nums[i];
            while(hp.count(x)){
                count++;
                x++;
            }
            ans = max(ans,count);
        }
    }
    
    return ans;
}

bool isHappy(int n) {
        
    unordered_map<int,bool> hp;
    int sum;
    
    if(n==1){
        return true;
    }
    
    while(n != 1){
       sum = 0;
       while(n > 0){
            int rem = n%10;
            sum += rem*rem;
            n = n/10;
        }

        if(hp.count(sum)) return false;
        else {
            hp[sum] = true;
            n = sum;    
        }
        
        if(n==1){
            return true;
        }
    }
    return false;
}

string minWindow(string s, string t) {
    int len1 = s.length();
    int len2 = t.length();
    
    if(len1 < len2){
        return "";
    }
    
    // unordered_map<char,int> hp1;
    // unordered_map<char,int> hp2;
    
    int hp1[256] = {0};
    int hp2[256] = {0};
    
    for(auto ch:t){
        hp2[ch]++;
    }
    
    int start = 0;
    int start_index = -1;
    int min_len = INT_MAX;
    int count = 0;
    
    for(int j=0; j<len1; j++){
        hp1[s[j]]++;
        
        if(hp2[s[j]] !=0 and hp1[s[j]] <= hp2[s[j]]){
            count++;
        }
        
        if(count == len2){
            while(hp1[s[start]] > hp2[s[start]] or hp2[s[start]] == 0){
                if(hp1[s[start]] > hp2[s[start]]){
                    hp1[s[start]]--;
                }
                start++;
            }
                
            int len_window = j - start + 1;
            if(min_len > len_window){
                min_len = len_window;
                start_index = start;
            }
        }
    }
    
    if(start_index == -1){
        return "";
    }
    
    string ans = s.substr(start_index,min_len);
    return ans;
}

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

int hp[256] = {0};
    
bool isAlienSorted(vector<string>& words, string order) {
    
    int count = 1;
    for(char ch:order){
        hp[ch] = count;
        count++;
    }
    
    bool ans = true;
    
    for(int i=1;i<words.size();i++){
        if(!compare(words[i-1],words[i])){
            ans = false;
        }
    }
    
    return ans;
    
}

bool compare(string a, string b){

    if(a[0] != b[0]){
        return hp[a[0]] < hp[b[0]];
    }
    
    else{
        for(int i=1;i<max(a.length(),b.length());i++){
            if(a[i] != b[i]){
                return hp[a[i]] < hp[b[i]];
            }
        }    
    }
    
    return true;        
}

class RandomizedSet {
    unordered_map<int,int> hp;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hp.count(val)){
            return false;
        }
        
        hp[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!hp.count(val)){
            return false;
        }
        
        int pos = hp[val];
        v[pos] = v.back();
        v.pop_back();
        
        
        hp[v[pos]] = pos;
        hp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % v.size();
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
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