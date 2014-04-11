#include<iostream>
using namespace std;
#ifndef tree_h

#define tree_h
template <class T> class tree;

template <class T>
class node{
        T value;
        node *left;
        node *right;
        node(T a);
        friend class tree<T>;
        void operator==(node *B){
                if( value == B->value )
                        return true;
                else
                        return false;
        }
};

template<class T>
node<T>::node(T a){
                value = a;
                left = NULL;
                right = NULL;
}

template< class T>
class tree{
        node<T>* root;
        node<T>* createTreeFromArray(T nodeArray[], int length, int index);
        void preOrderTraversal(node<T> * root);
        int findPath(node<T> *root, vector<node<T> *> &nodePath, node<T> *findNode);
        node<T>* LCA_func(node<T> *root, T value1, T value2);
        public:
                void createTree(T nodeArray[], int length);
                void printPreOrder();
                void printPath(T value);
                void LCA(T value1, T value2);
};

template<class T>
node<T>* tree<T>::createTreeFromArray(T nodeArray[], int length, int index){
        node<T> *treeNode = new node<T>(nodeArray[index]);
        if (2*index < length)
                treeNode->left = createTreeFromArray(nodeArray, length, 2*index);
        if (( 2*index + 1) < length)
                treeNode->right = createTreeFromArray( nodeArray, length, 2*index + 1 );
        return treeNode;
}

template<class T>
void tree<T>::preOrderTraversal(node<T> * root){
        if(root == NULL)
                return;
        cout<<root->value<<" "<<endl;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
        return;
}

template<class T>
void tree<T>::createTree(T nodeArray[], int length){
        root = createTreeFromArray(nodeArray, length, 1);
}

template<class T>
void tree<T>::printPreOrder(){
        preOrderTraversal(root);
}

template<class T>
int tree<T>::findPath(node<T> *root, vector<node<T> *> &nodePath, node<T> *findNode){
        if( root != NULL )
        {
                nodePath.push_back(root);
                if ( root->value == findNode->value ){
                        return 1;
                }
                if( findPath(root->left, nodePath, findNode) || findPath(root->right, nodePath, findNode))
                        return 1;
                nodePath.pop_back();
        }
        return 0;
}

template<class T>
void tree<T>::printPath( T value){
        vector<node<T> *> nodePath;
        node<T> *findNode = new node<T>(value);
        findPath(root, nodePath,findNode);
        cout<<nodePath.size()<<endl;
        for(int i=0;i<nodePath.size();i++)
                cout<<nodePath[i]->value<<" ";
}

template<class T>
void tree<T>::LCA(T value1, T value2){
        node<T> *ancestor = LCA_func(root,value1,value2);
        if(ancestor!=NULL)
                cout<<ancestor->value;
        return;
}


template<class T>
node<T>* tree<T>::LCA_func(node<T> *root, T value1, T value2){
        if(root==NULL)          return NULL;
        if(root->value == value1 || root->value == value2)      return root;

        node<T> *left = LCA_func(root->left,value1,value2);
        node<T> *right = LCA_func(root->right,value1,value2);
        if(left!=NULL && right!=NULL)
                return root;
        if(left!=NULL)  return left;
        return right;
}


#endif
