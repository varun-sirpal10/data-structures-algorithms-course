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

int main(){
	vector<int> heap;
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin>>x;
		insert(heap,x);
	}
	display(heap);
	return 0;
}