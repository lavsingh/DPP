#include<iostream>
#include<vector>

using namespace std;
struct node
{
   int data;
   struct node* left;
   struct node* right;
};

struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

vector<int> min_path(node *root, int sum){
	vector<int> k;
	if(root == NULL)
		return k;
	if(!root->left && !root->right && root->data == sum){
		k.push_back(root->data);
		return k;
	}
	vector<int> left = min_path(root->left, sum - root->data);
	vector<int> right = min_path(root->right, sum - root->data);
	if(right.size()){
		right.push_back(root->data);
		return right;
	}
	if(left.size()){
		left.push_back(root->data);
		return left;
	}
	return k;
}
int main(){
	node *root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(15);
	root->left->left = newnode(7);
	vector<int> ans = min_path(root, 25);
	for(int i=0;i<ans.size(); i++)
		cout<<ans.at(i);
	int k;
	cin>>k;
	return 0;
}