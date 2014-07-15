#include<iostream>


using namespace std;

int num_ways(char A[], char B[], int n){

	int T[10][10];
	int F[10][10];
	memset(T,0,100*sizeof(bool));
	memset(F,0,100*sizeof(bool));
	for(int i=0;i<n;i++){
		T[i][i] = A[i]=='T'?1:0;
		F[i][i] = A[i]=='F'?1:0;
	}
	
	for(int k=1;k<n;k++){
		for(int i=0;i<n-k;i++){
			
			for(int j=i; j<i+k ; j++){
				int g = i+k;

				if(B[j]=='&'){
					T[i][g] += T[i][j]*T[j+1][g];
					F[i][g] += T[i][j]*F[j+1][g] + F[i][j]*T[j+1][g] + F[i][j]*F[j+1][g];
				}
				if(B[j]=='^'){
					T[i][g] += T[i][j]*F[j+1][g] + F[i][j]*T[j+1][g];
					F[i][g] += F[i][j]*F[j+1][g] + T[i][j]*T[j+1][g];
				}
				if(B[j]=='|'){
					T[i][g] += T[i][j]*T[j+1][g] +  T[i][j]*F[j+1][g] + F[i][j]*T[j+1][g];
					F[i][g] += F[i][j]*F[j+1][g];
				}
			}
		}
	}

	return T[0][n-1];
}
int main(){
	char A[4]={'T','T','F','T'};
	char B[3]={'|','&','^'};
	cout<<num_ways(A,B,4);
	int k;
	cin>>k;

	return 0;
}