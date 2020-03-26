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

void dutchNationalFlagAlgo(int arr[]){
	int mid = 0, low=0, high=arr.size()-1;

	while(mid<=high){
		if(arr[mid]==1){
			mid++;
		}
		else if(arr[mid]==2){
			swap(arr[mid],arr[high]);
			high--;
		}
		else{
			swap(arr[mid],arr[low]);
			low++;
			mid++;
		}
	}

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
}

int main(){

	int arr[] = {1,2,1,1,0,1,0,2,1};

	dutchNationalFlagAlgo(arr);
	return 0;
}