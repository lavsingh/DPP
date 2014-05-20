#include<iostream>

using namespace std;

typedef struct n {
	int data;
	struct n *left;
	struct n *right;
	struct n *sibling;
}node;

node *newNode(int n){
	node *temp = (node *)malloc(sizeof(node));
	temp->data = n;
	temp->left = temp->sibling =  temp->right = NULL;
	return temp;
}

node *updateSiblingPointer(node *root){
	node *temp = root;
	node *next, *t = NULL;
	while(1){
		next = NULL;
		while(temp!=NULL){
			if(temp->left){
				if(next == NULL){
					next = temp->left;
					t = next;
				}
				else {
					t->sibling = temp->left;
					t = temp->left;
				}
			}
			if(temp->right){
				if(next == NULL){
					next = temp->right;
					t = next;
				}
				else {
					t->sibling = temp->right;
					t = temp->right;
				}
			}
			temp = temp->sibling;
		
		}
		if (next == NULL)
			break;
		temp = next;
	}
	return root;
}

void printLevelOrder(node *root){
	node *temp = NULL;
	while(1){
		temp = NULL;
		while( root != NULL ){
			cout<<root->data<<" ";
			if(root->left && temp ==  NULL){
				temp = root->left;
			}
			if(root->right && temp ==  NULL){
				temp = root->right;
			}
			root = root->sibling;
		}
		cout<<endl;
		if(temp == NULL) 
			break;
		root = temp;
	}
	return;
}

int main(){
	node *root = newNode(5);
	root->left = newNode(6);
	root->right = newNode(7);
	root->left->right = newNode(10);
	root->right->left = newNode(11);
	root->right->right = newNode(12);
	root->left->right->left = newNode(13);
	root->left->right->right = newNode(14);
	root->right->left->right = newNode(15);
	root->right->right->right = newNode(16);
	root->right->right->right->left = newNode(17);
	root->right->right->right->right = newNode(18);
	root = updateSiblingPointer(root);
	printLevelOrder(root);
	int k;
	cin>>k;
	return 0;
}