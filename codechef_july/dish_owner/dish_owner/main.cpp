#include<iostream>

using namespace std;

int main(){

	int T;
	cin>>T;
	while(T>0){
		int N;
		cin>>N;
		int A[100],P[100];
		
		for(int i=1;i<=N;i++){
			cin>>A[i];
			P[i] = -1;
		}

		int Q;
		cin>>Q;
		while(Q>0){
			int type, x, y, r;
			cin>>type;
			if(type == 0){
				cin>>x>>y;
				if(A[x] > A[y])
					P[y] = x;
				if(A[x] < A[y])
					P[x] = y;
			}
			if(type == 1){
				cin>>r;
				while(P[r]!=-1){
					r = P[r];
				}
				cout<<r<<endl;
			}
			Q--;
		}
		T--;
	}
	return 0;
}