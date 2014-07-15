#include<iostream>

using namespace std;

typedef struct n{
	int data;
	struct n* left;
	struct n* right;
}node;

node *newNode(int n){

	node *root = (node *)malloc(sizeof(node));
	root->data = n;
	root->left = root->right = NULL;
	return root;
}

node *function(node *root, node **tail){

	if(root == NULL) return NULL;
	node *leftTail = NULL;
	node *leftHead = function (root->left, &leftTail);

	node *rightTail = NULL;
	node *rightHead = function (root->right, &rightTail);

	*tail = root;
	root->right = NULL;
	if(leftTail == NULL && rightTail == NULL){
		return root;
	}

	if(rightTail == NULL){
		leftTail->right = root;
		root->left = leftTail;
		return leftHead;
	}

	if(leftTail == NULL){

		rightTail->right = root;
		root->left = rightTail;
		return rightHead;
	}
		
	leftTail->right = rightHead;
	rightHead->left = leftTail;
	rightTail->right = root;
	root->left = rightTail;
	return leftHead;
}

void print(node *head){

	while(head!= NULL){
		cout<<head->data<<"  ";
		head = head->right;
	}
	return;
}

int main(){
	node *root= newNode(10);
	root->left = newNode(100);
	root->left->left = newNode(40);
	root->left->right = newNode(30);
	root->right = newNode(50);
	root->right->right = newNode(60);
	node *tail = NULL;
	node * head = function(root, &tail);
	print(head);

	return 0;
}