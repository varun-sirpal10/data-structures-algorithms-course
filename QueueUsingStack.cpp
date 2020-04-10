#include <iostream>
#include <stack>

using namespace std;

class Queue {
	stack<int> pri;
	stack<int> sec;

public:
	void push(int x){
		this->pri.push(x);
	}

	void pop(){
		while(!this->pri.empty()){
			int temp = this->pri.top();
			this->pri.pop();
			this->sec.push(temp);
		}

		this->sec.pop();
		
		while(!this->sec.empty()){
			int temp = this->sec.top();
			this->sec.pop();
			this->pri.push(temp);
		}
	}

	int size(){
		return this->pri.size();
	}

	bool empty(){
		return this->pri.empty();
	}

	int front(){

		while(!this->pri.empty()){
			int temp = this->pri.top();
			this->pri.pop();
			this->sec.push(temp);
		}

		int result =  this->sec.top();

		while(!this->sec.empty()){
			int temp = this->sec.top();
			this->sec.pop();
			this->pri.push(temp);
		}

		return result;
	}
};

int main() {

	Queue q;

	q.push(10);
	q.push(20);	
	q.push(30);
	q.push(40);

	cout<<"Front: "<<q.front()<<endl;

	cout<<"Size: "<<q.size()<<endl;

	q.pop();
	q.pop();

	cout<<"Size: "<<q.size()<<endl;

	cout<<"Empty: "<<q.empty()<<endl;

	q.pop();
	q.pop();

	cout<<"Empty: "<<q.empty()<<endl;

	return 0;
}