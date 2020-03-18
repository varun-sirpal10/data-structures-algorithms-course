#include<iostream>

using namespace std;

bool isPossible(long N, long M, long X, long Y, long mid){

	long coupons = M + (N-mid)*Y;
	if(coupons >= mid*X){
		return true;
	}
	return false;
}

int scholarship(long N, long M, long X, long Y){

	long start = 0;
	long end = N;

	long ans=-1;

	while(start<=end){

		long mid = (start+end)/2;

		if(isPossible(N,M,X,Y,mid)){
			ans = mid;
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}

	return ans;

}

int main() {
	long N,M,X,Y;
	N = 10;
	M = 10;
	X = 2;
	Y = 2;

	cout<<scholarship(N,M,X,Y)<<endl;
	return 0;
}