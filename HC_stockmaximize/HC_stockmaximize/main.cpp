#include<iostream>
#include<climits>
using namespace std;

long long function(int n, int A[]){
	long long profit = 0;
	int max = INT_MIN;
	for(int i=n-1;i>=0;i--){
		if(A[i]>max)
			max = A[i];
		profit+=(max-A[i]);
	}
	return profit;
}
int main(){
	int k,n;
	int A[50000];
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>n;
		for(int j=0;j<n;j++)
			cin>>A[j];
		cout<<function(n,A)<<endl;
	}
	return 0;
}