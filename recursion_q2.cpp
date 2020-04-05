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

int countMazePathDia(int sr, int sc, int er, int ec){
	if(sr==er and sc==ec){
		return 1;
	}

	if(sr>er or sc>ec){
		return 0;
	}

	int horizontal = countMazePathDia(sr,sc+1,er,ec);
	int vertical = countMazePathDia(sr+1,sc,er,ec);
	int diagonal = countMazePathDia(sr+1,sc+1,er,ec);

	return horizontal+vertical+diagonal;
}

int reduceToOne(int n){

	if(n==1){
		return 0;
	}

	int count1=INT_MAX, count2=INT_MAX, count3=INT_MAX;

	count1 = 1 + reduceToOne(n-1);

	if(n%2==0){
		count2 = 1+reduceToOne(n/2);
	}

	if(n%3==0){
		count3 = 1 + reduceToOne(n/3);
	}

	return min(count1,min(count2,count3));
}

int numSquares(int n){
	if(n==0){
		return 0;
	}

	int minValue = INT_MAX;
	for(int i=1;i*i<=n;i++){
		int abhiTakKaAnswer = numSquares(n-i*i);
		minValue = min(abhiTakKaAnswer,minValue);
	}

	return minValue+1;
}

string code[] = {" ", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeyPad(string str, string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string key = code[ch - '0'];

	for(int i=0;i<key.length();i++){
		printKeyPad(ros,ans + key[i]);
	}
}

int main(){

	// cout<<countMazePathDia(0,0,2,2)<<endl;

	// cout<<reduceToOne(10)<<endl;

	// cout<<numSquares(16)<<endl;

	printKeyPad("234","");

	return 0;
}