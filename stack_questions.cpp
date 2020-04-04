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

bool balancedParanthesis(string str){
	stack<char> s;

	for(int i=0;i<str.length();i++){
		char ch = str[i];
		if (ch=='(')
		{
			s.push(ch);
		}
		else{
			if (s.empty())
			{
				return false;
			}
			s.pop();
		}
	}

	return s.empty();
}

bool duplicateParenthesis(string str){
	stack<char> s;
	int count;

	for(int i=0;i<str.length();i++){
		if(str[i] == ')'){
			count = 0;
			while(s.top() != '('){
				s.pop();
				count++;
			}
			s.pop();
			if(count<1){
				return true;
			}
		}
		else{
			s.push(str[i]);
		}
	}
	return false;
}

int main(){

	// string str = ")))(((";
	// cout<<balancedParanthesis(str)<<endl;

	string str = "((a+b)+((c+d)))";
	// string str = "((a+(b))+(c+d))";
	cout<<duplicateParenthesis(str)<<endl;


	return 0;
}