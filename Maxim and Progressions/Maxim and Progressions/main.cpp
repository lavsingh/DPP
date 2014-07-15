#include<iostream>
#include<cstring>

#define MOD 1000000007 
using namespace std;
int totalSequence(int n){
	int ans = 1;
	for(int i=0;i<n;i++)
		ans = (ans*2)%MOD;
	return ans-1;
}
int function(int A[],int n){

	int count[101];
	memset(count,0,101*sizeof(int));
	
	int B[101][3];
	memset(B,0,101*3*sizeof(int));
	
	for(int i=0;i<n;i++){
		int num = A[i];
		count[num]++;
		B[num][1] = 2*B[num][1]+1;
		for(int j=1;j<100;j++){
			if(num-j > 0){
				B[num][0] += B[num-j][0];
				B[num][0] += count[num-j];
			}
			if(num+j <= 100){
				B[num][2] += B[num+j][2];
				B[num][2] += count[num+j];
			}
			B[num][0] = B[num][0]%MOD;
			B[num][1] = B[num][1]%MOD;
			B[num][2] = B[num][2]%MOD;
		}
	}
	int ans = 0;
	for(int i=0;i<100;i++)
		ans = (ans + B[i][0]+ B[i][1] + B[i][2])%MOD;
	return (totalSequence(n) - ans)%MOD;

}

int main(){
	int T;
	cin>>T;

	int n;
	while(T>0){
		cin>>n;
		int A[n];
		for(int i=0;i<n;i++)
			cin>>A[i];
		cout<<function(A,n)<<endl;
		T--;
	}

	return 0;
}