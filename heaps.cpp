#include <iostream>
#include <vector>

using namespace std;
//MAX HEAP
void upHeapify(vector<int> &heap, int idx){
	if (idx==0)
	{
		return;
	}
	int parentIdx = (idx - 1)/2;
	if(heap[parentIdx] < heap[idx]){
		int temp = heap[parentIdx];
		heap[parentIdx] = heap[idx];
		heap[idx] = temp;
		upHeapify(heap,parentIdx);
	}
	else{
		return;
	}
}

void downHeapify(vector<int> &heap, int idx){
	int leftIdx = 2*idx + 1;
	int rightIdx = 2*idx + 2;
	if(leftIdx >= heap.size() and rightIdx >= heap.size()){
		return;
	}
	int largestIdx = idx;
	if(leftIdx < heap.size() and heap[leftIdx] > heap[largestIdx]){
		largestIdx = leftIdx;
	}
	if(rightIdx < heap.size() and heap[rightIdx] > heap[largestIdx]){
		largestIdx = rightIdx;
	}
	if(largestIdx == idx) return;
	swap(heap[idx],heap[largestIdx]);
	downHeapify(heap,largestIdx);
}

void deletePeakElement(vector<int> &heap){
	swap(heap[0],heap[heap.size() - 1]);
	heap.pop_back();
	downHeapify(heap,0);
}

void insert(vector<int> &heap, int key){
	heap.push_back(key);
	upHeapify(heap,heap.size()-1);
}

void display(vector<int> &heap){
	for (int i = 0; i < heap.size(); i++)
	{
		cout<<heap[i]<<" ";
	}
	cout<<endl;
}

void buildHeapOptimized(vector<int> &heap){
	for (int i = heap.size() - 1; i >= 0; i--)
	{
		downHeapify(heap,i);
	}
}

int main(){
	vector<int> heap;
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin>>x;
		heap.push_back(x);	
		// insert(heap,x);
	}
	// display(heap);
	// deletePeakElement(heap);
	// display(heap);

	buildHeapOptimized(heap);
	display(heap);

	return 0;
}

//11 
//100 40 435 2 9 20 10 20 35 38 45