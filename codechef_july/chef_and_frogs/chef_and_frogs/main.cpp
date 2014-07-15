#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct n{
	int index;
	int point;
	int set;
}node;

int comparePoint(const void* a, const void *b){
	return (*((node *)a)).point > (*((node *)b)).point;
}

int compareIndex(const void* a, const void *b){
	return (*((node *)a)).index > (*((node *)b)).index;
}

int main(){
	int N,K,P;
	cin>>N>>K>>P;
	node A[N];
	for(int i=0;i<N;i++)
	{
		node B;
		B.index = i+1;
		cin>>B.point;
		B.set = -1;
		A[i] = B;
	}
	qsort(A,N,sizeof(node),comparePoint);
	int set = 0;
	A[0].set = 0;
	for(int i=1;i<N;i++){
		if((A[i].point - A[i-1].point)>K)
			set++;
		A[i].set = set;
	}
		
	qsort(A,N,sizeof(node),compareIndex);
	
	int x,y;
	for(int i=0;i<P;i++){
		cin>>x>>y;
		if(A[x-1].set == A[y-1].set)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}