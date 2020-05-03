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

bool subarraySumK(int arr[], int n, int k) {
	unordered_map<int, int> hp;

	int sum = 0;

	for(int i=0;i<n;i++){
		sum += arr[i];

		if(hp.count(sum)){
			return true;
		}
	}


}

int main(){

	// int arr[] = {1,2,3,-3,4,5,4};
	// int n = 7;
	// cout<<subArrayWithSumZero(arr,n)<<endl;

	int arr[] = {1, 2, 3, 4, 2, 1, 7};
	int n = 7;
	int k = 7;

	cout << subarraySumK(arr, n, k) << endl;

	return 0;
}