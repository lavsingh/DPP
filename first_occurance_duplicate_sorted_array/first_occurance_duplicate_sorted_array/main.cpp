#include<iostream>

using namespace std;

int func(int A[], int n, int k){
	int high = n-1, low = 0;
	int mid = low + (high-low)/2;
	while(high>low){
		mid = low + (high-low)/2;
		if(A[mid] == k && mid == 0)
			return mid;
		if(A[mid] == k && A[mid-1] < k)
			return mid;
		if(A[mid] == k && A[mid-1] == k)
			high = mid - 1;
		if(A[mid]>k)
			high = mid - 1;
		if(A[mid]<k)
			low = mid + 1;
	}
	if(A[high] == k)
		return high;
	return -1;
}



int main(){

	int A[6] = {1,1,1,2,2,2};
	cout<<func(A,6,2);
	int k;
	cin>>k;
	return 0;
}