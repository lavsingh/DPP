#include<iostream>
#include<queue>
using namespace std;

typedef struct n {
	int i,j,val;
}element;

struct comparator{
	bool comp(element a,element b){
		if(a.val<b.val)
			return true;
		else
			return false;
	}
};

void mergeKsorted(int A[][4],int k,int n){
	priority_queue <element,vector<element>,comparator> p ;
	for(int i=0;i<k;i++){
		element e;
		e.i= i;
		e.j = 0;
		e.val = A[i][0];
		p.push(e);
	}

	while(!p.empty()){
		element value = p.top();
		cout<<value.val;
		if(value.j<n-1)
		{
			element next;
			next.i = value.i;
			next.j = (value.j)+1;
			next.val = A[next.i][next.j];
		}
		p.pop();
	}
}

int main(){
	

	int k = 3, n =  4;
	int arr[][4] = { {1, 3, 5, 7},
            {2, 4, 6, 8},
            {0, 9, 10, 11}} ;
	mergeKsorted(arr,k,n);

	return 0;
}