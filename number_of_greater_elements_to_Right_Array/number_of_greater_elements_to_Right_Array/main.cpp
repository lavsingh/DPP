#include <iostream>
using namespace std;

typedef struct n {
	int val;
	int numRight;
	struct n *left;
	struct n *right;
}node;

node * newNode(int k){
	node *temp = (node *)malloc(sizeof(node));
	temp->val = k;
	temp->numRight = 0;
	temp->left= NULL;
	temp->right = NULL;
	return temp;
}

node *insert(node *treeRoot, int n, int &num){
	node *t = newNode(n);
	node *root = treeRoot;
	num = 0;

	if(root ==  NULL) 
		return t;
	
	while(true){
		if(n<root->val){
			num+= root->numRight + 1;
			if(root->left){
				root= root->left;
			}
			else {
				root->left = t;
				break;
			}
		}
		else {
			root->numRight++;
			if(root->right){
				root= root->right;
			}
			else {
				root->right = t;
				break;
			}
		}
	}
	return treeRoot;
}

int main() {
	node *tree = NULL;
	int n;
	cin>>n;
	int A[100];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	while(n!=0){
		int num = 0;
		tree = insert(tree,A[n-1],num);
		cout<<num<<endl;
		n--;
	}
	cin>>n;
	return 0;
}