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

TreeNode* builtTree(TreeNode* root) {

	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	if (root == NULL) {
		root = new TreeNode(data);
	}

	root->left = builtTree(root->left);
	root->right = builtTree(root->right);

	return root;
}

void preOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	cout << root->val << " ";

	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	postOrder(root->left);
	postOrder(root->right);

	cout << root->val << " ";
}

int countNodes(TreeNode* root) {
	if (root == NULL) {
		return 1;
	}

	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	int total = leftCount + rightCount;
	return total;
}

// Inorder HomeWork
void inOrder(TreeNode* root) {
	if(root == NULL){
		return;
	}

	inOrder(root->left);

	cout<<root->val<<" ";
	
	inOrder(root->right);

}

int sumOfNodes(TreeNode* root) {
	if(root->left == NULL or root->right == NULL){
		return root->val;
	}

	int leftSum = 0, rightSum = 0;

	leftSum = sumOfNodes(root->left);
	rightSum = sumOfNodes(root->right);

	int total = leftSum + rightSum + root->val;

	return total;
}

bool search(TreeNode* root, int key) {

	if(root == NULL){
		return false;
	}

	if(key == root->val){
		return true;
	}

	bool resLeft = search(root->left, key);
	bool resRight = search(root->right, key);

	if(resLeft or resRight){
		return true;
	}

	return false;
}

int height(TreeNode* root) {

	if(root == NULL){
		return -1;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return max(leftHeight,rightHeight) + 1;
}	

int replaceNodesWithSumOfChildren(TreeNode* root){
	if(root == NULL){
		return 0;
	}

	if(root->left == NULL and root->right == NULL){
		return root->val;
	}

	int leftSum = replaceNodesWithSumOfChildren(root->left);
	int rightSum = replaceNodesWithSumOfChildren(root->right);

	int prevRoot = root->val;
	int total = leftSum + rightSum;
	root->val = total;

	return total + prevRoot;
}

int main() {

	TreeNode* root = NULL;

	root = builtTree(root);

	// preOrder(root);
	// cout << endl;

	// postOrder(root);
	// cout << endl;

	// cout << countNodes(root) << endl;

	// inOrder(root);
	// cout<<endl;

	// cout<<sumOfNodes(root)<<endl;

	// cout<<search(root,13)<<endl;

	// cout<<height(root)<<endl;

	int result = replaceNodesWithSumOfChildren(root);
	cout<<result<<endl;
	preOrder(root);

	return 0;
}

// Input Tree
// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

// 1 -1 2 3 -1 5 6 -1 -1 7 -1 -1 4 -1 -1

// Balanced Input
// 1 2 -1 -1 3 -1 4 -1 6 -1 -1

// Left View
// 1 2 4 -1 6 -1 -1 -1 3 -1 5 7 9 -1 -1 10 11 -1 -1 -1 8 -1 -1