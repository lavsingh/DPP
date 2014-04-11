#include<iostream>
#include<climits>

using namespace std;

int floyd_warshal(int A[][5], int n, int min){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(A[i][j] > (A[i][k]+A[k][j]))
					A[i][j]=A[i][k]+A[k][j];
			}
		}
	}
	int v = n;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(A[i][j]>min)
			{	v--;
				break;
			}

	return n-v;
}

int main(){

	int A[5][5];
	for(int i=0;i<5;i++){
			for(int j=0;j<5;j++)
				A[i][j]=INT_MAX;
	}
	int s,e;
	for(int i=0;i<4;i++){
		cin>>s>>e;
		A[s-1][e-1]=1;
		A[e-1][s-1]=1;
	}
	for(int i=0;i<5;i++)
		A[i][i]=0;
	cout<<floyd_warshal(A, 5,2);

	int k;
	cin>>k;

	return 0;
}