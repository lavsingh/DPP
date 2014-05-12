#include<iostream>
#include<climits>

using namespace std;
int function(int A[],int m,int B[],int n,int k){

	int i = (((m*1.0)/(m+n))*(k-1));
	int j = k-i-1;

	int Ai_1 = (i==0)?INT_MIN:A[i-1];
	int Ai = (i==m)?INT_MAX:A[i];
	int Bj_1 = (j==0)?INT_MIN:B[j-1];
	int Bj = (j==n)?INT_MAX:B[j];

	if(Ai_1<Bj && Ai>Bj)
		return Ai;
	if(Bj_1<Ai && Bj>Ai)
		return Bj;

	if(Ai>Bj)
		function(A,m,B+j+1,n-j-1,k-j-1);
	else
		function(A+i+1,m-i-1,B,n,k-i-1);

}
int main(){
	int A[5]={1,3,5,7,9};
	int B[5]={2,4,6,8,10};
	cout<<function(A,5,B,5,5);
	int k;
	cin>>k;

	return 0;

}