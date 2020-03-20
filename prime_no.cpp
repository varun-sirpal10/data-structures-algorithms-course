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

#define ll long long int 

//Root-n method - O(sqrt(n))
bool isPrime(int n){

	if(n==1){
		return false;
	}

	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

//Prime Sieve - Generate an array of prime numbers - O(NLogLogN)
void primeSieve(int p[]){

	//mark all odd numbers as prime
	for(int i=3;i<=1000000;i+=2){
		p[i] = 1;
	}

	//Sieve
	for(ll i=3;i<=1000000;i+=2){
		if(p[i]==1){
			for(ll j=i*i;j<=1000000;j+=i){
				p[j] = 0;
			}
		}
	}

	p[0]=p[1]=0;
	p[2]=1;
}

int main(){

	// int n = 16;

	// if(isPrime(n)){
	// 	cout<<"Prime number."<<endl;
	// }
	// else{
	// 	cout<<"Not prime."<<endl;
	// }

	int n=20;
	int p[1000005] = {0};

	int csum[1000005] = {0};
	primeSieve(p);

	// for(int i=0;i<1000005;i++){
	// 	if(p[i]==1){
	// 		cout<<i<<" ";
	// 	}
	// }

	for(int i=0;i<1000000;i++){
		csum[i] = csum[i-1] + p[i];
	}

	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<csum[b] - csum[a-1]<<endl;
	}

	return 0;
}