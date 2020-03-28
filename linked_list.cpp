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

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		this->next = NULL;
	}
};

void insertAtHead(node* &head, int data){
	node* n = new node(data);
	n->next = head;
	head = n;
}

void display(node* head){
	node* temp = head;

	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<"NULL "<<endl;
}

void insertAtTail(node* &head, int data){
	if(head==NULL){
		insertAtHead(head,data);
		return;
	}

	node* temp = head;

	while(temp->next != NULL){
		temp = temp->next;
	}

	node* n = new node(data);
	temp->next = n;
}

void deleteAtHead(node* &head){
	node* temp = head;
	head = head->next;
	delete temp;
}

void deleteAtTail(node* &head){
	if(head==NULL){
		return;
	}

	if(head->next == NULL){
		deleteAtHead(head);
		return;
	}

	node*temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}

	node*n = temp->next;
	temp->next = NULL;
	delete n;
}

int lengthOfLinkedList(node* head){
	if(head==NULL){
		return 0;
	}
	if(head->next==NULL){
		return 1;
	}
	node* temp = head;
	int count = 0;
	while(temp!=NULL){
		temp = temp->next;
		count++;
	}
	return count;
}

void searchLinkedList(node* head, int data){
	int flag = 0;
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
		if(data == temp->data){
			flag = 1;
			cout<<"Element found."<<endl;
		}
	}
	if(flag==0){
		cout<<"Element not found."<<endl;
	}
}

void insertAtMiddle(node* head, int data, int pos){
	node* temp = head;
	while(pos>1){
		temp = temp->next;
		pos--;
	}
	node* n = new node(data);
	node* temp1 = temp->next;
	temp->next = n;
	n->next = temp1;
}

int main(){

	node*head = NULL;

	//display(head);

	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);

	//display(head);

	insertAtTail(head,4);
	insertAtTail(head,7);

	//display(head);

	//deleteAtHead(head);

	//display(head);

	//deleteAtTail(head);

	//display(head);

	//cout<<lengthOfLinkedList(head)<<endl;

	//searchLinkedList(head,5);

	insertAtMiddle(head,9,3);

	display(head);

	return 0;
}