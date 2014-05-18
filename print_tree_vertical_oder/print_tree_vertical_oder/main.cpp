#include<iostream>
#include<map>
#include<vector>

using namespace std;

typedef struct n {
	int key;
	struct n*left;
	struct n*right;
}node;

node *newNode(int n){
	node *temp = (node *)malloc(sizeof(node));
	temp->key = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void pushMap(node *root,int hd, map<int,vector<int>> &M){
	if(root==NULL)
		return;
	M[hd].push_back(root->key);
	pushMap(root->left,hd-1,M);
	pushMap(root->right,hd+1,M);
}
void getVerticalOrder(node *root){
	int hd = 0;
	map<int, vector<int>> M;
	pushMap(root,0,M);

	for(map< int, vector<int> >::iterator it = M.begin(); it!=M.end();it++)
	{
		for(int i=0;i<it->second.size();i++)
			cout<<it->second[i]<<" ";
		cout<<endl;
	}
}

int main(){
	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";

	getVerticalOrder(root);
	int k;
	cin>>k;
	return 0;
}