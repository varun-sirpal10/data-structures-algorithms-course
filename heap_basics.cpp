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

bool myCompare(int a, int b){
	return a>b;
}

void display(vector<int> &v){
	for(int val:v){
		cout<<val<<" ";
	}
	cout<<endl;
}

void downHeapify(vector<int> &v, int idx, int n){

	int leftChild = 2*idx + 1;
	int rightChild = 2*idx + 2;

	if (leftChild >= n and rightChild >= n)
	{
		return;
	}

	int largestIdx = idx;
	if(leftChild < n and myCompare(v[leftChild],v[largestIdx])){
		largestIdx = leftChild;
	}
	if(rightChild < n and myCompare(v[rightChild],v[largestIdx])){
		largestIdx = rightChild;
	}

	if(largestIdx != idx){
		swap(v[largestIdx],v[idx]);
		downHeapify(v,largestIdx,n);
	}
}

void arrayToHeap(vector<int> &v){

	int n = v.size();
	int start = n/2 - 1;

	for(int i=start;i>=0;i--){
		downHeapify(v,i,n);
	}
}

void heapSort(vector<int> &v){

	arrayToHeap(v);

	for(int i=v.size()-1;i>=1;i--){
		swap(v[0],v[i]);
		downHeapify(v,0,i);
	}
}

int main(){

	vector<int> v;
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin>>x;
		v.push_back(x);	
	}

	// arrayToHeap(v);
	// display(v);

	heapSort(v);
	display(v);	

	return 0;
}

// 11 
// 100 40 435 2 9 20 10 20 35 38 45