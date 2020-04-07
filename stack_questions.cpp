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

bool isDuplicate(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		char ch = str[i];
		if(ch != ')'){
			s.push(ch);
		}

		else{
			if(s.top() == '('){
				return true;
			}

			while(s.top() != '('){
				s.pop();
			}
			s.pop();
		}
	}
	return false;
}

void nextGreater(int arr[], int n){

	stack<int> s;

	for(int i=0;i<n;i++){

		while(!s.empty() and s.top()<arr[i]){
			int temp = s.top();
			s.pop();
			cout<<temp<<" -> "<<arr[i]<<endl;
		}

		s.push(arr[i]);
	}

	while(!s.empty()){
		int temp = s.top();
		s.pop();
		cout<<temp<<" -> "<<-1<<endl;
	}
}

void stockSpanProblem(int arr[], int n){

	stack<int> s;

	for(int i=0;i<n;i++){

		while(!s.empty() and arr[s.top()] <= arr[i]){
			s.pop();
		}

		if(s.empty()){
			cout<<arr[i]<<" -> "<<i+1<<endl;
		}
		
		else{
			int idx = s.top();
			cout<<arr[i]<<" -> "<<(i - s.top())<<endl;
		}

		s.push(i);
	}
}

void nextSmaller(int arr[], int n){

	int result[n];

	stack<int> s;

	for(int i=0;i<n;i++){

		while(!s.empty() and arr[s.top()] > arr[i]){
			result[s.top()] = arr[i];
			s.pop();
		}

		s.push(i);
	}

	while(!s.empty()){
		result[s.top()] = -1;
		s.pop();
	}

	for(int j=0;j<n;j++){
		cout<<arr[j]<<" -> "<<result[j]<<endl;
	}
}

int histogramArea(int arr[], int n){
	
	stack<int> s;

	int maxArea = INT_MIN;

	int i=0;

	while(i<n){

		if(s.empty() or arr[s.top()] <= arr[i]){
			s.push(i);
			i++;
		}

		else{

			int extractedTop = s.top();
			s.pop();
			int height = arr[extractedTop];

			int currArea;

			if(s.empty()){
				currArea = height*i;
			}
			else{
				currArea = height*(i - s.top() - 1);
			}
			
			maxArea = max(maxArea,currArea);
		}
	}

	while(!s.empty()){

		int extractedTop = s.top();
		s.pop();
		int height = arr[extractedTop];

		int currArea;

		if(s.empty()){
			currArea = height*i;
		}
		else{
			currArea = height*(i - s.top() - 1);
		}
		
		maxArea = max(maxArea,currArea);
	}

	return maxArea;
}

int main(){

	// string str = ")))(((";
	// cout<<balancedParanthesis(str)<<endl;

	// string str = "((a+b)+((c+d)))";
	// string str = "((a+(b))+(c+d))";
	// cout<<duplicateParenthesis(str)<<endl;

	// int arr[] = {100,80,60,70,60,75,85};
	// int n = 7;
	// stockSpanProblem(arr,n);	

	// int arr[] = {59,8,7,12,2,14};
	// nextGreater(arr,6);

	// int arr[] = {2,3,1,5,6,2};
	// int n = 6;
	// nextSmaller(arr,n);

	int arr[] = {6, 2, 5, 4, 5, 1, 6};
	int n = 7;

	cout << histogramArea(arr, n) << endl;

	return 0;
}