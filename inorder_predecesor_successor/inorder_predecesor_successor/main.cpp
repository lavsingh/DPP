#include<iostream>

using namespace std;

typedef struct n{
	int data;
	struct n* left, *right;
}node;


void function(node *root, node **pre, node **suc, int key){
	if(root== NULL) return;
	if(root->data == key) {
		if(root->left!=NULL){
			node *temp = root->left;
			while(temp->right!=NULL)
				temp = temp->right;
			*pre = temp;
		}
		if(root->right){

			node*temp = root->right;
			while(temp->left!=NULL)
				temp = temp->left;
			*suc = temp;
		}
	}

	if(root->data>key){
		*suc = root;
		function(root->left, pre, suc, key);
	}
	else {
		*pre = root;
		function(root->right, pre, suc, key);
	}
	return;

}

node *newNode(int data){
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int main(){
	node *root = newNode(50);
	root->left = newNode(30);
	root->right = newNode(70);
	root->left->left = newNode(20);
	root->left->right = newNode(40);
	root->right->left = newNode(60);
	root->right->right = newNode(80);

	node *pre = NULL, *suc= NULL;

	function(root, &pre, &suc, 40);

	cout<<pre->data<<" "<<suc->data<<endl;

	pre = NULL;
	suc= NULL;

	function(root, &pre, &suc, 65);
	cout<<pre->data<<" "<<suc->data<<endl;

	int k;
	cin>>k;
	return 0;
}