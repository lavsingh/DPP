#include<iostream>
#include<string>
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

void serialize(node *root, string &S){
	if(root==NULL){
		S.append("*");
		return;
	}
	char *p = new char[10];
	itoa(root->data,p,10);
	S.append(p);
	S.append(" ");
	serialize(root->left,S);
	S.append(" ");
	serialize(root->right,S);
	return;
}

node *deserialize(string &s){
	int pos = s.find(' ');
	string t = s.substr(0, pos);
	
	s = s.substr(pos+1);
	if(t == "*")
		return NULL;
	
	node *root = newNode(stol(t,0,10));
	root->left = deserialize( s );
	root->right = deserialize(s);
	return root;

}

void inorder (node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);

	return;
}

int main(){
	
	node *root = newNode(10);
	root->left = newNode(100);
	root->right = newNode(4);
	root->left->left = newNode(6);
	root->left->right = newNode(19);
	root->right->right = newNode(102);
	string sss;
	serialize(root, sss);
	cout<<sss;

	node *tree = deserialize(sss);
	inorder(tree);

	return 0;
}