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

node* kAppend(node* &head, long k){
    node* slow = head;
    node* fast = head;

    int c = 1;
    while(c<k){
        fast = fast->next;
        c++;
    }

    node* prev;

    while(fast->next != NULL){
        prev = slow;
        fast = fast->next;
        slow = slow->next;
    }

    fast->next = head;
    head = slow;
    prev->next = NULL;

    return head;
}

int main() {
    
    node* head = NULL;
    long n,k;
    int data;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,data);
    }
    cin>>k;
    k = k%n;
    if(k==0){
        display(head);
    }
    else{
        head = kAppend(head,k);
        display(head);
    }
}