#include<iostream>

using namespace std;
typedef struct n{
	int data;
	struct n *left;
	struct n *right;
}node;

node *newNode(int data){
	node *root = (node *)malloc(sizeof(node));
	root->data = data;
	root->left = root->right = NULL;
	return root;
}
node *function(int a[], int min, int max, int *postindex, int key){

	if(postindex<0)
		return NULL;
	node *root = NULL;
	
	if(key > min && key < max){
		root = newNode(a[*postindex]);
		*postindex = *postindex - 1;
		if(*postindex >= 0){
			root->right = function(a, key, max, postindex, a[*postindex]);
			root->left = function(a, min, key, postindex, a[*postindex]);
		}
	}
	return root;
}

void printTree(node *root){

	if(root == NULL)
		return;
	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);
	return;
}

int main(){

	int a[]={1,7,5,50,40,10};
	int postindex = 5;
	node *root = function(a, INT_MIN, INT_MAX, &postindex, a[5]);
	printTree(root);
	int k;
	cin>>k;
	return 0;
}