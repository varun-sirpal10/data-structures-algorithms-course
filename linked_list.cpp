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

void deleteAtIndex(node* &head, int idx){
	if(head==NULL){
		return;
	}
	if(head->next == NULL){
		deleteAtHead(head);
		return;
	}
	node* temp = head;
	int jump = idx - 2;
	while(jump>0){
		temp = temp->next;
		jump--;
	}
	node* toBeDeleted = temp->next;
	temp->next = toBeDeleted->next;
	delete toBeDeleted;
}

node* midPointOfLinkedList(node* head){
	node* slow = head;
	node* fast = head;

	while(fast->next!=NULL and fast->next->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

void reverseIterative(node* &head){
	node* prev = NULL;
	node* curr = head;

	while(curr!=NULL){
		node* n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}

	head = prev;
}

node* reverseRecursive(node* &head){

	if(head==NULL or head->next==NULL){
		return head;
	}

	node* newHead = reverseRecursive(head->next);

	node* curr = head;
	curr->next->next = curr;
	curr->next = NULL;
	return newHead;
}

node* merge2LinkedList(node* a, node* b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}

	node* result = NULL;
	if(a->data <= b->data){
		result = a;
		result->next = merge2LinkedList(a->next,b);
	}
	else{
		result = b;
		result->next = merge2LinkedList(a,b->next);
	}
	return result;
}

node* kthNodeFromEnd(node* head, int K){
	node* slow = head;
	node* fast = head;

	int count = 1;
	while(count<=K){
		fast = fast->next;
		count++;
	}

	while(fast!=NULL){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

node* mergeSort(node* head){
	if(head->next == NULL or head==NULL){
		return head;
	}

	node* mid = midPointOfLinkedList(head);

	node* merge1 = mergeSort(mid->next);

	mid->next = NULL;

	node* merge2 = mergeSort(head);

	node* sorted = merge2LinkedList(merge1,merge2);
	return sorted;
}

node* kReverse(node* head, int K){
	if(head==NULL or head->next==NULL){
		return head;
	}

	int count=1;
	node* prev = NULL;
	node* curr = head;
	node* n = NULL;

	while(curr != NULL and count<=K){
		n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
		count++;
	}

	head -> next = kReverse(n,K);

	return prev;
}

void printInReverse(node* head){
	if(head==NULL){
		return;
	}

	printInReverse(head->next);
	cout<<head->data<<" -> ";
}

bool helper(node* right){
	if(right==NULL){
		return true;
	}

	bool recursionResult = helper(right->next);

	bool ans = true;

	if(recursionResult == false or left->data != right->data){
		ans = false;
	}

	left = left->next;
	return ans;
}

node* left;
bool isPalindrome(node* head){

	left = head;
	return helper(head);
}

bool hasCycle(node* head){
	node* slow = head;
	node* fast = head;

	while(fast!=NULL and fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;

		if(slow==fast){
			return true;
		}
	}
	return false;
}

int main(){

	//node*head = NULL;

	//display(head);

	// insertAtHead(head,3);
	// insertAtHead(head,2);
	// insertAtHead(head,1);

	// //display(head);

	// insertAtTail(head,4);
	// insertAtTail(head,7);

	// //display(head);

	// //deleteAtHead(head);

	// //display(head);

	// //deleteAtTail(head);

	// //display(head);

	// //cout<<lengthOfLinkedList(head)<<endl;

	// //searchLinkedList(head,5);

	// insertAtMiddle(head,9,3);
	// insertAtMiddle(head,6,3);

	// display(head);

	//deleteAtIndex(head,3);
	//display(head);

	// node* midPoint = midPointOfLinkedList(head);
	// cout<<midPoint->data<<endl;

	// reverseIterative(head);
	// display(head);

	// head = reverseRecursive(head);
	// display(head);

	node* head = NULL;

	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 3);
	insertAtTail(head, 2);
	insertAtTail(head, 1);

	display(head);


	// int K = 2;

	// node* kthNode = kthNodeFromEnd(head,K);
	// cout<<kthNode->data<<endl;

	// node* merge = mergeSort(head);
	// display(merge);

	// node* klist = kReverse(head,3);
	// display(klist);

	// printInReverse(head);

	// bool res = isPalindrome(head);
	// cout<<res<<endl;

	// node* head2 = NULL;

	// insertAtTail(head2, 2);
	// insertAtTail(head2, 4);
	// insertAtTail(head2, 6);
	// insertAtTail(head2, 7);

	// cout << "First Linked List ******************" << endl;
	// display(head1);

	// cout << "Second Linked List ******************" << endl;
	// display(head2);

	// node* mergedList = merge2LinkedList(head1, head2);

	// cout << "Merged Linked List ******************" << endl;
	// display(mergedList);

	return 0;
}