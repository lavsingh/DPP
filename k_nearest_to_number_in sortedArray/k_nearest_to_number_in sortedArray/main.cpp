#include <iostream>
using namespace std;

int binarySearch(int A[], int n, int num){
	int high = n-1;
	int low = 0;
	int mid= (high+low)/2;
	while(high>=low){
		if(A[mid] == num)
			return mid;
		if(A[mid] > num)
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low+high)/2;
	}
	return -1;
}


void findBoundary(int A[], int n, int pos, int k){
	int left = 0, right = 0;
	int t=k;
	if(pos - t/2 < 0){
		left = 0;
		right = t;
	}
	else if(pos+t/2 >= n){
		left = n-1-t;
		right = n-1;
	}
	else{
		left = pos-t/2;
		right = left+t;
	}
	while(t!=0){
		
		int diff = A[right] - A[left];
		int LL = left - t/2>=0?left-t/2:0;
		int RL = LL + k;
		int RR = right + t/2<n-1?right+t/2:n-1;
		int LR = RR - k;
		t/=2;
		if(A[RR] - A[LR] > A[RL] - A[LL]){
			left = LL;
			right = RL;
		}
		else {
			left = LR;
			right = RR;
		}
		
	}
	cout<<left<< " "<<right<<endl;
}
int main() {
	int n;
	cin>>n;
	int A[100];
	for(int i=0;i<n;i++)
		cin>>A[i];
	
	int num,k;
	cin>>num>>k;
	//edge cases
	if(k==0){
		cout<<"no limit given"<<endl;
	}
	if(k>=n){
		cout<<0<<" "<<n-1<<endl;
	}
	int pos = binarySearch(A,n,num);
	
	if(pos == -1){
		cout<<"element not found"<<endl;
		return 0;
	}
	
	findBoundary(A, n, pos, k);
	return 0;
}