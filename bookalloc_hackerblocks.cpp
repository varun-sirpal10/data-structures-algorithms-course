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

bool canWeAllot(int arr[], int n, int b, int minSum){
    
    int stud = 1;
    int books = arr[0];
    
    for(int i=1;i<n;i++){
        books += arr[i];
        
        if(books > minSum){
            stud++;
            books = arr[i];
        }

        // if(arr[i]>minSum){
        //     return false;
        // }

        if(stud > b){
            return false;
        }
    }
    return true;
}

int books(int arr[], int n, int b) {
    
    int minSum = arr[0];
    int maxSum = arr[0];
    
    for(int i=1;i<n;i++){
        if(arr[i] > minSum){minSum = arr[i];}
        maxSum += arr[i];
    }
    
    int start = minSum;
    int end = maxSum;
    
    int ans;
    
    if(b > n){
        return -1;
    }
    
    while(start <= end){
        int mid = (start+end)/2;
        
        if(canWeAllot(arr,n,b,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
	int t;
	cin>>t;
	int arr[100];
	int n,b,i;
	while(t--){
		cin>>n>>b;
		for(i=0;i<100;i++){
			cin>>arr[i];
		}
		cout<<books(arr,n,b);
	}
	return 0;
}