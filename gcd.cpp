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

int gcd(int n1,int n2){
	return n2==0?n1:gcd(n2,n1%n2);
}

int lcm(int n1, int n2){
	return n2*n1/gcd(n1,n2);
}
int main(){
	int n1=25,n2=65;
	//cin>>n1>>n2;
	cout<<gcd(n1,n2)<<endl;
	cout<<lcm(n1,n2)<<endl;
	return 0;
}