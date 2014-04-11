#include<iostream>

using namespace std;

void printList(int A[],int index[], int n){
	for(int i=1;i<=n;i++)
		cout<<A[index[i]]<<" ";
	cout<<endl;
}

void solve(int A[], int size, int index[], int n,int sum, int target){
	if(sum > target) return;
	if(sum == target) {
		printList(A,index,n);
	}
	for(int i = index[n]; i<size; i++ ){
		index[n+1] = i+1;
		solve(A, size, index,n+1,sum+A[i+1],target);
	}
	return;
}

int main(){
	int A[7] = {3,1,2,7,6,1,5};
	int index[10];
	index[0] = -1;
	int target = 8;
	solve(A,7,index,0, 0, target);
	cin>>target;
	return 0;
}