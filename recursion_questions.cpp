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

int countBoardPath(int start, int end){

	if(start == end){
		return 1;
	}

	if(start > end){
		return 0;
	}

	int count = 0;

	for(int dice=1;dice<=6;dice++){
		count += countBoardPath(start+dice,end);
	}

	return count;
}

int countMazePath(int sr, int sc, int er, int ec){
	if(sr == er and sc == ec){
		return 1;
	}

	if(sr > er or sc > ec){
		return 0;
	}

	int down = countMazePath(sr+1,sc,er,ec);
	int right = countMazePath(sr,sc+1,er,ec);

	int total = down + right;

	return total;
}

string removeDuplicates(string str){
	if (str.length()==0)
	{	
		return str;
	}

	char ch = str[0];
	string restOfStr = str.substr(1);
	string recursionRes = removeDuplicates(restOfStr);

	if (ch == recursionRes[0])
	{
		return recursionRes;
	}
	else{
		return ch + recursionRes;
	}
}

string addStarBetweenDuplicates(string str){
	if(str.length()==0){
		return str;
	}

	char ch = str[0];
	string ros = str.substr(1);
	string recursionRes = addStarBetweenDuplicates(ros);

	if (ch == recursionRes[0])
	{
		return ch + string("*") + recursionRes;
	}
	else{
		return ch + recursionRes;
	}
}

string moveXToEnd(string str){
	if(str.length()==0){
		return str;
	}

	char ch = str[0];
	string ros = str.substr(1);
	string recursionRes = moveXToEnd(ros);

	if (ch == 'x')
	{
		return recursionRes + ch;
	}
	else{
		return ch + recursionRes;
	}
}

string replacePi(string str){
	if(str.length()==0){
		return str;
	}
	char ch = str[0];
	string ros = str.substr(1);
	string recursionRes = replacePi(ros);

	if(ch == 'p' and recursionRes[0] == 'i'){
		return "3.14" + recursionRes.substr(1);
	}
	else{
		return ch + recursionRes;
	}
}

void printSubsequence(string str, string ans){

	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	printSubsequence(ros,ans+ch);
	printSubsequence(ros,ans);
}

void printPermutations(string str, string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}
	for(int i=0;i<str.length();i++){
		char ch = str[i];

		string ros = str.substr(0,i) + str.substr(i+1);

		printPermutations(ros,ans+ch);
	}
}

void printBoardPath(int start, int end, string path){
	if(start == end){
		cout<<path<<endl;
		return;
	}

	if(start>end){
		return;
	}


	for(int dice=1;dice<=6;dice++){
		char ch = dice + '0';
		printBoardPath(start+dice,end,path+ch);
	}
}

void printMazePath(int sr, int sc, int er, int ec, string path){
	if(sr==er and sc==ec){
		cout<<path<<endl;
		return;
	}

	if(sr > er or sc > ec){
		return;
	}

	printMazePath(sr + 1, sc, er, ec, path + "V->");
	printMazePath(sr, sc + 1, er, ec, path + "H->");
}

int main(){

	// cout<<countBoardPath(0,10)<<endl;

	// cout<<countMazePath(0,0,2,2)<<endl;

	// cout<<removeDuplicates("aabbcdggf")<<endl;

	// cout<<addStarBetweenDuplicates("helloo")<<endl;

	// cout<<moveXToEnd("xabcxxyxx")<<endl;

	// cout << replacePi("xxpiipixxppix") << endl;

	// printSubsequence("abc", "");

	// printPermutations("abc", "");

	// printBoardPath(0,3,"");

	printMazePath(0,0,2,2,"");

	return 0;
}