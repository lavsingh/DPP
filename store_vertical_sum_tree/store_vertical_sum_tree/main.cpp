#include<iostream>
#include<map>
using namespace std;

typedef struct n {
	int data;
	struct n* left;
	struct n*right;
}node;

node *newNode(int data){
	node *root = (node *)malloc(sizeof(node));
	root->data = data;
	root->left = root->right = NULL;
	return root;
}

void function(node *root, map<int,int> *sum , int level){
	if(root == NULL)
		return;
	map<int,int>::iterator it;
	it = (*sum).find(level);

	if(it != (*sum).end())
		(*sum)[level] = root->data + (*sum).find(level)->second;
	else
		(*sum)[level] = root->data;

	function(root->left, sum, level -1);
	function(root->right, sum, level + 1);
	return;
}
int main(){
	int level = 0;

	node *root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(40);
	root->left->left = newNode(100);
	root->right->left = newNode(30);
	root->right->right = newNode(80);
	map<int,int> sum;
	function(root, &sum, level);

	map<int, int>::iterator it;
	for(it = sum.begin(); it!=sum.end(); it++){
		cout<< it->first << " " << it->second<<endl;
	}
	int k;
	cin>>k;
	return 0;
}