#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>

#define MOD 1000000009
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	int n,q,m;
	while(t>0){
		scanf("%d%d",&n,&q);
		vector<int> A;
		int x;
		for(int i=0;i<n;i++){
				scanf("%d",&x);
				A.push_back(x);
		}
		
		while(q>0){
			scanf("%d",&m);
			
			int count[100];
			int arr[100];
				
				
			for(int i=0;i<m;i++){
				count[i]=0;
				arr[i]=0;
			}
			
			for(int i =0; i<n;i++){
				if( A[i]<0){
					int k = (m - abs(A[i]));
					count[k%m]++;
				}
				else
					count[A[i]%(m)]++;
			}
			
			//for(int i=0;i<m;i++){
			//	int base = count[i];
			//	int val = count[i]-1;
			//	
			//	for(int j=2;j<=count[i];j++){
			//		base = (base * val) / j;
			//		arr[(j*i)%m] += base;
			//		val--;
			//	}
			//}

			long long int prod[100],val[100];
			for(int i=0;i<m;i++){
				prod[i]=0;
				val[i]=0;
				count[i]+=arr[i];
			}
			prod[0]=1;
			for(int i=0;i<m;i++){
				for(int j=0;j<m;j++){
					val[j] += prod[(j-i+m)%m]*count[i];
				}
				for(int k=0;k<m;k++){
					prod[k] += val[k];
					val[k] = 0;
				}
			}
			printf("%lld\n",prod[0]%MOD);
			q--;
		}
		t--;
	}
	
	return 0;
}