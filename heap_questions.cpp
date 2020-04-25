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

int connectSticks(vector<int> &sticks){

	priority_queue<int, vector<int>, greater<int> > pq;

	for(int val:sticks){
		pq.push(val);
	}

	int sum = 0;

	while(pq.size() > 1){
		int first = pq.top();
		pq.pop();

		int second = pq.top();
		pq.pop();

		sum += first + second;
		pq.push(first + second);
	}

	return sum;
}

int findKthLargest(vector<int>& nums, int k) {
        
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }
    
    for(int i=k;i<nums.size();i++){
        if(nums[i] > pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    
    return pq.top();
}



int main(){


	return 0;
}