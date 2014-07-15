#include<iostream>
using namespace std;

typedef struct n {
	int data;
	struct n *left;
	struct n *right;
}node;

node *newNode(int n){
	node *root = (node *)malloc(sizeof(node));
	root->data = n;
	root->left = root->right = NULL;
	return root;
}

node *insert(node *root, int n){
	if(root==NULL)
		return newNode(n);
	if(n<root->data)
		root->left = insert(root->left,n);
	else
		root->right = insert(root->right, n);
	return root;
}

void inorder(node *root){
	if(root== NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}

int diameter(node *root, int *max){
	if(root == NULL) return 0;
	int left = diameter(root->left, max);
	int right = diameter(root->right, max);
	*max = *max>left+right?*max:(left+right);
	return left>right?left+1:right+1;
}

int main(){
	node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 4);
	root = insert(root, 19);
	root = insert(root, 7);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 2);

	root = insert(root, 4);
	root = insert(root, 8);
	root = insert(root, 9);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, 5);
	int max = 0;
	diameter(root, &max);
	cout<<max;
	int n;
	cin>>n;
	return 0;
}