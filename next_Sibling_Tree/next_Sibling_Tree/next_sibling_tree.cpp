#include<iostream>
#include <vector>
#include "tree.h"

using namespace std;
int main(){
	int num;
	cin>>num;
	int A[100];
	for(int i=0;i<num;i++)
		cin>>A[i];

	tree <int> myTree;
	myTree.createTree(A,num);
	
	myTree.printPreOrder();
	cin>>num;
	return 0;
}
