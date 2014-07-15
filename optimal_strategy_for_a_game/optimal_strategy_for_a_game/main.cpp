#include<iostream>

using namespace std;

int optimalStrategyOfGame(int A[], int n){
	int MAX[7][7];
	for(int i=0;i<n;i++){
		MAX[i][i] =  A[i];
		if(i<n){
			MAX[i][i+1] = A[i]>A[i+1]?A[i]:A[i+1];
		}
	}

	for(int i=2;i<n;i++){
		for(int j=0;j<n-i;j++){
			int first = A[j] + (MAX[j+2][j+i]<MAX[j+1][j+i-1]?MAX[j+2][j+i]:MAX[j+1][j+i-1]);
			int last = A[j+i] + (MAX[j][j+i-2]<MAX[j+1][j+i-1]?MAX[j+2][j+i]:MAX[j+1][j+i-1]);
			MAX[j][j+i] = first > last ? first:last;
		}
	}
	return MAX[0][n-1];
}

int main(){
	int arr1[] = {20, 30, 2, 2, 2, 10};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    printf("%d\n", optimalStrategyOfGame(arr1, n));
	int k;
	cin>>k;
	return 0;
}