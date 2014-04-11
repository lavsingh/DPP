#include<iostream>

using namespace std;

void longestAP(int A[], int n){
	int L[100][100];
	for(int i=n-1;i>=1;i--)
		L[i-1][n-1] = 2;
	int llap=2,start=-1,diff=-1;
	for(int j=n-2;j>=1;j--)
	{
		int i=j-1,k=j+1;
		while(i>=0 && k<=n-1)
		{
			if(A[i]+A[k]<2*A[j])
				k++;
			else if(A[i]+A[k]>2*A[j]){
				L[i][j]=2;
				i--;
			}
			else {
				L[i][j]=L[j][k]+1;
				if(L[i][j]>llap){
					llap=L[i][j];
					start=i;
					diff = A[j] - A[i];
				}
				i--;
				k++;
			}
		}
		while(i>=0){
			L[i][j] = 2;
			i--;
		}
	}
	cout<<llap<<endl;
	cout<<diff<<endl;
}
int main(){
	int A[]={5,10,15,20,25,30};
	int n = 6;
	longestAP(A,n);
	cin>>n;
	return 0;

}