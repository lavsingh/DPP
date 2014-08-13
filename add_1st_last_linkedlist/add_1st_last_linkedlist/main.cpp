#include<iostream>

using namespace std;

typedef struct n {
	int data;
	struct n*next;
}node;

bool function(node **start, node *end){
	if(end==NULL)
		return 1;
	int t = function(start, end->next);
	if(end->next == *start || *start == end || t == 0)
		return 0;
	(*start)->data -= end->data;
	(*start) = (*start)->next;
	return 1;
}

node *newNode(int data){
	node *root = (node *)malloc(sizeof(node));
	root->data = data;
	root->next = NULL;
	return root;
}

int main(){
	node *root = newNode(6);
	root->next = newNode(5);
	root->next->next = newNode(4);
	root->next->next->next = newNode(3);
	root->next->next->next->next = newNode(2);
	root->next->next->next->next->next = newNode(1);
	node *start = root, *end = root;
	function(&start,end);
	while(root){
		cout<<root->data<<" ";
		root = root->next;
	}
	int k;
	cin>>k;
	return 0;
}