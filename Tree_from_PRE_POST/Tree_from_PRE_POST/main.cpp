/* program for construction of full binary tree */
#include<iostream>
#include <stdlib.h>

using namespace std;
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct n
{
    int data;
    struct n *left;
    struct n *right;
}node;
 
// A utility function to create a node
node* newNode (int data)
{
    node* temp = (node *) malloc( sizeof(node) );
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}

node *constructTreeUtil(int pre[],int post[], int &index, int l, int r, int size){
	if(index >=size || l>r)
		return NULL;
	node *root = newNode(pre[index]);
	index++;
	if(l==r)
		return root;
	int i=0;
	for(int i=l;i<=r;i++)
		if(pre[index] == post[i])
			break;
	if(i<=r){
		root->left = constructTreeUtil(pre, post, index, l, i, size);
		root->right = constructTreeUtil(pre, post, index, i+1, r, size);
	}
	return root;

}

node *constructTree(int pre[],int post[], int size){
	int index = 0;
	node *root = constructTreeUtil(pre,post,index,0,size-1,size);
	return root;
}

// A utility function to print inorder traversal of a Binary Tree
void printInorder (node* root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}
 
// Driver program to test above functions
int main ()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    node *root = constructTree(pre, post, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
	int k;
	cin>>k;
    return 0;
}