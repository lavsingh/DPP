#include<iostream>

using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

typedef struct node_t node_t;

/* Binary tree node */
struct node_t
{
    int data;
    int lCount;

    node_t* left;
    node_t* right;
};

/* Iterative insertion
   Recursion is least preferred unless we gain something
*/
node_t *insert_node(node_t *root, node_t* node)
{
    /* A crawling pointer */
    node_t *pTraverse = root;
    node_t *currentParent = root;

    // Traverse till appropriate node
    while(pTraverse)
    {
        currentParent = pTraverse;

        if( node->data < pTraverse->data )
        {
            /* We are branching to left subtree
               increment node count */
            pTraverse->lCount++;
            /* left subtree */
            pTraverse = pTraverse->left;
        }
        else
        {
            /* right subtree */
            pTraverse = pTraverse->right;
        }
    }

    /* If the tree is empty, make it as root node */
    if( !root )
    {
        root = node;
    }
    else if( node->data < currentParent->data )
    {
        /* Insert on left side */
        currentParent->left = node;
    }
    else
    {
        /* Insert on right side */
        currentParent->right = node;
    }

    return root;
}


/* Elements are in an array. The function builds binary tree */
node_t* binary_search_tree(node_t *root, int keys[], int const size)
{
    int iterator;
    node_t *new_node = NULL;

    for(iterator = 0; iterator < size; iterator++)
    {
        new_node = (node_t *)malloc( sizeof(node_t) );

        /* initialize */
        new_node->data   = keys[iterator];
        new_node->lCount = 0;
        new_node->left   = NULL;
        new_node->right  = NULL;

        /* insert into BST */
        root = insert_node(root, new_node);
    }

    return root;
}

int kthSmallest(node_t *root, int k, node_t **kth){
	if(*kth != NULL || k<0) return 0;
	if(root == NULL) return 0;
	int nodes = 0;
	int leftNodes = kthSmallest(root->left, k , kth);
	nodes = leftNodes + 1;
	if( nodes == k )
		*kth = root;
	int rightNodes = kthSmallest(root->right, k - nodes , kth);
	nodes+= rightNodes;
	return nodes;
}

int main(){
	int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
    int i;
	node_t* root = NULL;

    /* Creating the tree given in the above diagram */
    root = binary_search_tree(root, ele, ARRAY_SIZE(ele));
	node_t *k = NULL;
	kthSmallest(root, 4, &k);
	cout<<k->data<<endl;
	k = NULL;
	kthSmallest(root, 1, &k);
	cout<<k->data<<endl;
	k = NULL;
	kthSmallest(root, 7, &k);
	cout<<k->data<<endl;
	k = NULL;
	kthSmallest(root, 3, &k);
	cout<<k->data<<endl;
	int m;
	cin>>m;
	return 0;
}