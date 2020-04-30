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

	int sum=0;

	for(int stick:sticks){
		pq.push(stick);
	}

	while(pq.size()>1){

		int first = pq.top();
		pq.pop();

		int second = pq.top();
		pq.pop();

		sum+=first+second;
		pq.push(first+second);
	}

	return sum;
}

int findKthLargest(vector<int>& nums, int k) {

	priority_queue<int,vector<int>, greater<int> > pq;

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

class Compare{
public:
    bool operator()(vector<int> &a, vector<int> &b){
        int x = a[0]*a[0] + a[1]*a[1];
        int y = b[0]*b[0] + b[1]*b[1];
        
        return x < y;
    }
};  
    
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    
    vector<vector<int>> res;
    
    for(vector<int> point:points){
        pq.push(point);
    }
    
    while(pq.size() > K){
        pq.pop();
    }
    
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    
    return res;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    priority_queue<pair<int,int>> pq;
    
    vector<int> res;
    
    for(int i=0;i<k;i++){
        pq.push({nums[i],i});
    }
    
    for(int i=k;i<nums.size();i++){
        pair<int,int> temp = pq.top();
        
        res.push_back(temp.first);
        
        while(!pq.empty() and pq.top().second <= i - k){
            pq.pop();
        }
        
        pq.push({nums[i],i});
    }
    
    res.push_back(pq.top().first);
    
    return res;
}

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if(maxHeap.empty() or num < maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            if(maxHeap.empty()){ return 0; }
            return (maxHeap.top()+minHeap.top())/2.0;
        }
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
    }
};


int main(){


	return 0;
}