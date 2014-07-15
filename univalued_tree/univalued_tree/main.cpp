#include<iostream>
#include<map>

using namespace std;

typedef struct n{
	int data;
	struct n *left;
	struct n *right;
}node;

node * newNode(int n){
	node *t = (node *) malloc(sizeof(node));
	t->data = n;
	t->left = NULL;
	t->right = NULL;
	return t;
}



bool numUnivaluedTree(node *root, int &num){
	
	if(root==NULL) return true; 
	int localL = 0, localR = 0;
	bool left = numUnivaluedTree(root->left, localL);
	bool right = numUnivaluedTree(root->right, localR);
	if(left && right && (!root->left || root->data == root->left->data) && (!root->right || root->data == root->right->data)){
		num = 1+ localL+ localR;
		return true;
	}
	num = localL +  localR;
	return false;
}


int main(){
	int n;
	cin>>n;
	int kk;
	int i=0;
	if(n<=0){
		cout<<0<<endl;
		return 0;
	}
	map<int,node *> h;
	while(i<n){
		cin>>kk;
		node *temp = newNode(kk);
		h[i] = temp;
		i++;
	}
	int p1,r1;
	i=0;
	while(i<n-1){
		cin>>p1>>r1;

		node *root = h[p1];
		if(root->left == NULL)
			root->left = h[r1];
		else
			root->right = h[r1];
		i++;
	}
	node *root = h[0];

	int num = 0;
	numUnivaluedTree(root,num);
	cout<<num<<endl;

	return 0;
}