#include <iostream>
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
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	//cout<<"NULL "<<endl;
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

int main() {
    
    node* head = NULL;
    long n,k;
    int data;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,data);
    }
    //display(head);
    head = kReverse(head,k);

    display(head);
}