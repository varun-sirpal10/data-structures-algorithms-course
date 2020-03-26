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

void waveSort(int arr[], int size){
	for(int i=0;i<size;i+=2){
		if(i>0 && arr[i]<arr[i-1]){
			swap(arr[i],arr[i-1]);
		}
		if(i<size-1 && arr[i+1]>arr[i]){
			swap(arr[i],arr[i+1]);
		}
	}

	for(int j=0;j<size;j++){
		cout<<arr[j]<<" ";
	}
}
int main(){
	int arr[] = {1,3,4,2,7,8};
	int n = 6;

	waveSort(arr,n);
}