#include<iostream>

using namespace std;

class Stack{

	int* arr;
	int top;
	int maxSize;

public:
	Stack(int capacity = 5){
		this->top = -1;
		this->maxSize = capacity;
		this->arr = new int[this->maxSize];
	}

	void push(int data){
		if(this->top == this->maxSize - 1){
			cout<<"Stack is full."<<endl;
			return;
		}

		this->top++;
		this->arr[this->top] = data;
	}

	void pop(){
		if(this->top == -1){
			cout<<"Stack is empty."<<endl;
			return;
		}

		this->top--;
	}

	int getTop(){
		return this->arr[this->top];
	}

	int size(){
		return this->top + 1;
	}

	bool empty(){
		return this->size() == 0;
	}
};

int main(){

	Stack s;

	s.push(3);
	s.push(2);
	s.push(45);
	s.push(37);
	s.push(9);

	s.push(789);

	s.pop();
	s.pop();

	cout << s.size() << endl;

	s.pop();

	cout << s.getTop() << endl;

	s.pop();
	s.pop();
	s.pop();

	cout << s.empty() << endl;

	return 0;
}