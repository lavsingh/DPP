#include<iostream>

using namespace std;

typedef struct n {
	int data;
	struct n*left;
	struct n* right;
}node;

node *newNode(int n){
	node *root = (node *)malloc(sizeof(node));
	root->data = n;
	root->left = root->right = NULL;
	return root;
}

int maxDepth(node *root, int *max){
	if(root == NULL) return 0;
	int left = maxDepth(root->left, max);
	int right = maxDepth(root->right, max);
	if((left + right + root->data )> *max)
		*max = left + right + root->data;
	return root->data+(left>right?left:right);
}

int main(){
	node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
	int max = 0;
	maxDepth(root,&max);
	cout<<max;
	return 0;
}