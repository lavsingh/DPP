#include<iostream>
using namespace std;

int rotation_point(int A[],int num){
	//for(int i=0;i<num;i++)
	//	cout<<A[i]<<endl;
	//cout<<num;
	int low = 0, high = num-1;
	int mid = (high+low)/2;

	while(high - low >1){
		if( (A[low] < A[mid]) && (A[high]<A[mid]))
			low = mid+1;
		else
			high = mid;
		mid = (low+high)/2;
	}
	
	return A[low]>A[high]?A[high]:A[low];

}

int main(){
	int a[100]={4,6,7,1,2,3};
	cout<<rotation_point(a,6)<<endl;

	int b[100]={2,3,4,6,7,1};
	cout<<rotation_point(b,6)<<endl;
	int c[100]={1,2,3,4,6,7};
	cout<<rotation_point(c,6)<<endl;
	int d[100]={7,1,2,3,4,6};
	cout<<rotation_point(d,6)<<endl;
	int e[100]={6,7,1,2,3,4};
	cout<<rotation_point(e,6)<<endl;

	int f[100]={3,4,6,7,1,2};
	cout<<rotation_point(f,6)<<endl;
	char num;
	cin>>num;
}