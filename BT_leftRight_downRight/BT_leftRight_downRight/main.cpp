#include<iostream>
#include<queue>

using namespace std;

typedef struct n {
	char data;
	struct n* left;
	struct n* right;
}node;

node *newNode ( char n ){
	node *root = (node *)malloc(sizeof(node));
	root->data = n;
	root->left = root->right = NULL;
	return root;
}

node *function(node *root){
	queue<node *> q;
	queue<node *> q1;
	q.push(root);
	node *start1 = NULL;
	while(!q.empty()){
		node *start, *prev;
		prev = NULL;
		start =  q.front();
		if(start1!=NULL)
			start1->left = start;
		while(!q.empty()){
			node *t = q.front();
			q.pop();
			if(t->left) 
				q1.push(t->left);
			if(t->right)
				q1.push(t->right);
			t->left = NULL;
			if(prev!=NULL)
				prev->right = t;
			
			prev = t;
		}
		prev->right = NULL;

		
		prev = NULL;
		start1 =  q1.front();
		while(!q1.empty()){
			node *t = q1.front();
			q1.pop();
			if(t->left) 
				q.push(t->left);
			if(t->right)
				q.push(t->right);
			t->left = NULL;
			if(prev!=NULL)
				prev->right = t;
			prev = t;
		}
		prev->right = NULL;
		start->left = start1;
	}
	return root;
}

void print(node *root){
	while(root!=NULL){
		node *t = root;
		while(t!=NULL){
			cout<<t->data<<" ";
			t = t->right;
		}
		cout<<endl;
		root = root->left;
	}
	return;
}
int main(){

	node *root= newNode('A');
	root->left = newNode('B');
	root->right = newNode('C');
	root->right->left = newNode('D');
	root->right->right = newNode('E');
	root->right->left->left = newNode('F');
	root->right->right->left = newNode('G');
	root->right->right->right = newNode('H');
	root = function(root);

	print(root);
	int k;
	cin>>k;
	return 0;
}