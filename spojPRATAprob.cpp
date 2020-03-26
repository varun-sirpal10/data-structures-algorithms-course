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

bool isPossible(int arr[], int P, int L, int minTime){
	int prata = 0;

	for(int i=0;i<L;i++){

		int time = 0;
		int n = 1;

		while(time + arr[i]*n <= minTime){
			time += arr[i]*n;
			n++;
			prata++;
			if(prata>=P){
				return true;
			}
		}
	}
	return false;
}

int PRATAProblem(int arr[], int P, int L){
	int start = 1;
	int end = INT_MIN;

	end = arr[L-1]*(P)*(P+1)/2;

	int ans=-1;

	while(start <= end){
		int mid = start + (end-start)/2;

		if(isPossible(arr,P,L,mid)){
			ans = mid;
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	return ans;
}

int main(){

	int t;
	cin>>t;
	while(t--){
		int P,L;
		int arr[1000];
		cin>>P;
		cin>>L;
		for(int i=0;i<L;i++){
			cin>>arr[i];
		}
		sort(arr,arr+L);

		cout<<PRATAProblem(arr,P,L)<<endl;
	}
	return 0;
}