#include<iostream>
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

bool canWeAllot(vector<int> &arr, int n, int b, long minSum){
    
    int stud = 1;
    long books = arr[0];
    
    for(int i=1;i<n;i++){
        books += arr[i];
        
        if(books > minSum){
            stud++;
            books = arr[i];
        }
        
        if(arr[i]>minSum){
            return false;
        }
        
        if(stud > b){
            return false;
        }
    }
    return true;
}
int Solution::books(vector<int> &arr, int b) {
    
    int n = arr.size();
    long minSum = arr[0];
    long maxSum = 0;
    
    for(int i=0;i<arr.size();i++){
        if(arr[i]>minSum){minSum = arr[i];}
        maxSum += arr[i];
    }
    
    long start = minSum;
    long end = maxSum;
    
    long ans;
    
    if(b > n){
        return -1;
    }
    
    while(start <= end){
        long mid = (start+end)/2;
        
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