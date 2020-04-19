#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) {
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* builtBST(TreeNode* root, int data) {
	if (root == NULL) {
		return new TreeNode(data);
		// root = new TreeNode(data);
		// return root;
	}

	if (root->val > data) {
		root->left = builtBST(root->left, data);
	} else {
		root->right = builtBST(root->right, data);
	}

	return root;
}

TreeNode* insert() {

	TreeNode* root = NULL;

	int data;
	cin >> data;

	while (data != -1) {
		root = builtBST(root, data);
		cin >> data;
	}

	return root;
}

void inOrder(TreeNode* root) {
	if (root == NULL) return;

	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

bool searchBST(TreeNode* root, int key){

	if(root == NULL){
		return false;
	}

	if(root->val == key){
		return true;
	}

	if(key > root->val){
		return searchBST(root->right,key);
	}
	else{
		return searchBST(root->left,key);
	}
}

int main(){
	TreeNode* root = insert();

	// inOrder(root);
	// cout<<endl;

	cout<<searchBST(root,5)<<endl;
	cout<<searchBST(root,21)<<endl;



}


// 4 2 1 3 6 5 7 -1
