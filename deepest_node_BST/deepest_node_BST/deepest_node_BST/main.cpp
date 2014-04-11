#include<iostream>
#include "tree.h"
using namespace std;


int main(){
	
	tree <int> myTree;
	int num;
	cin>>num;
	int A[100];
	for(int i=0;i<num;i++)
		cin>>A[i];
	myTree.createTree(A,num);
	
	return 0;
}